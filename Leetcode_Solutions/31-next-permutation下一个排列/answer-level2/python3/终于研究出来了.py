
题目确实比较难读懂，研究了好久。


```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def find_pos(nums,n) :
            for i in range(n-2,-1,-1) :
                if nums[i] < nums[i+1] : return i
            return -1

        def fn_rev(nums,n,pos=0):
            i,j = pos,n-1
            while(i<j):
                nums[i],nums[j] = nums[j],nums[i]
                i+=1
                j-=1

        def fn_change(nums,n,pos):
            for j in range(n-1,pos,-1) :
                if nums[j] > nums[pos]:
                    nums[pos],nums[j] = nums[j],nums[pos]
                    break

        n = len(nums)
        pos = find_pos(nums,n)
        if pos == -1:
            fn_rev(nums,n)
        else :
            fn_change(nums,n,pos)
            fn_rev(nums,n,pos = pos+1)
        return
```

即便找到了pos，对后面的也要做反转，达到最小的目的。
另外 如果pos 不返回-1如果为空的话，在写if条件的时候pos为0 和为fale就会混在一起。