### 解题思路
题解来自于 [画解算法：15. 三数之和](https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/)

主要是去重，以及特殊样例 [0,0,0,0,0]

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n<3:
            return []
        result = []
        nums.sort()
        for i in range(n-2):
            if i>0 and nums[i] == nums[i-1]:  # i=0 时会有 bug, i-1=-1 样例 0,0,0,0 
                continue  # 是否能起作用？
            elif nums[i] > 0:
                break 
            else:
                t = nums[i]
                j, k = i+1, n-1
                while j<k:
                    sum3 = t + nums[j] + nums[k]
                    if sum3 == 0:
                        result.append([t, nums[j], nums[k]])
                        j += 1
                        k -= 1
                        while (j<n) and (nums[j] == nums[j-1]):
                            j += 1
                        while (k>=0) and (nums[k] == nums[k+1]):
                            k -= 1
                    elif sum3 > 0:
                        k -= 1
                    else:
                        j += 1
        return result

```