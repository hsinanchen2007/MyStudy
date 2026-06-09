### 解题思路-动态规划
核心思路：构造一个列表dp，其中dp[i]表示字符串s[:i+1]是否可以拆分；

关键：如何由dp[0]~dp[i-1]推导出dp[i]？

假设现在在推导dp[i]，那么如果dp[i]为1，则字典中必然存在一个单词word以s[i]结尾，并且dp[i-len(word)]=1；以些为条件来进行推导；

这里为了方便查找以什么字符结尾的单词，代码中将单词列表转换成字典结构，key为结尾字符，val为相应的单词列表；

### 代码

```python3
class Solution:
    """
    动态规划：假设dp[i]表示字符串s[:i+1]能否拆分；基于dp[0]~dp[i]从而判断dp[i+1]的拆分情况；
    """
    def wordBreak(self, s: str, words) -> bool:
        if s.strip == '' or words == []:
            return False
        
        # 1. dp[i]表示s[:i+1]可以拆分
        dp = [0] * len(s)
        # 2. wordDict中的key:List[str]表示以字符key结尾的word列表
        wordDict = dict()
        for word in words:
            try:
                wordDict[word[-1]].append(word)
            except:
                wordDict[word[-1]] = [word]
        
        # 3. 通过dp[0]~dp[i-1]推导出dp[i]，其中dp[0]已知
        for i in range(len(s)):
            try:
                # 推导dp[i]时，首先遍历以s[i]结尾的单词word
                for word in wordDict[s[i]]:
                    tmp_len = len(word)
                    # 假设word在s[:i+1]的尾部，那么判断dp[i-len(word)]是否为1或是word==s[:i+1]
                    if ( (i-tmp_len >= 0 and dp[i-tmp_len] == 1) or (i-tmp_len == -1) ) and s[i-tmp_len+1:i+1] == word:
                        dp[i] = 1
                        break
            except:
                pass
        
        return dp[-1]
```