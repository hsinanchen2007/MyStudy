### 解题思路
遍历一次数组，
用哈希表记录每个值的索引，如果得到前面有数可以和本数组合成target，就直接用哈希表获得前面的索引输出；如果没有，就把本次的值和索引记录到哈希表里面去。python用字典实现哈希表。

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        hashtable = {}
        key = []
        for i in range(0,len(nums)):
            if hashtable.get(target-nums[i])==None:
                hashtable[nums[i]] = i
                continue
            else:
                key.append(hashtable.get(target-nums[i]))
                key.append(i)
                return key
        return key
```