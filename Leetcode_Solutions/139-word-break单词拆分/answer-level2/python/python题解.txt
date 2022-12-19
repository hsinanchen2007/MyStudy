### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dic = {}
        for i in wordDict:
            dic[i] = 0
        length = len(s)
        dp = [False]*(length+1)
        dp[0] = True
        for i in range(1,length+1):
            for j in range(i):
                if dp[j] and s[j:i] in dic:
                    dp[i] = True
                    break 
        
        return dp[-1]


        # def isBreak(s, i, dic):
        #     if not s:
        #         return True
        #     if index[i] != -1:
        #         return index[i]
        #     for j in range(len(s)+1):
        #         if s[:j] in dic:
        #             if isBreak(s[j:], j, dic):
        #                 index[j] = True
        #                 return True
        #             index[j] = False
        #     return False
        # return isBreak(s, 0, dic)
        

        


        
            
            
            
```