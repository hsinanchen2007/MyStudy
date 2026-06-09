```python
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        dic_arr = []
        temp_arr = [0] * 26
        dic_arr.append(temp_arr[:])
        for st in s:
            temp_arr[ord(st) - 97] += 1
            dic_arr.append(temp_arr[:])
        res = []
        for i, j, k in queries:
            cnt = 0
            for t in range(26):
                if (dic_arr[j + 1][t] - dic_arr[i][t]) & 1 == 1:
                    cnt += 1
                    if cnt // 2 > k: break
            res.append(False if cnt // 2 > k else True)
        return res
```