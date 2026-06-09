### 解题思路
官方序列化和反序列化即为层次遍历，层次遍历常用方法是用栈，所以在序列化和反序列化中都使用了栈作为基础数据结构，具体实现方法和用栈做树的层次遍历基本一致，具体细节可以看下面代码。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        利用栈做层次遍历。
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return []
        data = []
        queue = [root]
        while len(queue):
            node = queue[0]
            if node is None:
                data.append('null')
            else:
                data.append(node.val)
                queue += [node.left, node.right]
            del queue[0]
        p = len(data) - 1
        while data[p] == 'null':
            del data[-1]
            p -= 1
        print('serialize success')
        return data

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        看做完全二叉树并根据完全二叉树的下标的性质进行还原。
        :type data: str
        :rtype: TreeNode
        """
        length = len(data)
        if length == 0:
            return None
        queue = []
        root = TreeNode(data[0])
        queue.append(root)
        i = 1
        flag = 0 # flag用来记录i指向的节点是左孩子还是右孩子
        while len(queue) and i < length:
            node = queue[0]
            new_node = TreeNode(data[i]) if data[i] != 'null' else None
            if flag == 0: # 添加左孩子
                node.left = new_node
                flag = 1
            else:
                node.right = new_node
                flag = 0
                del queue[0]
            if new_node:
                queue.append(new_node)
            i += 1
        print('deserialize success')
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```