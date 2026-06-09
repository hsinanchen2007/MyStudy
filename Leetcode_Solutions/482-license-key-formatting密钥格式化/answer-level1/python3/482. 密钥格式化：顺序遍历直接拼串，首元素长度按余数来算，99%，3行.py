![image.png](https://pic.leetcode-cn.com/2e7fae552c01b62497bf443282f37f9b1c38472214b16964284d454cd456dcb7-image.png)

直接拼起来就是了。

```python []
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace('-', '').upper()
        ans = [S[: len(S) % K]] + [S[i - K: i] for i in range(len(S) % K + K, len(S) + 1, K)]
        return '-'.join(ans) if ans[0] else '-'.join(ans[1: ])
```


