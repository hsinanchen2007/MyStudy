```
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if len(nums)<=2:
            return len(nums)
        
        #一个指针从0开始，一个从2开始
        man = 0
        kuai = 2
        
        #依次遍历
        while kuai<len(nums):
            #不相等就是无2个以上元素
            if nums[man] != nums[kuai]:
                man += 1
                kuai += 1
            #相等就说需要删除，删除之后节点无需移动
            elif nums[man] == nums[kuai]:
                nums.remove(nums[kuai])
                
        return len(nums)
```
