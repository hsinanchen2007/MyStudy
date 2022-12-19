### 解题思路
先计算出第一部分的长度，为`S`去除`-`后的长度模`K`，因为必须长度大于等于1，所以刚好整除时，第一部分长度就为`K`。

然后就按照字符串拼接，设置步长`step=K`即可。

### 代码

```python3
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        first_group_len = (len(S) - S.count('-')) % K
        first_group_len += K if first_group_len == 0 else 0
        S = S.replace('-', '').upper()
        res = ''
        for i in range(first_group_len, len(S), K):
            res += ('-' + S[i: i + K])
        res = S[: first_group_len] + res
        return res
```