### 1.哈希表（使用额外空间）
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic = {}
        for i in nums1:
            if not dic.get(i):
                dic[i]=1
        new = []
        for i in nums2:
            if dic.get(i):
                new.append(i)
                dic[i] -= 1
        return new
```
### 2.哈希表（不使用额外空间）
```
相比于上面的方法，节省了new数组的空间
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums1 or not nums2:
            return []
        dic = {}
        for i in nums1:
            if not dic.get(i):
                dic[i]=1
        n = len(nums2)
        i,j = 0,n-1
        while i<j:
            if dic.get(nums2[i]):
                dic[nums2[i]] -= 1
                i += 1       
            else:
                nums2[i],nums2[j] = nums2[j],nums2[i]
                j -= 1
        if dic.get(nums2[i]):
            i += 1
        return nums2[0:i]
```

### 3.set函数求交集
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
```
### 4.暴力解法，时间复杂度比较高
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(i for i in nums1 if i in nums2))
```
