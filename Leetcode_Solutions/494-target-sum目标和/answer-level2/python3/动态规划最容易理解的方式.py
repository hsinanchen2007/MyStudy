# 分析

首先，我们需要分析可能的值是怎么来的。

以官方例子为例：
输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5


当我们只用第一个元素时，值域是
组成方式

* [+1] : 1
* [-1] : -1

当我们加入一个元素a[2]，它可能为[1, -1]
组成方式

* [+1, +1] : 2
* [+1, -1] : 0
* [-1, +1] : 0
* [-1, -1] : 1

后续的我们可以再算一层，方便观察规律

| i | a[i] | -3  | -2  | -1  | 0  | 1  | 2  | 3  |
| -- |:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
| 0  |  1 |    |    | 1  |    | 1  |    |    |
| 0  |  1 |    |  1  |    |  2  |    |  1  |    |
| 0  |  1 |  1  |     |  3  |     |  3  |     |  1  |

每加入一个元素。都有两个状态。[+a[i],-a[i]]
我们可以观察出这两个特征：

1. 组合的结果集是上一层结果集每个都加入a[i], -a[i]
2. 结果集出现的次数也是由上一层对应结果集的次数叠加而成

第2点很重要。我们可以定义出一个二维状态转移方程。i维表示前i个元素，j标识前i个元素的总和和出现数量

dp[i][j] = dp[i-1][j+a[i]] + dp[i-1][j-a[i]]

也就是状态这样定义

```python
dp = [collections.defaultdict(int)] * len(nums)
```

使用这种方法即使题目改变定义，数组和很大或者数组元素很多依然可解。

# 最终答案

更优的是使用临时数组降维
```python
class Solution:
    # 二维数组版本
    def findTargetSumWays_2dim(self, nums: List[int], S: int) -> int:
        import collections
        total = sum(nums)
        dp = [collections.defaultdict(int) for _ in range(len(nums))]
        # 初始值 0表示第一个元素
        dp[0][nums[0]] += 1
        dp[0][-nums[0]] += 1
        for i in range(1, len(nums)):
            num = nums[i]
            for sm in range(-total, total+1, 1):
                # 状态转移方程
                # dp[i][j] = dp[i-1][j+a[i]] + dp[i-1][j-a[i]]
                val = dp[i-1].get(sm+num, 0) + dp[i-1].get(sm-num, 0)
                if val != 0:
                    dp[i][sm] = val
        return dp[-1][S]  # 返回所有元素组合的题解数量

    # 使用临时容器(defaultdict)降维
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        import collections
        total = sum(nums)
        # 每一次状态转移均在此更新
        dp = collections.defaultdict(int)
        dp[nums[0]] += 1
        dp[-nums[0]] += 1
        for i in range(1, len(nums)):
            # 临时数组
            tmp = collections.defaultdict(int)
            num = nums[i]
            for sm in range(-total, total+1, 1):
                val = dp.get(sm+num, 0) + dp.get(sm-num, 0)
                if val != 0:
                    tmp[sm] = val
            dp = tmp
        return dp[S]
```

# 备注

大部分答主的状态转移方程定义的是值域数组。这样很不好理解，也不够通用。万一题目变为每个元素很大怎么办，很容易就把这种可能忽略掉。虽然题目中规定了数组的合不超过1000，也就是共2001种可能。

dp = [0] * sum(nums)
