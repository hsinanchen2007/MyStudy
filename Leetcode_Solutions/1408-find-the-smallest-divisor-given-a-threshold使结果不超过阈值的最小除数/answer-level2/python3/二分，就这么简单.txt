find 函数判断此时的除数是否满足小于等于阈值的条件
在（1，max（nums））的可行域内二分查找，mid不满足条件就说明除数太小，到右半边查找
mid满足条件说明，除数有可能更小，到左半边查找
最后跳出循环时left == right 就是我们要的答案
```
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def find(nums,chu,t):
            now = 0
            for n in nums:
                now += math.ceil(n/chu)
                if(now > t):
                    return False
                
            return True
        
        left, right = 1 , max(nums)
        while(left<right):
            mid = left + (right - left)//2
            if(find(nums,mid,threshold)):
                right = mid
            else:
                left = mid+1
                
        return left
                
```
