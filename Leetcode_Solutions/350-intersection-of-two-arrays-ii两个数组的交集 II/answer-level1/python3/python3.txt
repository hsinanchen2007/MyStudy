### 解题思路
先求出交集，然后选择交集中次数最少的添加进去

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        hash1=Counter(nums1)
        hash2=Counter(nums2)
        res=[]
        for i in (hash1.keys() & hash2.keys()):
            for _ in range(min(hash1[i],hash2[i])):
                res.append(i)
        print(res)
        return res

        

      
```