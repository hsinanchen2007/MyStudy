
如果 [a b b a] 相似与 [a b b a]；则 [ac bd bd ac] 和两者都相似；
那么 set 之后长度都相同；
[a b b a] 与 [c b c b] 模式不同，则对应分量相加 [ac bb bc ab];
取 set 之后长度不同。


```
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        # 按照向量的观点，这两个词向量线性相关；a 和 b 线性相关则，a,b,a+b 也线性相关。
        p = list(pattern)
        s = str.split()
        
        if len(s)!=len(p):
            return False
        sp = [ x+y for x,y in zip(s,p)]
        return len(set(s))==len(set(p)) and len(set(s))==len(set(sp))
```
