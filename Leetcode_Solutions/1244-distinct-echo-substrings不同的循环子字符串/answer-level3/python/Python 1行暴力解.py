假装是一行，
```
        # One-Line:
        return len(collections.Counter(text[L:R]for R in range(len(text)+1) for L in range(R%2,R,2)if text[L:(L+R)//2]==text[(L+R)//2:R]))
```

实际上是6行。
```
        # BruteForce:
        tmp = collections.defaultdict(int)
        for R in range(len(text)+1):
            for L in range(R%2,R,2):
                if text[L:(L+R)//2]==text[(L+R)//2:R]:
                    tmp[text[L:(L+R)//2]]+=1
        return len(tmp)
```



另外比赛用的是BFS，比赛完写了个Rolling Hash

, 居然都没有暴力法快，不献丑了。。。
```
# NULL
```

为了避免显得太水，附一个O(N^2/C)的答案，比暴力法稍稍快一点(900ms)：
```
        ords = [ord(c) for c in text]
        dic = collections.defaultdict(list)
        dst = collections.defaultdict(list)
        for i,c in enumerate(text):
            for j in dic[c]:
                dst[i-j].append(i)
            dic[c].append(i)
        ans = 0
        for LEN,d in dst.items():
            if len(d)<LEN:continue
            flag = 0
            end = LEN-1
            stored = set()
            for n in d:
                if flag!=n:
                    end = n+LEN-1
                flag = n+1
                if end ==n:
                    stored.add(text[n-LEN+1:n+1])
                    end+=1
            ans+=len(stored)
        return ans
```