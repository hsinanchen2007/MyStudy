先看53最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**其解题思想来自其中一个题解**：作者：acnesu
    假设你是一个选择性遗忘的赌徒，数组表示你这几天来赢钱或者输钱，
    你用sum来表示这几天来的输赢，
    用ans来存储你手里赢到的最多的钱，

    如果昨天你手上还是输钱（sum < 0），你忘记它，明天继续赌钱；
    如果你手上是赢钱(sum > 0), 你记得，你继续赌钱；
    你记得你手气最好的时候

根据这个思想，给出如下代码：
```
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if len(nums) == 1:
        #     return nums[0]

        sum_ = 0
        ans = max(nums) 

        for i in range(len(nums)):
            sum_ += nums[i]
            if sum_ < 0 :
                sum_ = 0
            else:
                ans = max(ans,sum_) ## 这里需要思考如果数组都是负数的情况是怎么样的
        return ans
```

再看本题：
加油站给了一个gas，一个cost，我们用gas-cost，得到一个remains，本题答案如果有解就是唯一解，那是不是就相当于求新数组remains的最大自序和？唯一不同的就是返回的是下标而不是和。
```
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """

        if sum(gas) < sum(cost):
            return -1
        
        remains = []
        for i in range(len(gas)):
            remains.append(gas[i] - cost[i])

        sum_ = 0
        ans = 1000000
        for i in range(len(remains)):
            sum_ += remains[i]
            if sum_ >= 0:
                ans = min(i,ans)  ## 注意和上面对比
            else:
                ans = 100000
                sum_ = 0
        return ans
```

很明显可以看出，这两题一模一样几乎。

ps：我几个月前找第一份实习的时候，去一家小公司面试数据挖掘，一上来什么都没问就给了这道题 #加油站，我写不出来，什么都没多说就让我走了...那次让我意识到数据挖掘岗对统计的学生有多不友好...好好刷题 

