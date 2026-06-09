```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def stacksort(nums,k):
            def adjust(nums,i):
                l=2*i+1
                r=2*i+2
                smallest=i
                if l<k and nums[l]<nums[smallest]:
                    smallest=l
                if r<k and nums[r]<nums[smallest]:
                    smallest=r
                if not smallest==i:
                    nums[smallest],nums[i]=nums[i],nums[smallest]
                    adjust(nums,smallest)
            for i in range(k//2-1,-1,-1):
                adjust(nums,i)
            return nums
        stacklist=nums[:k]
        stacklist=stacksort(stacklist,k)
        for num in nums[k:]:
            if num>stacklist[0]:
                stacklist[0]=num
                stacklist=stacksort(stacklist,k)
        return stacklist[0]
```
