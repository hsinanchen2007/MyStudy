### 解题思路
此处撰写解题思路
# 和300题最长上升序列一样的思路
### 代码

```python3
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        if not pairs:
            return 0
        pairs=sorted(pairs,key=lambda x:x[0])
        n=len(pairs)
        dp=[1]*n
        # dp[i]:代表当前第i个数对，[0:i]包含关系的最长的数对链
        # 和最长上升序列一样的思路
        for i in range(1,n):
            for j in range(i):
                if pairs[i][0]>pairs[j][1]:
                    # 更新当前的最大值 比如[-7,1][0,10][2,3][4,5]
                    # [4,5]是3不是2 因为比较[2,3]的时候 更新了
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)

        

               
                   
```