这个问题是最简单求两集合交集的升级版
不同之处是，同样的元素还有不同的次数，并且你还要考虑这个次数
对准这个关键点就有了如下代码

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = []
        a = collections.Counter(nums1)
        b = collections.Counter(nums2)
        s1 = set(nums1) 
        s2 = set(nums2)
        s3 = s1 & s2
        for i in s3:
            for v in range(min(a[i],b[i])):
                    d.append(i)    
        return d
    
        
```
