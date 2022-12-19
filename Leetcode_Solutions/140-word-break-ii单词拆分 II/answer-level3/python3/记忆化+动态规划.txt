贡献一下一个弱鸡解法
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        Hash = {}
        for word in wordDict:
            if word not in Hash:
                Hash[word] = 1
        print(Hash)
        memo = {}
        ### 记忆化，用memo[i]记录s[:i+1]能由单词表中的单词构成句子，并且每一个前塑位置
        memo[0] = -1
        dp = [0]*(len(s) + 1)
        dp[0] = 1
        for i in range(1, len(dp)):
            for j in range(i):
                if (dp[j] == 1) and (s[j:i] in Hash):
                    if i not in memo:
                        memo[i] = [j] 
                    else:
                        memo[i].append(j)
                    dp[i] = 1
        if not dp[-1]: return []
        self.res = []
        ### 根据memo上记录的信息，倒序查找
        self.backtrack([], memo, len(s), s)
        return self.res
        
    def backtrack(self, cur_words, memo, index, s):
        if memo[index] == -1:
            self.res.append(' '.join([word for word in cur_words[::-1]]))
            return
        for num in memo[index]:
            cur_words.append(s[num:index])
            self.backtrack(cur_words, memo, num, s)
            cur_words.pop()
```
