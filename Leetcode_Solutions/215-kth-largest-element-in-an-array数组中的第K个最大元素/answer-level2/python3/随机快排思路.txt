朴素的快速排序方法在原数组基本有序的情况下是O(n^2)，在最后几个测试用例上出问题。
采用随机选取可尽力避免最糟情况。

这一次提交的结果是72ms,13.6MB

```
import random
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if len(nums)==1:
            return nums[0]
        e=random.randrange(0,len(nums))
        a=nums[e]
        c=1
        del nums[e]
        i=0
        L=[]
        R=[]
        flag=True
        while i<len(nums):
            if nums[i]>a:
                R.append(nums[i])
                if len(R)>=k:
                    flag=False
            elif flag:
                if nums[i]==a:
                    c+=1
                else:
                    L.append(nums[i])
            i+=1
        if k<=len(R):
            return self.findKthLargest(R,k)
        if k>len(R)+c:
            return self.findKthLargest(L,k-len(R)-c)
        return a
```