### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        from itertools import takewhile
        if not postorder:
            return True
        p = postorder[-1]
        left_sub = list(takewhile(lambda x:x<p, postorder[:-1]))
        right_sub = postorder[len(left_sub):-1]
        if not all(x > p for x in right_sub):
            return False
        left = True
        right = True
        if left_sub:
            left = self.verifyPostorder(left_sub)
        if right_sub:
            right = self.verifyPostorder(right_sub)
        return left and right

```