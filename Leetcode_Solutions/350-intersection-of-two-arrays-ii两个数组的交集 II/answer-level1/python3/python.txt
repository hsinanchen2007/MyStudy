### 解题思路

### 代码

```python3
class Solution:
    def intersect(self, nums1, nums2):
        num=[];
        x1=len(nums1);
        x2=len(nums2);
        i=0;j=0;
        while i<x1:
            while j<x2:
                if nums1[i]==nums2[j]:
                    num.append(nums1[i]);
                    del nums1[i];x1-=1;
                    del nums2[j];x2-=1;
                    j-=1;i-=1;
                    break;
                j+=1;
            i+=1;j=0;
        return num;
```