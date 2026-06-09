### 解题思路
根据题目逻辑

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        # 建立动规数组，分别保存1到n的结果
        dp = ['1' for i in range(n+1)]
        for i in range(2, n+1):
            s = dp[i-1]
            res = ''
            count = 1
            # 遍历上一层的结果字符
            for j in range(len(s)):
                # 如果当前字符等于下一字符，则该字符的count++
                if j+1 < len(s) and s[j] == s[j+1]:
                    count += 1
                    continue
                # 否则，将该字符的“数量+字符”加到结果中，并将count重新置1，以计算下一个字符的数量
                else:
                    res += (str(count)+s[j])
                    count = 1
            # 保存结果到动规数组中
            dp[i] = res
        return dp[n]



```