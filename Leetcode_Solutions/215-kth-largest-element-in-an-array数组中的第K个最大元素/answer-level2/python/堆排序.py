### 解题思路
套用堆排序，只需要修改最后一步，不用排序所有，只需要排序最后k位。

### 代码

```python
class Solution(object):
    def findKthLargest(self, nums, k):
        def seft(lis,start,end):
            root = start
            while True:
                child = root*2+1
                if child>end:
                    break
                if child+1 <= end and lis[child]<lis[child+1]:
                    child += 1
                if lis[root] < lis[child]:
                    lis[root],lis[child] = lis[child],lis[root]
                    root = child
                else:
                    break
        start = (len(nums)//2)-1
        for i in range(start,-1,-1):
            seft(nums,i,len(nums)-1)
        for j in range(len(nums)-1,len(nums)-1-k,-1):
            nums[j],nums[0] = nums[0],nums[j]
            seft(nums,0,j-1)
        return nums[len(nums)-k]           
```