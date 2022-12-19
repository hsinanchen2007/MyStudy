# 题解
## 哈希
 1. 初试化哈希表$hash= \{\}$
 2. 遍历数组：
 	+ 若$nums[i]$不在$hash$中，则令$nums[i]$为key，value为当前的索引$i$。
 	+ 若已存在：
 		* 判断当前的索引和上一相同元素的索引差是否小于等于$k$，即$i-hash[nums[i]]<=k$。若满足，返回$True$。
 		* 将索引更新为当前索引，$hash[nums[i]]=i$
 
 3. 返回$False$


### 复杂度分析
 - 时间复杂度：$O\left(n\right)$，进行了一次遍历。
 - 空间复杂度：$O(n)$，借助$hash$存储过程。

### Python

```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hash={}
        for i in range(len(nums)):
            if(nums[i] not in hash):
                hash[nums[i]]=i
            else:
                if(i-hash[nums[i]]<=k):
                    return True
                else:
                    hash[nums[i]]=i
        return False
```
