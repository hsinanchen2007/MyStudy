# 题解
看到本题，我第一时间想到了哈希表，利用哈希表保存元素出现的次数。


## 哈希表

 1. 特判，若数组中只有一个元素，直接返回
 2. 初试化$max\_count=n//2$，表示若出现次数大于$n//2$，则为众数。初始化哈希表$hash={}$
 3. 遍历数组：
 	+ 若$nums[i]$不在$hash$中，则存下来，键为$nums[i]$，值为$1$。
 	+ 若$nums[i]$在$hash$中，则令$nums[i]$对应值加一。
 		* 若$nums[i]$对应值大于$max\_count$，则返回$nums[i]$，为众数。
### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(n)$

### Python

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hash={}
        n=len(nums)
        if(n==1):
            return nums[0]
        max_count=n//2
        for i in range(n):
            if(nums[i] not in hash):
                hash[nums[i]]=1
            else:
                hash[nums[i]]+=1
                if(hash[nums[i]]>max_count):
                    return nums[i]
```

## 摩尔投票法
**众数出现的次数$>$其他数字出现次数之和**

 1. 初始化$res=0$，$count=0$
 2. 遍历数组：
 	+ 若$count==0$，则将$res$更新为$nums[i]$，并令$count=1$
 	+ 否则：
 		* 若$nums[i]==res$，令$count+=1$
 		* 若$nums[i]!=res$，令$count-=1$
 
 3. 若最终$count>0$，则返回$res$
 
 

### 复杂度分析

 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n=len(nums)
        res=0
        count=0
        for i in range(n):
            if(count==0):
                res=nums[i]
                count=1
            else:
                if(nums[i]==res):
                    count+=1
                else:
                    count-=1
        if(count>0):
            return res
```