### 解题思路
我的思路：无
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        dicts = {}
        for x in arr:
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1
        dicts_nums = {}
        for key in dicts:
            if dicts[key] not in dicts_nums:
                dicts_nums[dicts[key]] = 1
            else:
                return False
        return True
```