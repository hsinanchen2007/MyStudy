Time: 20190904
Type: Hard, DP

### 题目描述
给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

注意:
数组长度 n 满足以下条件:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:

输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-largest-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路
关于DP类问题，个人感觉需要先在纸上推导明白状态定义，递推公式，能手工推导一部分解，然后有了大概的概念就可以转换为代码了。

这是一类最大最小问题。

简单说就是将数组划分为多组，每组会求一个和，多组的和最大值的可能性很多，求多组和的最小值的可能性。

状态定义：`f[i][j]`表示`nums[0] ~ nums[j]`共`j+1`个元素划分为`i`组的和的最大最小值。
可初始化的状态：`f[1][j]`表示`nums[0]~nums[j]`划分为1组的分组和的最大最小值，显然`f[1][j] = sum(0, j)`，包含边界。
状态迁移方程：`f[i][j] = min(max(f[i-1][k], sum(k+1, j))), 0<= k < j`

这种问题的状态迁移方程很具有代表性，即在右边划一段出来，先把问题规模`-1`，然后剩下的只需要再切分为`i-1`组即可。

其中`k`是这缩小问题规模的切分点。

### 代码
```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        presum = [0 for i in range(len(nums))]
        presum[0] = nums[0]
        for i in range(1, len(nums)):
            presum[i] =  presum[i-1]  + nums[i]    
        # presum[j] - presum[i] = [i+1, j]
        
        # f[i][j]表示从nums[0]~nums[j]分成i组的解
        f = [[float('inf')] * len(nums) for i in range(m+1)]
        # f[1][j] = sum(0, j), 包含边界，表示只划分一段时的解
        for j in range(len(nums)):
            f[1][j] = presum[j]
            
        for i in range(2, m + 1):
            for j in range(i - 1, len(nums)):
                for k in range(0, j):
                    f[i][j] = min(f[i][j], max(f[i-1][k], presum[j] - presum[k]))
        return f[m][len(nums)-1]
```

但是这道题用Python会超时，用C++不会超时。

```c++
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long>> f(n + 1, vector<long>(m + 1, INT_MAX));
        vector<long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        
        f[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];
    }
};
```

### 时空复杂度

时间复杂度：$O(mn^2)$
空间复杂度：$O(mn)$


本题最优解是二分法，时间复杂度要比这个要优秀得多。

下面就来看二分法是什么思路以及如何写出对应的代码。

#### 二分法的思路

本题二分法的思路很有意思，首先我们想子数组的最大和一定比所有元素的最大值要大或者相等，要比整个数组的和要小。

有了上下界，我们就可以用二分的方式在其中遍历。遍历的过程是，我们从上下界的中间出发，定一个最大和的值`mid`，然后对数组进行划分，从左往右，加和恰好大于`mid`时，表示当前这个`num`不能再往本组加了，一加就超过了，所以一组划分好了，我们用`temp`跟踪当前的数组和，既然这个`num`不属于当前一组，一定是下一组，于是`temp = num`。在`temp`没大于`mid`前，只管累加即可。

统计出当前`mid`下可以划分多少组后，就可以和`m`比较，如果划分的组数大于`m`，表示`mid`值太小了，将下边界`left`值变大，否则划分的组数没到`m`，表示`mid`大了，将上边界`right`下移。

二分的骨架是一样的，重点是这个思路以及在`mid`的统治下统计有多少组。

理解了这个二分，代码将变得非常简单自然。

```python

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def countGroups(mid):
            temp = 0
            count = 1
            for num in nums:
                temp += num
                if temp > mid:
                    count += 1
                    temp = num # 准备下一组
            return count
        
        left, right = max(nums), sum(nums)
        
        while left < right:
            mid = left + (right - left) // 2
            num_group = countGroups(mid)
            
            if num_group > m: # 划分多了，mid太小了
                left = mid + 1
            else:
                right = mid
        print(left, mid, right)
        return left # left恰好是满足条件的最少分割，自然就最大
```

注意`count`从1开始计数，因为无论如何都有一组。

END.

