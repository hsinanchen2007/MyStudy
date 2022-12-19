# 1. 思路：

**先序遍历是指：先访问根，再访问左、右子树的遍历方式**，如下图：

![330px-Sorted_binary_tree_preorder.svg.png](https://pic.leetcode-cn.com/ec1210888fc0217a175894bdee32c0d59af950f4dee426deeff1d72577b2d712-330px-Sorted_binary_tree_preorder.svg.png)

其遍历顺序为F, B, A, D, C, E, G, I, H。图片来自[维基百科](https://zh.wikipedia.org/wiki/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86)



可以想到先序遍历的递归和迭代写法，在这里我们主要考虑迭代写法。

# 1.1 先序遍历的迭代写法：

首先简单复习一下先序遍历的迭代写法：

其中，res保存节点值的输出结果

```
def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []

        stack = []

        while root:
            stack.append(root)
            res.append(root.val)
            root = root.left

        while stack:
            node = stack.pop()
            node = node.right
            while node:
                stack.append(node)
                res.append(node.val)
                node = node.left
                
        return res
```

可见，先序遍历迭代写法的核心在于**将所有左节点按顺序压入栈中，栈弹出的节点如果有右节点，则继续将其所有左节点压入栈中。**

给我们的启示在于：**优先考虑左节点，在左节点不可实现时，再考虑右节点**

# 1.2 题目分析：

题目中提到，短划线的个数相当于节点的深度。在这里，**我们用栈保存已经遍历过的节点**。

如果**当前节点cur的深度恰好比栈顶节点top大1，说明该节点是上一节点的子节点。**

即 cur = top.child

所以现在的问题就转换为两个子问题：

**1. 如何确定栈顶节点的深度**

**2. 如何确定子节点的位置（左/右）**

# 1.3 如何确定栈顶节点的深度：

一个直观的想法是利用字典保存栈顶节点深度，但是这样会消耗大量空间。

这里我们给出的方法是：**用栈的长度代表栈顶节点的深度**：

正如前面所提到的，我们需要保证**当前节点cur的深度恰好比栈顶节点top大1**，那么，当栈顶节点top深度 > 当前节点cur深度-1时，该如何处理？

由于我们是不断把元素压入栈中，由于栈**后进先出**的特点，**栈顶下面的元素，其深度必然比栈顶元素要小**，所以我们只需不断弹出栈顶元素，直到栈顶节点满足要求。

以 **1-2--3--4-5--6--7** 为例，其过程如下：

![excel.png](https://pic.leetcode-cn.com/7bfd5303912d70dbf0b538140e7c008ec38ed2b6f483664e48476e24b72bb35d-excel.png)


从这个过程中我们也不难看出，**左节点都是直接入栈的，而右节点入栈前需要弹出一定的栈顶节点**，这也是我们判断左右节点的重要依据。

# 1.4 判断子节点位置：

如上文所述，判断节点位置的重要依据是：**入栈前是否需要弹出栈顶节点**

而弹出栈顶节点的依据为：**当前节点cur的深度是否恰好比栈顶节点top大1**

如果是，则**不需要弹出，即当前节点为栈顶节点的左节点**

反之，**需要弹出，弹出过程结束后，当前节点为栈顶节点的右节点**


# 2. 具体代码


```
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        count, num = 0, 0                            # 初始化-的个数count和数字num
        stack = []                                   # 对栈进行初始化
        S += '-'                                     # 为处理最后一个数字，在S后添加'-'

        for c in S:
            if c == '-':                             # c为'-'时
                if num:                              # 如果num不为0
                    node = TreeNode(num)             # 建立新的节点
                    if count==len(stack):            # 如果count和stack长度相同
                        if stack:                    # 说明该节点是栈顶节点的左节点
                            stack[-1].left = node
                    else:                            # 如果count和stack长度不同 
                        while count<len(stack):      # 说明该节点是栈中某节点的右节点
                            stack.pop()              # 弹出栈顶节点，直到栈的长度=count
                        stack[-1].right = node       # 此时节点是栈顶的右节点

                    stack.append(node)               # 将节点加入栈顶
                    count, num = 0, 0                # 并对count和num进行初始化
                
                count += 1                           # 不论num是否为0，count都递增
                                                     # 作为对'-'的计数
            else:
                num = num*10 + int(c)                # 否则对数字进行处理
        
        return stack[0]                              # 最后返回栈底元素，即根节点
```


![1028.png](https://pic.leetcode-cn.com/2327f88d18be81cd91107aedfb14a0e376d46d942155cca51f4a1287b4175efb-1028.png)
