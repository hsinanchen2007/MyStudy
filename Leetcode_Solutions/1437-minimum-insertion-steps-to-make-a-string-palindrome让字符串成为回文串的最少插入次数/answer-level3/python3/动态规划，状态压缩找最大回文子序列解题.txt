### 解题思路
利用动态规划，状态压缩，找到字符串s的最大回文子序列的长度length，然后len(s)-length就是需要修改的字符数，再该题中为需要插入的字符数
![image.png](https://pic.leetcode-cn.com/026c871fb262e80cbc058b816b45fde4426a1f30f2b067861dd8b400a9cfc53d-image.png)

### 代码
```python
class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        ls=len(s)           
        dp=[0]*ls    
        for i in range(ls):
            temp1=0
            temp2=0
            #temp是用于保存上次的dp[j+1]的值，即dp[i-1][j+1]
            dp[i]=1
            for j in range(i-1,-1,-1):
                temp1=dp[j]
                if(s[i]==s[j]):
                    dp[j]=temp2+2
                else:     
                    dp[j]=max(dp[j],dp[j+1])    
                temp2=temp1  
        return ls-dp[0]

```