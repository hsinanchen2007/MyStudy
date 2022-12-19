### 解题思路
利用字典的特性,不知道这样算不算算法,还是说是api, 时间44ms, 83.07%,内存14.3M,59%

### 代码

```python3
class Solution:
    def frequencySort(self, s: str) -> str:
        if not s:
            return ""
        storage = {}
        for i in s:
            if i not in storage:
                storage[i] = 1
            else:
                storage[i] += 1
        s = ''
        count_list = list(storage.values())
        max_count = max(count_list)
        while max(storage.values()) > 1:
            s += list(storage.keys())[list(storage.values()).index(max_count)] * max(storage.values())
            del storage[s[-1]]
            if storage:
                max_count = max(list(storage.values()))
            else:
                break
        s += ''.join(list(storage.keys()))
        return s
```