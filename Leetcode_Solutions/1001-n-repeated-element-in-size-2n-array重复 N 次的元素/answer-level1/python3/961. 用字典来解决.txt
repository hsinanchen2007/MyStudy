### 解题思路
字典统计出现频次，然后再到字典中提出来。

### 代码

```python3
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        n = len(A) / 2

        A_list = {}
        for item in A:
            if item in A_list.keys():
                A_list[item] += 1
            else:
                A_list[item] = 1

        for key in A_list.keys():
            if A_list[key] == n:
                return key
```