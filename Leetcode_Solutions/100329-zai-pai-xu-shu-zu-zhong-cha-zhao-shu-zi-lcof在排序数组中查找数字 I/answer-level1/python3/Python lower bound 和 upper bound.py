参考[知乎大佬的解释](https://www.zhihu.com/question/36132386/answer/530313852) 我感觉写得相当好


总结一下模板:

**二分查找得到下界**

```python
def lower_bound(nums: list, target: int) -> int:
    '''
    return the target lower bound index in nums
    '''
    first, last = 0, len(nums)
    while first < last:
        mid = first + (last - first) // 2
        # 注意此处是小于号
        if nums[mid] < target:
            first = mid + 1
        else:
            last = mid
    return first
```
返回的`first` 如果等于数组长度或者对应位置索引不等于目标值,那么说明没有找到

**二分查找得到上界**

```python
def upper_bound(nums: list, target: int) -> int:
    '''
    return the first idx in nums when nums[idx] > target
    '''
    first, last = 0, len(nums)
    while first < last:
        mid = first + (last - first) // 2
        # 注意直接把 < 改成 <=
        if nums[mid] <= target:
            first = mid + 1
        else:
            last = mid
    return first
```
该函数返回的是第一个大于目标值的索引, 如果返回0或者该索引前一个位置的值不是目标值,说明查找失败


**本题的写法**

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0

        left, right = 0, len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        if left == len(nums) or nums[left] != target:
            return 0 # 没有找到, 直接返回0
        idx1 = left
        
        # 如果这里能够运行, 肯定是找到了target的
        left, right = 0, len(nums)
        while left < right:
            mid = left + (right - left) // 2
            # note that change to <=
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid
        # upper bound 应该是 right - 1
        # 返回 right - 1 - idx1 + 1
        # 退出循环时 left = right 
        return left - idx1
```