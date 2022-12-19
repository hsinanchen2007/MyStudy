### 解题思路
序列化，例如 python 的 pickle 模块 
我之前也在纠结这个问题，在做题 [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)时， 看不懂二叉树的测试用例是如何序列化的，所有位置的 null 是否都需要打出来。官方给了分析 [请问 [1, null, 2, 3] 在二叉树测试用例中代表什么](https://support.leetcode-cn.com/hc/kb/article/1194353/)

对于一般二叉树，不带null 的层次遍历，或者不带 null 的先序（中序或者后序）遍历是无法唯一确定一棵树的结构。

#### 1.带 null 的层次遍历
1. 序列化有多种不同的形式，这里考虑层次遍历。例如，对于题解实例去掉节点 2 ，层次序列化可以为
+ [1,null,3,4,5] （我的代码，效果和现在 leetcode 所使用的的相同）
+ [1,null,3,4,5, null, null, null, null] （[高赞解答](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/liang-chong-jie-fa-by-jason-2-13/)的效果 ，最外层的叶子节点必须使用 null 填充）
+ [1,null,3,null,null,4,5] or [1,null,3,null,null,4,5,null,null,null,null,null,null,null,null] （堆结构的效果）
为了实现我的代码的效果，需要对 null 累加进入 data 进行延后处理。这样 1 的左子节点 null 会累加进去，但是 4,5 的子节点的null 不会累加进去。


2. 反序列化，对应于上面不同的结构有不同的写法
+ 在堆结构下， 通过将所有节点（包括使用 null 填充的节点）存放在 list 中，可以使用下标很方便地找到父节点。但对于很深层的稀疏树，可能要耗费大量的额外存储空间，并且反序列化耗时很久。
+ 之前考虑过在反序列化时，先将我的代码的序列化结果转换为 堆结构的效果，但发现还是超时了。
+  对于我的代码，和高赞的代码，找到父节点稍微有一点麻烦，这里需要构造一个 queue 队列，代表目前还没有子节点，马上要成为父节点的点，然后 father = queue.pop(0), 一次枚举两个 data 中的元素，分别作为其左孩子和右孩子。
+ 另外对我的代码，因为 4,5 的 null 子节点在 data 中略去了，为了避免 4,5 的 left 和 right 都变成了野指针，需要在生成 4,5 节点时，就把其 left 和 right 都初始化为 None. 同时我的代码需要判断 i 是否在循环内部增加的过程中超过了 len(data)-1, 因为可能有 例如，例子中 5 变成了 null, 而 null 没有累加进入 data，导致下标超界。
+ 看讨论区第一高赞的代码突然想到，用上面第二种方法，在反序列化的时候，不用判断 i 是否会超过 len(data)-1。只需要用 queue 非空来控制就可以。

#### 2. 带 null 的先序遍历


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # 层次遍历时不写任何 null 的，但无法唯一确定一棵树
        # 序列化需要写一些 null, 以保证能唯一确定一棵树
        if root == None: # 需要特殊处理，因为下面进行了延后处理
            return "[null]"
        
        queue = [root]
        res = "["
        tmp = ""
        while queue:
            for _ in range(len(queue)):
                x = queue.pop(0)
                if x == None:
                    tmp += "null" + "," #这里的 null 延后再加，
                                        #例如 4,5 对应的子节点 null 不用加。但 2 的 null 要加
                else:
                    res += tmp
                    tmp = ""
                    res = res + str(x.val) + ","
                    queue.append(x.left) # 若仅仅层次遍历，这里是先判断非 None, 才进队列
                    queue.append(x.right)
        return res[:-1]+"]"


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data[1:-1].split(",")
        # 先来层次还原成 堆结构, 超时!!!
        # layer = [data[0]]
        # all_layer = [layer]
        # i = 1
        # while i < len(data):
        #     new_layer = []
        #     for x in all_layer[-1]: # 上一层
        #         if x == "null":  # 补两个 null
        #             new_layer.append("null")
        #             new_layer.append("null")
        #         else:
        #             # new_layer.append(data[i])  # [3,2,4,1]枚举到 1出现错误，i 超标
        #             # i += 1
        #             # if i < len(data):  # 这里判断不可丢
        #             #     new_layer.append(data[i])
        #             #     i += 1
        #             new_layer.append(data[i])
        #             i += 1
        #             if i>= len(data):
        #                 break
        #             new_layer.append(data[i])
        #             i += 1
        #             if i >= len(data):
        #                 break
        #     all_layer.append(new_layer)
        # flat_all_layer = [x for layer in all_layer for x in layer]
        
        if data[0] == "null":
            return None
        root = TreeNode(int(data[0]))
        root.left = None
        root.right = None
        queue = [root]
        i = 1
        while queue: # 层次遍历 or 层次生成都离不开 queue
            for _ in range(len(queue)):
                father = queue.pop(0)
                ## 参看题解，同时出两个点，分别作为 left 和 right
                for j in range(2):
                    if i>= len(data): break
                    x = data[i]
                    if x != "null":
                        node = TreeNode(int(x))
                        node.left = None  # 先初始化，避免实例中 5 的 left 和right 成了野指针 的情形
                        node.right = None
                        queue.append(node)
                        if j == 0:
                            father.left = node
                        else:
                            father.right = node
                        # if i%2 ==0:
                        #     all_node[i//2].left = node  # 非堆结构这样父节点的计算方式对啊。
                        # else:
                        #     all_node[i//2].right = node

                    i += 1
                    if i>= len(data): 
                        break
    
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```