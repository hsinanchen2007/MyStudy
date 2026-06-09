### 解题思路
**总结**
转移方程挺简单的，但是这题逻辑还是挺缜密的，需要考虑到方方面面，提交了3次才通过

2次错误的提交是因为没有考虑到两种极限的情况：
1. amount = 0 时，返回应是0

2. 测试样例为[1,,2147483647] 2 时，在程序中加上了i-j>0 解决

下面是思考的一些**关键点**
1. dp[i] = min(dp[i-j]) + 1 (j in coins) 

2. dp[i]表示总金额为i时，用coins组合成i所需用到的最少硬币数
3. 对于i < min(coins) 的i，不可能有硬币可以组合成i，因此dp[i] = -1
4. 以上这步在dp初始化的时候就已经完成了，所以下面计算dp[i]的循环可以从min(coins)开始
5. 显而易见dp[i] = 1 当 i in coins 时 (此时只需要从提供的硬币中拿对应数值的一枚)
6. 我们的思路是求min(dp[i-j])，但是需要排除dp[i-j] == -1的情况，否则min(dp[i-j])极有可能为-1
7. 本来想让dp[i-j]相互之间比较得到最小值的，但是又要设置初始值，又要排除-1的情况，所以这里我直接设置了一个列表保存所有可能的组合情况，最后取列表的最小值即可；最后不能忘记清空列表否则在下一次循环的时候会有上次列表的记录...

### 代码

```python
class Solution:
    # dp[i]表示总金额=i时，硬币组合所需的最少硬币数
    # dp[i] = min(dp[i-j]) + 1 (j in coins)
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        if amount < min(coins):
            return -1
        dp = [-1]*(amount + 1)
        '''
        这步可以省略，因为上面初始化的时候已经全部设置为-1了，所以下面的循环直接从min(coins)开始计算
        # 先把coins的最小值之前的初始化为-1
        for i in range(1,min(coins)):
            dp[i] = -1
        '''
        
        # 保存每次计算dp[i]时的组合数
        temp = []
        # 计算缓存表
        for i in range(min(coins),amount+1):
            if i in coins:
                dp[i] = 1
            else:
                # 标志是否存在硬币组合
                flag = 0
                for j in coins:
                    # 控制i-j>0是为了不考虑超出总金额i的数，因为组合钱是用不到超过i的数的
                    if i-j>0 and dp[i - j] != -1:
                        flag = 1
                        # 组合的硬币个数
                        temp.append(dp[i-j] + 1)
                # 所有dp[i-j] == -1
                if flag == 0:
                    dp[i] = -1
                    continue
                dp[i] = min(temp)
                # 方便下一次添加元素
                temp.clear()
        return dp[-1]
            
```