### 解题思路
1.按#001两数之和使用双指针查找a+b = -c，遍历c
2.去重，指针移动时应当跳过重复数字

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 双指针
        """
        1.按#001两数之和使用双指针查找a+b = -c，遍历c
        2.去重，指针移动时应当跳过重复数字
        """
        lens = len(nums)
        nums.sort()
        if lens <=2 or nums[0]>0:
            return []
        i, j = 0, 1
        k = lens-1
        res = []
        while nums[i] <= 0 and i <= lens-3:
            target = -nums[i]
            t0 = i
            while k>j:
                t1, t2 = j, k
                s = nums[j] + nums[k]
                if target == s:
                    res.append([nums[i], nums[j], nums[k]])
                    while nums[j] == nums[t1]:
                        j += 1
                        if j >= lens-1:
                            break
                    while nums[k] == nums[t2]:
                        k -= 1
                        if k <= 0:
                            break
                elif target > s:
                    while nums[j] == nums[t1]:
                        j += 1
                        if j >= lens-1:
                            break
                else:
                    while nums[k] == nums[t2]:
                        k -= 1
                        if k <= 0:
                            break
            while nums[i] == nums[t0]:
                i += 1
                if i >= lens-1:
                    break
            j = i+1
            k = lens-1

        return res



```