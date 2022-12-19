# 解题思路
定义2个指针，首指针first,尾指针last。首先判断首指针是否为奇数，如果是的话，首指针向右位移一位，即first+1;若为偶数的话，直接交换首指针和尾指针的数字，此时，尾指针的数字为偶数，那么尾指针向左位移位，即last-1。通过循环，直到首指针和尾指针重合，结束循环，返回数组即可。

# 代码
```
class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        first = 0
        last = len(nums)-1
        while first<last:
            if nums[first]%2!=0:
                first+=1
            else:
                nums[first],nums[last]=nums[last],nums[first]
                last-=1
        return nums
```
