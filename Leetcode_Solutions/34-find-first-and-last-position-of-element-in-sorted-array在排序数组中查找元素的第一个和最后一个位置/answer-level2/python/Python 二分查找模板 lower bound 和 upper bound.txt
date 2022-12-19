刷探索遇到的, 提供一下python二分查找的模板:

# 查找target在数组中的下界

下界被定义为, target在数组中第一次出现的索引.
如果target没有在数组中出现, 则返回数组中比target小的数字的最大索引
例如
```
target = 5
0 1 2 3 4 5 5 5 : return 5
0 1 2 3 4 6 7 8 : return 4
0 1 2 3 4 4 4 4 : return 8
```
代码如下:
```python
def lower_bound(nums: list, target: int) -> int:
    '''
    return the target lower bound index in nums
    from c++ algorithms
    '''
    first, last = 0, len(nums)
    while first < last:
        mid = first + (last - first) // 2
        if nums[mid] < target:
            first = mid + 1
        else:
            last = mid
    return first
```
# 查找 target在数组中的上界
上界被一定以为, 数组中第一个比terget大的数字的索引, 只需要对查找下界代码略微修改即可
```python

def upper_bound(nums: list, target: int) -> int:
    '''
    return the first idx in nums when nums[idx] > target
    '''
    first, last = 0, len(nums)
    while first < last:
        mid = first + (last - first) // 2
        # 小于号 改成 小于等于
        if nums[mid] <= target:
            first = mid + 1
        else:
            last = mid
    return first
```
# 此题的题解

此题 首先判断target是否在数组中, 如果不在直接返回, 如果在的话, 调用两函数找到上界和下界返回即可
```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        def upper_bound(target):
            l, r = 0, len(nums)
            while l < r:
                mid = (l + r) >> 1
                if nums[mid] <= target:
                    l = mid + 1
                else:
                    r = mid
            return l - 1
        
        
        def lower_bound(target):
            l, r = 0, len(nums)
            while l < r:
                mid = (l + r) >> 1
                if nums[mid] < target:
                    l = mid + 1
                else:
                    r = mid
            return r
        if not nums:
            # 空直接返回
            return [-1, -1]
        l1 = lower_bound(target)
        # 判断 target 是否在数组中
        if l1 > len(nums) - 1 or nums[l1] != target:
            return [-1, -1]
        return [l1, upper_bound(target)]
```