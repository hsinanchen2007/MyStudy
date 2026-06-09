### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n=len(nums1)
        m=len(nums2)
        result=[]
        x,y=1,1
        while (m-y)!=-1 and (n-x)!=-1:
                    if nums2[m-y]>=nums1[n-x]:
                        result.insert(0,nums2[m-y])
                        y+=1
                    else:
                        result.insert(0,nums1[n-x])
                        x+=1
        if m-y==-1:
            result=nums1[0:n-x+1]+result
        if n-x==-1:
            result=nums2[0:m-y+1]+result
                                    
        if len(result)%2==0:
            length=len(result)//2
            mid=(result[length]+result[length-1])/2.0
        else:
            length=(len(result)+1)//2
            
            mid=float(result[length-1])
        return mid


            
            
```