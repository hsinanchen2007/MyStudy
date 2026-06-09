### 解题思路
对于二叉搜索树中序遍历可以获得升序序列，所以我们的代码肯定是要以中序遍历为基础的，关键是我们如果想要生成双向链表肯定需要知道上一个节点是什么，因为树结构是单向的，所以我们需要将上一个节点保存下来，下面的实现是将上一个节点作为形参传入递归函数中的，当然也可以定义一个局部变量完成。具体讲一下递归函数：
（1）确定函数输入及输出：输入肯定是需要节点root的，通过刚才分析我们还需要上一个节点才能完成双向链表的链接，所以还需要传入上一个节点node；那么输出就很好理解了，我们并不知道上一个节点是什么，只能在递归过程中获得，那么我们的返回值就可以是当前已生成的双向链表的最后一个节点。
（2）出口：这里是很容易犯错的，如果`root == None`我们到底应该返回什么，我们遇到的其他问题好像都是返回None，但是这里应该是传入的节点node，因为如果当前节点不为None，它的返回值应该是当前子树的最大值（也就是一直向右的最后一个节点），但是该子树为空，那么我们应该返回给上层的就应该是本来准备给当前子树的node节点，举个例子，我们对任意左子树或者右子树进行遍历时，我们一定是已经完成了之前的双向链表list_1并且也已知list_1的最后一个节点node，我们希望对子树继续对链表进行扩充，**但是此时子树为空，那么可以认为已经用当前空节点完成了链表的扩充，只不过扩充了0个节点，即此时已完成链表的最后一个节点仍然是node**。
（3）递归内容：已知当前已完成的链表的最后一个节点，根据上述的输入输出以及中序遍历的框架，我们很容易写出下面代码，也就是将当前子树的根节点、根节点的上一个节点（左子树一直向左）进行相连，并返回右子树的最后一个节点作为当前子树的最大节点也是已排好的链表的最后一个节点。

对于递归函数的调用，传入一个虚拟节点即可，那么真正的头结点就是虚拟节点的下一个节点，而递归函数的返回值正好为尾节点。

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
        if root is None:
            return None
        def change_ptr(root, node):
            if root is None:
                return node
            node = change_ptr(root.left, node)
            node.right = root
            root.left = node
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