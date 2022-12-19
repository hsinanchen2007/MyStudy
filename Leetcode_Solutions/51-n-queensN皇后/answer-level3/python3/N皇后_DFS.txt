
```python []
ans = []
y_valid, xy_sum_valid, xy_dif_valid = [True for _ in range(n)], [True for _ in range(2 * n - 1)], [True for _ in range(2 * n - 1)]  # state

def dfs(path: List[int]):
    if len(path) == n:
        ans.append(['.' * c + 'Q' + '.' * (n - c - 1) for c in path])
        return
    r = len(path)
    for c in range(n):
        if y_valid[c] and xy_sum_valid[r + c] and xy_dif_valid[r - c + n - 1]:
            y_valid[c], xy_sum_valid[r + c], xy_dif_valid[r - c + n - 1] = False, False, False
            dfs(path + [c])
            y_valid[c], xy_sum_valid[r + c], xy_dif_valid[r - c + n - 1] = True, True, True

dfs([])
return ans
```


