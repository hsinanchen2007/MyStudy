看题解大部分都是中序遍历，没有题目提示的解法，就写一下。
思路:递归的解决问题,假设每次处理可以得到链表的head和tail
处理节点root的步骤:
0.初始化head,tail = root,root(任意节点初始可看成以自己为头和尾的单节点链)
1.若左儿子非空,处理root.left得到左子树形成的链表[left_head,left_tail]
2.若右儿子非空,处理root.right得到右子树形成的链表[right_head,right_tail]
3.root.left = None (题目要求)
4.将两段链表串起来得:[left_head,left_tail.right = root,root.right = right_head,right_tail]
5.返回head,tail
```python []
class Solution:
    def convertBiNode(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        head,tail = self.travel(root)
        return head

    def travel(self,root):
        head,tail = root,root
        if root.left:
            left_head,left_tail = self.travel(root.left)
            head = left_head
            left_tail.right = root
        if root.right:
            right_head,right_tail = self.travel(root.right)
            tail = right_tail
            root.right = right_head
        root.left = None
        return head,tail
```


