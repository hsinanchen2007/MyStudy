### 解题思路
        # 利用双指针：left以及i(看做一直向右滑动的右指针)以及一个滑动窗口sum
        # sum用来累加遍历数组时获取到的每个元素,当sum >= s时，先计算当前窗口的大小size(即i-left+1)
        # 然后将sum的值减去left指针当前指向的元素值，之后再将left指针向右移动一格，继续下面的遍历
        # 同时声明一个size_list列表来存放符合条件的窗口大小
        # 当右指针到达数组右边界时(即遍历结束)，继续判断当前滑动窗口的值sum是否依旧大于s
        # 如果sum>s,继续减去left指针指向的元素并移动left，直到left指针到达临界点为止(即left<len(nums) - 1)
        # 最后从size_list中找到整个过程滑动窗口最小的值size作为结果返回

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # 利用双指针：left以及i(看做一直向右滑动的右指针)以及一个滑动窗口sum
        # sum用来累加遍历数组时获取到的每个元素,当sum >= s时，先计算当前窗口的大小size(即i-left+1)
        # 然后将sum的值减去left指针当前指向的元素值，之后再将left指针向右移动一格，继续下面的遍历
        # 同时声明一个size_list列表来存放符合条件的窗口大小
        # 当右指针到达数组右边界时(即遍历结束)，继续判断当前滑动窗口的值sum是否依旧大于s
        # 如果sum>s,继续减去left指针指向的元素并移动left，直到left指针到达临界点为止(即left<len(nums) - 1)
        # 最后从size_list中找到整个过程滑动窗口最小的值size作为结果返回
        left = 0
        sum_ = 0
        size = 0
        size_list = []
        if len(nums) ==0:
            return 0
        for i in range(len(nums)):
            sum_ += nums[i]
            if sum_ >= s and left <len(nums)-1 and i <=len(nums)-1:
                while(sum_>=s):
                    size = i - left +1
                    size_list.append(size)
                    sum_ -= nums[left]
                    left += 1
        if len(size_list) != 0:
            size = min(size_list)   
        return size
                
            
            
```