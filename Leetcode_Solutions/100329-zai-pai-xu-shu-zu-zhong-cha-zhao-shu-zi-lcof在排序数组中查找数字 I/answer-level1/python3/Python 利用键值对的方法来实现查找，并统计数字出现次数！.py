
本题我们可以使用哈希映射来解决这个问题，把数值作为键(key)，把数值出现的次数（value）作为值。我们先遍历原数组建立哈希表，然后遍历哈希表找到key键与target相等的元素作为答案，如果找不到就返回0

```python
class Solution:
def search(self, nums: List[int], target: int) -> int:
        data = dict()
        for i in nums:
            data[i] = data.get(i,0) + 1
        result = 0
        for (key,value) in data.items():
            if key == target:
                result = max(result,value)
        return result
```
    