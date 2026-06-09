![image.png](https://pic.leetcode-cn.com/f6152d3861e5405f1d2dc39c2e920cea62ae3b8fad39645bcb6b61ce4650c376-image.png)

和其他大佬不同的是我主要用的是元组化判断，单向BFS代码少一半，时间300ms左右，大概也有97%这样。

```
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if '0000' in deadends or target in deadends:
            return -1
        
        def f(a,b,c,d):     #生成下一个组合
            return [((a+1)%10,b,c,d),((a-1)%10,b,c,d),(a,(b+1)%10,c,d),(a,(b-1)%10,c,d),(a,b,(c+1)%10,d),(a,b,(c-1)%10,d),(a,b,c,(d+1)%10),(a,b,c,(d-1)%10)]
        
        ans=1

        ds={tuple(int(i) for i in c) for c in deadends}
        ser={(0,0,0,0)}

        dt=ds.copy()
        tar={tuple(int(c) for c in target)}

        while True:
            tmp=set()
            for a,b,c,d in ser:
                for j in f(a,b,c,d):
                    if j not in ds and j not in tmp:
                        if j in tar:
                            return ans
                        ds|={j}     #记录正向访问过的组合
                        tmp|={j}
            if not tmp:
                break
            ser=tmp
            ans+=1
            
            tmp=set()
            for a,b,c,d in tar:
                for j in f(a,b,c,d):
                    if j not in dt and j not in tmp:
                        if j in ser:
                            return ans
                        dt|={j}     #记录逆向访问过的组合
                        tmp|={j}
            if not tmp:
                break
            tar=tmp
            ans+=1
        
        return -1
```
