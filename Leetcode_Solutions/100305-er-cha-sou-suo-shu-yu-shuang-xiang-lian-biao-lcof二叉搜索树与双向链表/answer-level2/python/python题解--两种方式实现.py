### 使用全局变量
![image.png](https://pic.leetcode-cn.com/7538ba2a7077c499b0c5774ae450be8f5a955671fd67ed292855bd44fbece856-image.png)
- 首先说明在Python2.中`list`默认是全局变量,Python3中另有说明,这次我们使用`list`实现
- 给我们是一颗二叉搜索树,我们知道它的属性是左子树的节点值比根节点小,右子树节点值之比根节点大,于是乎很容易想到使用中序遍历得到一个有序的也是题目中要求的排序方式
- 当我们遍历将链表转换成一个有序链表时,原先指向左子节点的指针调整为为有序链表中的最后一个节点,链表中最后一个节点的右指针指向当前节点
- 如此遍历下去即可,具体看代码
### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None
        head = [Node(0)]# 使用list创建全局的变量,用来保存有序链表的最后一个节点
        temp = head[0]# 保存初始化节点,也就是链表的第一个节点
        def creat_list(root):
            if root.left:# 循环遍历左子树
                creat_list(root.left)
            root.left = head[0]#当前节点的做指针指向最后一个节点
            head[0].right = root# 最后一个节点的指针指向当前节点
            head[0] = root# 更新最后一个节点
            if root.right:# 排序右子树
                creat_list(root.right)

        creat_list(root)
        temp = temp.right# 因为初始化了一个多余节点,所以不要这个节点
        temp.left = head[0]#此时head[0]代表是有序链表的最后一个节点,temp代表有序链表的第一个节点,将第一个和最后一个连接
        head[0].right = temp
        return temp

```
### 使用传参数的方式实现

- 思想和上面如出一辙,只是换做了另外一种实现,本质就是使用全局变量和传递参数的不同
![image.png](https://pic.leetcode-cn.com/3e107cb86e8b3b9ea65776f48a588c23fef0397004ac588a251ab887ead9cc0f-image.png)

```
class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if root is None:
            return None
        def change_ptr(root, node):
            if not root:
                return node
            node = change_ptr(root.left, node)
            root.left = node
            node.right = root
            node = root
            node = change_ptr(root.right, node)
            return node
        v_head = Node(0)
        tail = change_ptr(root, v_head)
        head = v_head.right
        head.left = tail
        tail.right = head
        return head
```
