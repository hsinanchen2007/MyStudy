# 思路
题目的要求是查找最小除数，使得`nums`中所有的数除以除数的和不大于阈值(向上取整)，如果一个一个的试，那时间复杂度就太高。最好的办法就是二分查找。
首先确定查找的上下界，下界当然是1，对于上界当然是`max(nums)`（如果除数大于`max(nums)`，那么除以后的和一直就是`nums`的元素个数，再向上考虑就没有意义。）
最重要的一点，是查找最小的除数，所以如果找到除数`k`满足和小于等于阈值，却不一定是最小的...我的做法是，再对`k-1`进行检查，如果和大于阈值，那么`k`就是最小的除数～～

# 代码
## `CPP`
```cpp
class Solution {
public:
    int check(vector<int>& nums, int div) {
        int sum = 0;
        for (auto each : nums) {
            sum += ((0 == each % div) ? each / div : each / div + 1);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int len = nums.size();
        if (1 == len) {
            if (0 == nums[0] % threshold) return nums[0] / threshold;
            else return nums[0] / (threshold - 1);
        }
        int l = 1, r = *max_element(nums.begin(), nums.end()), mid = (l + r) / 2;
        while (true) {
            int re = check(nums, mid);
            if(threshold >= re) {
                if (1 == mid) return mid;
                if (check(nums, mid - 1) > threshold) {
                    return mid;
                }
                r = mid;
                mid = (mid + l) / 2;
            } else {
                l = mid;
                mid = (mid + r) / 2;
            }
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/bc74d146fd72a5855e70cdb590fc848a057aa10b819e5ed9b6fb52060f00a68e-image.png)

## `Go`
```go
func check(nums []int, div int) int {
	sum := 0
	for _, each := range nums {
		sum = sum + (each / div)
		if 0 != each % div {
			sum ++
		}
	}
	return sum
}

func smallestDivisor(nums []int, threshold int) int {
	_len := len(nums)
	if 1 == _len {
		if 0 == nums[0] % threshold {
			return nums[0] / threshold
		} else {
			return nums[0] / (threshold - 1)
		}
	}
	l := 1
	r := 0
	for _, each := range nums {
		if r < each {
			r = each
		}
	}
	mid := (l + r) / 2
	for ; ; {
		re := check(nums, mid)
		if threshold >= re {
			if 1 == mid {
				return mid
			}
			if check(nums, mid - 1) > threshold {
				return mid
			}
			r = mid
			mid = (mid + l) / 2
		} else {
			l = mid
			mid = (mid + r) / 2
		}
	}
}
```
![image.png](https://pic.leetcode-cn.com/1549c1f4899e9839145bb7b5abac7b262265f29ec706601c918aff29d24d9006-image.png)

## `Python`
```python
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        if 1 == len(nums):
            if 0 == nums[0] % threshold:
                return nums[0] / threshold
            else:
                return nums[0] / (threshold - 1)
        l = 1
        r = max(nums)
        mid = (l + r) / 2

        while True:
            re = sum(map(lambda x: math.ceil(x/mid)), nums)
            if threshold >= re:
                if 1 == mid:
                    return mid
                if sum(map(lambda x: math.ceil(x/(mid - 1)), nums)) > threshold:
                    return mid
                r = mid
                mid = (mid + l) / 2
            else:
                l = mid
                mid = (mid + r) / 2

```
![image.png](https://pic.leetcode-cn.com/99430ad6c7306f7c7f5feb0d737e8b382613b5d37608a9a4ce989fa31d51e3b5-image.png)


# 分析
- 时间复杂度（长度为`n`）：$O(n*log_2{(max(nums))})$
- 空间复杂度：$O(1)$
    
