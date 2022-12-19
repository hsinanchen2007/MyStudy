1. 逆序遍历列表，删除重复项
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = len(nums) - 1
        cont = 1
        if len(nums) == 0:
            return 0
        while i != 0:
            if nums[i-1] != nums[i]:
                cont += 1
                i -= 1
            else:
                del nums[i-1]
                i -= 1
        return cont
```
这样从最后遍历数组，遇到相同的数字后就就行删除，更新下标为i-1，最后的得到一个只包含不重复数字的列表。
考虑到这样做和题意有些不符，题目只是说“不去关注后面的数字”并没有提及是否删除。所以换用双指针
2.双指针
 
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        cont = 0
        for i in range(len(nums)):
            if nums[cont] != nums[i]:
                cont += 1
                nums[cont] = nums[i]
        return cont+1
```
