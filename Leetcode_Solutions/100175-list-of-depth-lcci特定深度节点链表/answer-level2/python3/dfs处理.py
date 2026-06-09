### 解题思路
用深度优先right优先,每次进入深一层的情况,将最右边的node作为
链表的node加入结果列表中(ans)

然后由于dfs回溯得到上面的层时,将该节点作为链表的头一个节点也是
链表的节点,且该节点指向之前的节点head.next = ans[level]
更新在ans中的链表节点

主要要right先,反之就是就反了
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def listOfDepth(self, tree: TreeNode) -> List[ListNode]:
        ans = []
        def dfs(node,level):
            if not node:
                return
            if len(ans)==level:
                ans.append(ListNode(node.val))
            else:
                head = ListNode(node.val)
                head.next = ans[level]
                ans[level] = head
            dfs(node.right,level+1)
            dfs(node.left,level+1)
        dfs(tree,0)
        return ans
```