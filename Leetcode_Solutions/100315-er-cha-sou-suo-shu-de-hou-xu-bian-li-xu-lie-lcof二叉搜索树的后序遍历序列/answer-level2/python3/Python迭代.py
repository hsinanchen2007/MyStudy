### 解题思路
从后向前依次作为根节点遍历，从前向后第一个大于根节点的位置是左右子树的分界点。

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        n = len(postorder)
        if n <= 1:
            return True
        start = n-1
        while start > 0:
            num = 0
            for i in range(start):
                if postorder[i] < postorder[start]:
                    num += 1
                else:
                    break
            for j in range(i,start):
                if postorder[j] > postorder[start]:
                    num += 1
                else:
                    break
            if num < start:
                return False
            start -= 1
        return True
```