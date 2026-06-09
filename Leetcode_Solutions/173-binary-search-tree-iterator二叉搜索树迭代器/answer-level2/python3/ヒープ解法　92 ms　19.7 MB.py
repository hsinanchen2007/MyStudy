### 解题思路
・initでバイナリツリーをループしヒープに格納する　⇒　最小ヒープが出来上がり
・nextする時、heappopをする
・hasnextする時、ヒープの0番目要素があるかをチェック

注意点：
そもそもrootがNoneの場合と、ヒープが空の場合の処理を忘れずに

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import heapq
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.heap = []
        stack = []
        if root:
            stack = [root]
        while len(stack)>0:
            node = stack.pop()
            heapq.heappush(self.heap, node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        if len(self.heap) > 0:
            return heapq.heappop(self.heap)
        else:
            return None

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if len(self.heap) > 0:
            return True
        else:
            return False
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```