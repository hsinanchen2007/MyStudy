### 解题思路
思路和三数之和类似，首先进行两层循环，再在其中设置头尾指针，并将符合条件的结果加入结果列表。

### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)-3):
            for j in range(i+1, len(nums)-2):
                m = j+1
                n = len(nums)-1
                while m<n:
                    s = nums[i]+nums[j]+nums[m]+nums[n]
                    if s==target:
                        if [nums[i], nums[j], nums[m], nums[n]] not in ans:
                            ans.append([nums[i], nums[j], nums[m], nums[n]])                       
                        m += 1
                        n -= 1
                    elif s<target:
                        m += 1
                    else:
                        n -= 1
        return ans

```