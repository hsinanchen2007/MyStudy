执行用时 :
28 ms, 在所有 Python 提交中击败了99.88%的用户
内存消耗 :
12.2 MB, 在所有 Python 提交中击败了5.11%的用户

可重背包裸题
要保存方案也太暴力了
不过跑得超快

```python []
        N = len(candidates)
        
        M = target+1
        
        Ans = M * [0]
        for i in range(M):
            Ans[i] = list()
        
        Ans[0].append([])
        for i in range(N):
            for j in range(target-candidates[i]+1):
                for v in Ans[j]:
                    w = list(v)
                    w.append(candidates[i])
                    Ans[j+candidates[i]].append(w)
        
        return Ans[target]
```


