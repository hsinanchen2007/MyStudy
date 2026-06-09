left指向了最后一个是拐点的值，如果i遍历的元素不是拐点则会往后跳，当i指向的元素是拐点时，则把left更新为当前i。
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        #根据题目要求，小于两个元素的序列都是摆动序列
        if len(nums) < 2:
            return len(nums)
        #给计数器赋初值为1
        count  = 1
        left = 0
        for i in range(1,len(nums)-1):
            if (nums[i]-nums[left])*(nums[i]-nums[i+1]) > 0:
                count +=1
                left = i
        else:
            if nums[-1]!=nums[left]:
                count+=1
        return count
```
