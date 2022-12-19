方案一:
任意方式遍历二叉树
维护一个K规模的最小堆
堆规模不足K时，遇到新元素直接入堆，
堆规模达到K时，新元素如果大于堆顶，则用新元素替换堆顶，然后更新堆
堆规模达到K时，新元素小于堆顶，直接pass，啥也不干

方案二：
中序遍历，并维护一个K规模的列表，每当添加一个新元素就删除最后一个元素，遍历完成后的列表第一个元素即为所求

方案三：
逆中序遍历（即右→中→左），直接遍历到第k个数返回

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        stack=[]
        while (stack or root):
            if root:                   #不空就入栈，然后向右搜索
                stack.append(root)
                root=root.right
            else:
                root=stack.pop()       #root为空，就弹出栈顶，实际上第一个弹出的是二叉树最                                        #大的数，第二个弹出的就是第二大的数。。。
                k=k-1
                if k==0:
                    return root.val
                root=root.left
```
