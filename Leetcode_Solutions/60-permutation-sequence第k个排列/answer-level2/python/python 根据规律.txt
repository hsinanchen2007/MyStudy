```
        res = ""
        strs = [str(i) for i in range(1,n+1)]
        def jc(n):
            res = 1
            for i in range(1, n + 1):
                res *= i
            return res
        while n:
            sub = k // jc(n - 1)
            k = k % jc(n - 1)
            if k == 0:
                res += str(strs[sub-1])
                strs = strs[0:sub-1] + strs[sub:]
                strs.reverse()
                for item in strs:
                    res +=item
                break
            if k>0:
                res += str(strs[sub])
                strs = strs[0:sub] + strs[sub + 1:]
            n -= 1
        return res
```
