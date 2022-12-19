### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1_counter = collections.Counter(arr1)
        ans = []
        for i in arr2:
            counter = arr1_counter[i]
            ans += [i for j in range(counter)]
        temp = []
        for i in arr1:
            if i not in arr2:
                temp.append(i)
        temp = sorted(temp)
        return ans + temp
```