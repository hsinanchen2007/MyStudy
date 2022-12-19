### 解题思路
首先分析这个题肯定是一个dp问题，很明显后面的状态跟前面的结果有关，然后其次这还是一个贪心问题。具体是怎么贪心的呢，我们可以这样想一下
比如说[1,17,5,10,13,15,10,5,16,8]这个测试用例，取第三个数5的时候，我们可以这么考虑。第三个数要取一个比第二个数小的数，那么我们可以取
5，10都可以，具体怎么取呢，遵从这样一个原则：假如下一个数要取比前一个数小的数，那们我们再可以选择的数里面取最小的，这样就有更大的概率下一个数会比
这个数大，也就是取数字5，那么前三个满足要求的数就是[1，17，5]，下一个数要选比5大的数，可以看到10，13，15中要选一个，这种情况下我们选择可以选的最大的数，也就是15，应为这样的话，更有可能下一个数比15小，这就是贪心原则。

然后再看动态规划，首先dp[i]要么等于dp[i-1] + 1,要么等于dp[i-1]，具体的要看下一个加入数组的值与当前摆动数组的最后一个值的关系，是需要找一个比它大的，还是比它小的，所以我们需要一个type来记录下一个值需要什么样的，同时也要保存一个当前摆动数组的最后一个值，以便于比较，然后得出dp方程：

![IMG_20191220_193409.jpg](https://pic.leetcode-cn.com/2fc5754a8fbe6b74e48578d7f606a446b9816bb21ddebfa0ef31e583073c6fbb-IMG_20191220_193409.jpg)


最后加一下边界判断即可

![UC截图20191220193624.png](https://pic.leetcode-cn.com/ba31d39d0215d2b0066acb6428721d44252ca1a66d0e32eba6e14591245ff037-UC%E6%88%AA%E5%9B%BE20191220193624.png)



### 代码

```python3
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return 1
        dp = [[1, 0, 0] for i in range(len(nums) + 1)]
        dp[1][1] = nums[0]
        count = 0
        for i in range(1,len(nums)):
            if nums[i] != nums[0]:
                dp[i+1][0] = 2
                dp[i+1][1] = nums[i]
                if nums[i] > nums[0]:
                    dp[i+1][2] = True
                else:
                    dp[i+1][2] = False
                count = i
                break
        if len(nums) > 2:
            for i in range(count+1, len(nums)):
                if nums[i] < dp[i][1] and dp[i][2] == True:
                    dp[i + 1][0] = dp[i][0] + 1
                    dp[i + 1][2] = False
                elif nums[i] > dp[i][1] and dp[i][2] == False:
                    dp[i + 1][0] = dp[i][0] + 1
                    dp[i + 1][2] = True
                elif nums[i] >= dp[i][1] and dp[i][2] == True:
                    dp[i + 1][0] = dp[i][0]
                    dp[i + 1][2] = dp[i][2]
                elif nums[i] <= dp[i][1] and dp[i][2] == False:
                    dp[i + 1][0] = dp[i][0]
                    dp[i + 1][2] = dp[i][2]
                dp[i + 1][1] = nums[i]
        return dp[-1][0]
```


感觉还能优化，各位大佬也可以再优化一下ヾ(•ω•`)o