### 解题思路
我们统计每个数字出现的次数，并保存在哈希表中。遍历哈希表，如果找到符合要求的数字，直接返回即可。

### 代码

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = collections.Counter(nums)
        for key,value in dic.items():
            if value > len(nums) / 2:
                return key
```
### 复杂度分析

- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$，使用了哈希表。