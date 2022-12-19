
先建立初始堆，然后进行k-1次排序（堆顶元素与最后元素交换，并调整剩余堆结构），最后返回堆顶元素即可。
```python []
class Solution:
    def findKthLargest(self, nums,k):
        res = self.heapsort(nums,len(nums),k)
        return res
    def adjust(self,nums,i,n):
        x = nums[i]
        k = 2*i+1
        while k<=n:
            if k<n and nums[k+1]>nums[k]:
                k += 1
            if x > nums[k]:
                break
            nums[(k+1)//2-1] = nums[k]
            k = 2*k+1
        nums[(k+1)//2-1] = x
    def heapsort(self,nums,n,k):
        for i in range(n//2-1,-1,-1):
            self.adjust(nums,i,n-1)
        for i in range(n-1,n-k,-1):
            nums[i],nums[0] = nums[0],nums[i]
            self.adjust(nums,0,i-1)
        return nums[0]
            