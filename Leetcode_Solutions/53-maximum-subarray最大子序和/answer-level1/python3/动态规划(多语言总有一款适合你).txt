# 思路

感觉使用动态规划最为直接，也很好理解。分治法可能不太好理解，这里还是采用动态规划

- 问题拆分

    我们认为第`i`个数字是最大和连续数组的最右边数字，这就可以分为两种情况：一是第`i`个数字就是最大和连续数组，二是第i个数字加上`0~i-1`之间的最大和连续数组是新的最大和连续数组。

- 公式

$$

\begin{cases}

dp & = nums[0] & \text{初始化} \\

dp & = dp + nums[i] & \text{$dp > 0$} \\

dp & = nums[i] & \text{$dp <= 0$}

\end{cases}
$$



可以再使用额外一个变量记录最大连续和。



# 代码

## `cpp`

```cpp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len < 1) {
            return 0;
        } else {
            int dp = nums[0];
            int re = dp;
            for (int i = 1; i < len; i++) {
                dp = dp > 0 ? dp + nums[i] : nums[i];
                re = dp > re ? dp : re;
            }
            return re;
        }
    }
};
```

## `Go`

```go
func maxSubArray(nums []int) int {
	if len(nums) < 1 {
		return 0;
	} else {
		dp := nums[0]
		re := dp
		for _, each := range nums[1:] {
			if dp > 0 {
				dp += each
			} else {
				dp = each
			}
			if dp > re {
				re = dp
			}
		}
		return re;
	}
}
```

## `Python3`

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return 0
        else:
            dp = nums[0]
            re = dp
            for each in nums[1:]:
                dp = dp + each if dp > 0 else each
                re = dp if dp > re else re
            return re
```
![image.png](https://pic.leetcode-cn.com/7b6a4e9d0a5a4af42f660757dd9841b336876e698ceb9540a7dd8a763018cc63-image.png)


# 分析
- 时间复杂度
遍历一遍，因此时间复杂度为$O(n)$
- 空间复杂度
没有额外的空间，因此空间复杂度为$O(1)$