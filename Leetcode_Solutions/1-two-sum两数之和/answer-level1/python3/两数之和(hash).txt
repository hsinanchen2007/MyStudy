### 解题思路
暴力破解需要将两个数逐一对比，一般这种情况我们都可以用**hash table进行空间换时间**
>python可以用字典来表示hash table
#hash table的键即数字的大小num，而每个结点的值则是数字对应的位置idx

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash={}
        for idx, num in enumerate(nums):
            if target - num in hash:
                return [hash[target - num], idx]
            else:
                hash[num] = idx
        return None
```