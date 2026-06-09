# 题解
第一时间，想到的是哈希表
## 哈希

 1. 初试化哈希表$hash= \{\}$
 2. 遍历数组：
 	+ 若$nums[i]$不在$hash$中，则令$nums[i]$为key，1为value（随便什么都可以）。
 	+ 若已存在，则返回$True$
 
 3. 返回$False$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$，进行了一次遍历。
 - 空间复杂度：$O(n)$，借助$hash$存储过程。

### Python

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hash={}
        for i in range(len(nums)):
            if(nums[i] not in hash):
                hash[nums[i]]=1
            else:
                return True
        return False
```
## 排序
利用排序，若存在相邻元素相等，则返回$True$

### 复杂度分析
 - 时间复杂度：$O\left(nlog(n)\right)$，进行了一次遍历。
 - 空间复杂度：$O(1)$，借助$hash$存储过程。
### Python

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n=len(nums)
        if(n==0 or n==1):
            return False
        nums.sort()
        for i in range(1,n):
            if(nums[i]==nums[i-1]):
                return True
        return False
```