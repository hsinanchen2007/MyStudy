### 解题思路
此处撰写解题思路
简单来说，就是先排序，再查找。先对两个有序数组排序，每次取两个数组中最小值进行比较，较小的数组向后移动一个位置，当一个数组已经取完的时候，则将未取完的数组直接复制，即可。
### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        length1=len(nums1)
        length2=len(nums2)
        length=length1+length2
        a1=0
        a2=0
        res=[]
        Flag=False
        if length1==0 and length2!=0:
            return(nums2[int(length2/2)]+nums2[int(length2/2-1)])/2.0 if length2%2==0 else (nums2[int(length2/2)])*1.0
        elif length2==0 and length1!=0:
            return(nums1[int(length1/2)]+nums1[int(length1/2-1)])/2.0 if length1%2==0 else (nums1[int(length1/2)])*1.0

        for i in range(length):
            if nums1[a1]<nums2[a2]:
                tmp=nums1[a1]
                res.append(tmp)
                if a1==length1-1:
                    for j in range(length2-a2):
                        res.append(nums2[a2+j])
                    break
                if a1<length1-1:
                    a1+=1
            else:
                tmp=nums2[a2]
                res.append(tmp)
                if a2==length2-1:
                    for j in range(length1-a1):
                        res.append(nums1[a1+j])
                    break
                if a2<length2-1:
                    a2+=1
        if length%2==0:
            return(res[int(length/2)]+res[int(length/2-1)])/2.0
        else:
            return(res[int(length/2)])*1.0
        
```