### 解题思路
首先判定是否为空，空字符串返回空字符串，
然后遍历，出现一个前后不同的字符就统计出来放进re里面，
最后比较一下与原字符串的长短即可。

### 代码

```python3
class Solution:

    def compressString(self, S):
        n = len(S)
        if n == 0:
            return ''
        num = 1
        re = ''
        for item in range(0, n - 1):

            if S[item + 1] == S[item]:
                num += 1
            else:
                re += (S[item] + str(num))
                num = 1
        re += (S[n - 1] + str(num))
        if len(re) < n:
            return re
        else:
            return S

```