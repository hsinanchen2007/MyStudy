将字符按字符数排序。
如果最多的字符占了半数以上，返回空，
如果总字符数是偶数，将排序后的字符分为前后两半，交叉得出结果
如果为奇数，将前后两半交叉，再加上最中间的字符。


```python []
class Solution:
    def reorganizeString(self, S: str) -> str:

        lst = sorted(sorted(S), key=lambda x: S.count(x), reverse=True)
        n = int(len(S) / 2 + 0.5)  # 奇数位数时取中间右边一位

        if lst[0] == lst[n]:  # 最多的字符超过半数
            return ''
        else:
            return ''.join(j for i in zip(lst, lst[n:]) for j in i) + ['', lst[n - 1]][len(S) % 2]

```



常规版：

'''
```
class Solution:
    def reorganizeString(self, S: str) -> str:
        
        s=sorted(S)
        count=collections.Counter(S)
        s.sort(key=count.get)
        n=len(s)//2
        if s[n-1]==s[-1]:
            return ''
        
        a,b=s[:n],s[n:]
        for i in range(len(b)):
            s[i*2]=b[i]
        for i in range(len(a)):
            s[i*2+1]=a[i]
            
        return ''.join(s)
```
