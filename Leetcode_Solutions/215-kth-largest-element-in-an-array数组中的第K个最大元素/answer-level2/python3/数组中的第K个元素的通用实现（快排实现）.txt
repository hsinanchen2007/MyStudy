数组中第K个（最大/小）元素的实现思路都是一致的，即通过快排不断地局部排序、不断地缩小取值区间，最终求得某位置的解。
本题实现代码如下：
```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return get_Kth(nums, k)
```
另外此处是通用的得到数组的第K个元素的实现：
```
def get_Kth(lst, k, large=True):
    def partition(arr, left, right):
        pivot = left
        index = pivot + 1
        for i in range(index, right + 1):
            if arr[i] < arr[pivot]:
                arr[i], arr[index] = arr[index], arr[i]
                index += 1
        arr[pivot], arr[index - 1] = arr[index - 1], arr[pivot]
        return index - 1

    position = len(lst) - k if large else k
    left_ = 0
    right_ = len(lst) - 1
    mid = partition(lst, left_, right_)
    while mid != position and left_ < right_:
        if mid < position:
            left_ = mid + 1
        else:
            right_ = mid - 1
        mid = partition(lst, left_, right_)
    if mid == position:
        return lst[mid]
    return None
```
