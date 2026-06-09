![批注 2019-10-28 192343.png](https://pic.leetcode-cn.com/53380bd25678a8883e10e56cb0db6bf67e2ca4b2a1049ef2e099f0b8385fd081-%E6%89%B9%E6%B3%A8%202019-10-28%20192343.png)

```
    def merge(self, intervals):
        res=[]
        for cur in intervals:
            tmp=[]
            for pre in res:
                if pre[0]>cur[1] or pre[1]<cur[0]:
                    tmp.append(pre)
                    continue
                cur=[min(pre[0],cur[0]),max(pre[1],cur[1])]
            tmp.append(cur)
            res=tmp            
        return res
```
