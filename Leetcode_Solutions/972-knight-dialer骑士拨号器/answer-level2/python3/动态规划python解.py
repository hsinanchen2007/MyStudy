### 解题思路
dp二维状态考虑（start，N）
start表示起始移动的位置，N表示几位数字
moves为起始位置分别为0-9的时候，它的下一步可跳转位置
初始的时候全部赋值为1
然后循环N-1次
因为我们根据递推公式可知当前位置数字应该等于它可能的上一个位置数字之和
而且当前循环只和上一个循环有关
所以我们可以只用一维数组去不断更新

这里取模的地方容易出错，然后在更新的顺序上也有不同的写法，大家可以自行探索

### 代码

```python3
class Solution:
    def knightDialer(self, N: int) -> int:
        # 初始时为一位的时候，就是起点的数值
        dp = [1]*10
        moves = [[4,6],[6,8],[7,9],[4,8],[3,9,0],[],
                     [1,7,0],[2,6],[1,3],[2,4]]
        # 10e9 和 10**9是不一样的,一个是
        MOD = 10**9 + 7
        
        for i in range(N-1):
            dp2 = [0] * 10
            for start,count in enumerate(moves):
                for k in count:
                    dp2[k] += dp[start]
                    dp2[k] %= MOD
            dp = dp2
        
        # 输出的时候需要取一次模，因为答案可能会非常大，这里需要特别注意
        return sum(dp) % MOD
        
            
            
```