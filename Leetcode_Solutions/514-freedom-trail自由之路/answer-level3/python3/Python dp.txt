### 解题思路
动态规划，二维。dp[i][j]表示已经完成了i个字符并且此时ring[j]指向12点，ring[j]一定等于最后完成的字符。dp[i][j]=min(dp[i-1][j],j的取值满足：令ring[j]等于第i-1个被完成的字符)，其余都是不可能的状态。

### 代码

```python3
class Solution:    
    def findRotateSteps(self, ring: str, key: str) -> int:
        '''
        搞个列表存每个字母在的位置
        a-z对应列表下标0-25
        '''
        arr=[[] for i in range(26)]
        for i in range(len(ring)):
            arr[ord(ring[i])-ord('a')].append(i)
        
        #初始化
        dp=[[0 for j in range(len(ring))] for i in range(len(key))]

        #完成第一个字符，初始位置在ring[0],单独处理下
        for j in arr[ord(key[0])-ord('a')]:
            dp[0][j]=min(j,len(ring)-j) #顺时针或逆时针

        for i in range(1,len(key)): 
            for j in arr[ord(key[i])-ord('a')]: #每个字符只用考虑ring[j]等于该字符的j
                rotate=float('inf')
                for k in arr[ord(key[i-1])-ord('a')]: #完成上一个字符后12点对应的位置，只用考虑从这些位置开始转动
                    temp=dp[i-1][k]+min(abs(j-k),len(ring)-abs(j-k)) #比较从哪个位置转过来步数最少
                    if rotate>temp:
                        rotate=temp
                        dp[i][j]=temp
        
        res=float('inf')    
        for j in arr[ord(key[i])-ord('a')]:
            res=min(res,dp[i][j]) #完成最后字符可能停在多个位置，选择最少的一个，再加上按下中心按钮len(key)次
        return res+len(key)

```