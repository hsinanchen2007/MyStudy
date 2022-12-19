### 解题思路
定义头指针`start`，尾指针`end`
如果头尾之和大于`target`，end减一
如果头尾之和小于`target`，start加一
否则，返回`[start+1, end+1]`

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        start, end = 0, len(numbers)-1
        while start < end:
            if numbers[start] + numbers[end] > target:
                end -= 1
            elif numbers[start] + numbers[end] < target:
                start += 1
            else:
                return [start+1, end+1]
```