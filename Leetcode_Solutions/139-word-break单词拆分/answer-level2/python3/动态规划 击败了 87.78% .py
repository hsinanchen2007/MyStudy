### 解题思路
    动态规划题目通常都是dp[i]与dp[i-1]、dp[i-2]之间的关系，但是此题又稍微扩充了一点
    dp[i]与dp[i-len(word)-1]之间的关系，相对来说也比较纯粹
    
    dp[i]表示到第i个字符位置，是否可以用wordDict中的单词拼凑出来
    0代表无法拼凑出来，1代表可以拼凑出来
    
    如果dp[i-len(word)]为1，也就是说当前抠出来的这个单词在wordDict中，
    而且之前字符串是有效的，那么dp[i]也就是有效的
    
    公式如下：
    dp[i] =  1   if  截取出来的单词在wordDict中 and dp[i-len(截取出来的单词)] == 1
          =  0   else

### 代码

```python3
import sys
class Solution:
    def wordBreak(self, s, wordDict):
        if not s or len(s) == 0:
            return False

        len_word = {}
        min_len, max_len = sys.maxsize, 0
        for word in wordDict:
            if len(word) not in len_word.keys():
                len_word[len(word)] = {word}
            else:
                len_word[len(word)].add(word)
            min_len = min(min_len, len(word))
            max_len = max(max_len, len(word))
        # print(len_word)
        print(min_len, max_len)

        dp = [0 for i in range(len(s) + 1)]
        dp[0] = 1
        for i in range(len(s)):
            j = i
            while j >= 0:
                clipped_len = i - j + 1
                if clipped_len < min_len or clipped_len > max_len:
                    j -= 1
                    continue

                # 截取出来的长度
                tmp = s[j:i+1]
                if len(tmp) in len_word.keys():
                    if tmp in len_word[len(tmp)] and dp[j] == 1:
                        dp[i+1] = 1
                        break
                j -= 1
        # print(dp)
        return dp[len(s)]
```