<!-- 直接移除法，顾名思义，就是遍历列表，遇到目标元素直接remove删除，此时列表长度减1 -->
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0 
        while i<len(nums):
            if nums[i] == val:
                # 删除当前元素，此时指针i对应当前元素的下一位，故i不变
                nums.remove(nums[i])
            else:
                i+=1

        return len(nums)


<!-- 双指针法 ， 思路：将目标元素移到列表后面-->
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        i = 0 
        j = n-1
        k = n
        while i<k:
            if nums[i] == val:
                if nums[i] != nums[j]:
                    # 指针i与指针j对应的元素互换位置
                    nums[i],nums[j] = nums[j],nums[i]
                    i += 1
                    j -= 1
                    k -= 1
                    
                else:
                    j -= 1
                    k -= 1
            else:
                i += 1

        return k