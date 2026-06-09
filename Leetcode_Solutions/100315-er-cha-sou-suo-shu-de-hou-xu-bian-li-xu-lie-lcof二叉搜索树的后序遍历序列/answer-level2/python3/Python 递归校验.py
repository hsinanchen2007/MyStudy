### 解题思路

找到列表中第一个比最后一位值大的位置，

检验是否：该位置之前的最大值比最后一位小，该位置之后的最小值比最后一位大

如果校验通过，表示可以一棵不完整的搜索树

然后递归校验左子树和右子树

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if len(postorder) <= 2:
            return True
        val = postorder[-1]
        idx = 0
        for n in postorder[:-1]:
            if n > val:
                break
            idx += 1
        return (idx == 0 or val > max(postorder[:idx])) and \
            (idx == len(postorder) - 1 or val < min(postorder[idx:-1])) and \
            self.verifyPostorder(postorder[:idx]) and \
            self.verifyPostorder(postorder[idx:-1])
```