题目 有序数组  
看见tag 双指针大概就有思路了 一个负责记录位置  一个负责探寻下一个值
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        first_pointer = sec_pointer = 0
        while sec_pointer <= len(nums) -1:
            if nums[first_pointer] == nums[sec_pointer]:
                sec_pointer += 1
            else:
                nums[first_pointer + 1] = nums[sec_pointer]
                first_pointer += 1
                sec_pointer += 1
        return first_pointer + 1
  
```
用fir_pointer 记录当前的位置  然后用sec_pointer去探索下一个值，比较sec的值是否等于fir的值，相等的话就不管，sec++继续比较
直到sec != fir 的时候直接把sec的值覆盖fir后一位的值 然后把fir和sec都++


  

