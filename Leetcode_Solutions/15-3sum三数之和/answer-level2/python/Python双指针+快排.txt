### 解题思路
思想很简单和精选题解的思路一样，强调一些细节。
(1) 提前结束循环：nums[i] > 0，因为三个整数的和不可能为0
(2) 避免重复答案：从i, j, k三个下标的值避免重复答案，对应代码都在代码中标出，运用了递推的思想，只要和之前的旧值相同即指向下一个值。
时间复杂度分析：
快排：O(nlogn)
遍历：O(n^2)
所以总的复杂度是O(nlogn) + O(n^2) = O(n^2)

### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length < 3:
            return []
        self.quick_sort(nums, 0, length - 1) # 将数组排序
        res = []
        i = 0
        while i < length - 2:
            if nums[i] > 0: # trick
                break
            if i > 0 and nums[i] == nums[i - 1]: # 避免重复答案
                i += 1
                continue
            j = i + 1
            k = length - 1
            while j < k:
                if nums[j] + nums[k] == -nums[i]:
                    res.append([nums[i], nums[j], nums[k]])
                    # 更新j, k
                    j += 1 
                    k -= 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                elif nums[j] + nums[k] > -nums[i]:
                    k -= 1
                else:
                    j += 1
            i += 1
        return res

    def quick_sort(self, data, left, right):
        """
        快速排序
        """
        if right - left <= 0:
            return 
        temp = data[left]
        p, q = left, right
        while p != q:
            while p != q and data[q] > temp:
                q -= 1
            if p != q:
                data[p] = data[q]
                p += 1
            while p != q and data[p] < temp:
                p += 1
            if p != q:
                data[q] = data[p]
                q -= 1
        data[p] = temp
        self.quick_sort(data, left, p - 1)
        self.quick_sort(data, p + 1, right)
```