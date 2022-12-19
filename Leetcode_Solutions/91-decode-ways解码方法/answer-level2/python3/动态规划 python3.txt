### 解题思路
顺序遍历，计算字符串从开始位到当前位的解码方式总数，按照与字符串索引对应的位置存入dp数组
1. 如果第一个元素等于'0'，直接返回0
2. 如果元素长度等于1，直接返回1
3. 定义dp数组为[1]，然后从字符串s的第二个字母开始遍历
    1. 如果第i个元素是‘0’，检查第i-1个元素是不是‘1’或‘2’，如果不是，返回0；如果是，判断一下i是否等于1，来决定dp.append(dp[i-2])或者是dp.append(1)   (防止数组越界)
    2. 如果第i-1个元素是‘1’，或者第i-1个元素是‘2’且第i个原始大于‘0’且小于‘7’：dp.append(dp[i-2]+dp[i-1])
    3. 其余情况dp.append(dp[i-1])
4. 返回s最后一个元素对应的dp值

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        if len(s) == 1:
            return 1
        dp = [1]
        for i in range(1, len(s)):
            if s[i] == '0':
                if s[i-1] != '1' and s[i-1] != '2':
                    return 0
                else:
                    if i == 1:
                        dp.append(1)
                    else:
                        dp.append(dp[i-2])
                    continue
            if s[i-1] == '1':
                dp.append(dp[i-2]+dp[i-1])
            elif s[i-1] == '2' and (s[i] >= '1' and s[i] <= '6'):
                dp.append(dp[i-1]+dp[i-2])
            else:
                dp.append(dp[i-1])

        return dp[-1]
```