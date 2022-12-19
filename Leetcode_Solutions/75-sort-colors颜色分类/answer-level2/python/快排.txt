### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        self.sort(nums,0,len(nums)-1)
        return nums
    def quick(self,l,lo,u):
        key=l[lo]
        i=lo ;j=u
        while i<j:
            while i<j and l[j]>=key:
                j-=1
            l[i]=l[j]
            while i<j and l[i]<key:
                i+=1
            l[j]=l[i]
        l[i]=key
        return i
    def sort(self,l,i,j):
        if i>=j:return
        m=self.quick(l,i,j)
        self.sort(l,i,m-1)
        self.sort(l,m+1,j)
```