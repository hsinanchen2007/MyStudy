### 遍历nums1，找满足条件的val 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/4d3b01d5ea1901c6b92025ce8b5a2ee588758f181eedfca38c42fa15bff85d19-image.png)
遍历nums1，如果在nums2中,加入结果。并在nums2中删除。
### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        rst=[]
        if nums1 and nums2:
            for i,val in enumerate(nums1):
                if val in nums2:
                    nums2.remove(val)
                    rst.append(val)
        return rst 
```

### 集合 解题思路

![image.png](https://pic.leetcode-cn.com/ecd04372f2cb4e15771e07e40a40831e688e968f8973433c2639a03c5cce54d5-image.png)
对nums1和nums2取合集，合集中的每一个元素计算在两个队列中的次数，取次数少的串放入结果中
### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        rst=[]
        for x in set(nums1) & set(nums2) :
            rst.extend(min(nums1.count(x),nums2.count(x))*[x])
        return rst 
```
### 排序后比较 解题思路

![image.png](https://pic.leetcode-cn.com/c023f36ece83d4ae6c624feb37aa4afeacc7fe99a5c69c1eaa36d98f8b717a53-image.png)

对nums1和nums2排序，
nums1[i]==nums2[j]，将该值加入结果。
如果不相等，将较小的数删除。有可能另一列头相等的数肯定在较小数那一列头的后面。
### 代码

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        rst=[]
        nums1.sort()
        nums2.sort()
        i=j=0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]==nums2[j]:
                rst.append(nums1[i])
                i=i+1
                j=j+1
            elif nums1[i]>nums2[j]:
                j=j+1
            else:
                i=i+1
        return rst 
```
