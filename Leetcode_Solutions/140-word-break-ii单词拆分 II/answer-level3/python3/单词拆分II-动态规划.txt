### 解题思路-动态规划
本题同139题类似；这里dp不再只是保存(0,1)，而是用来保存拆分的单词；
1. 同139题，构造`dp=[[] for _ in range(len(s))]`，对于字符串s[:i+1]，若其可拆分，则用`dp[i]`来保存所有拆分情况结果可能的最后一个单词；如`s=catsand,words=['cat','cats, 'and', 'sand']`，由于可拆分为`['cat sand', 'cats and']`，因此`dp[6]=['sand', 'and']`；
2. 根据`dp`的结果重组可拆分的句子；由最后一个单词往前递归；


### 代码

```python3
class Solution:
    """
    第139是判断字符串s是否可以拆分；本题用来计算若可以拆分，那么有多少种拆分情况；
    动态规划：同139题，构造dp，当s[:i+1]可以拆分时，dp[i]保存可拆分的所有情况下的最后一个单词；最后根据dp反向重组所有拆分情况；
    """
    def combineWord(self, dp, tmp, res):
        """
        根据dp组句
        """
        if dp == []:
            res.append(tmp.strip())
            return
        elif dp[-1] == []:
            return
        
        for word in dp[-1]:
            self.combineWord(dp[:-len(word)], word+' '+tmp, res)

        return 

    def wordBreak(self, s: str, words):
        if s.strip() == '' or words == []:
            return []

        
        wordDict = dict()
        dp = [ [] for _ in range(len(s)) ]
        for word in words:
            try:
                wordDict[word[-1]].append(word)
            except:
                wordDict[word[-1]] = [word]
        
        # dp[i]不为空时表示：s[:i+1]可拆分，并且所有可能拆分结果的最后一个单词保存在dp[i]列表中；
        for i in range(len(s)):
            try:
                for word in wordDict[s[i]]:
                    tmp_len = len(word)
                    if s[:i+1] == word  or (i-tmp_len>=0 and dp[i-tmp_len] and s[i-tmp_len+1:i+1]==word):
                        dp[i].append(word)
            except:
                pass
        
        tmp, res = '', []
        self.combineWord(dp, tmp, res)
        return res
```