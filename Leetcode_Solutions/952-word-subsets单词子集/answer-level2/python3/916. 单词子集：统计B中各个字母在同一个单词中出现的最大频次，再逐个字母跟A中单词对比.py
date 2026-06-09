详见注释：

```python []
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        ctB = collections.defaultdict(int)
        for b in B:
            ctb = collections.Counter(b)    #统计B单词里字母的频次
            for c in ctb:
                ctB[c] = max(ctB[c], ctb[c])#修改B里各个字母的最大频次
        def f(a):
            cta = collections.Counter(a)    #统计A单词里字母的频次
            for c in ctB:
                if ctB[c] > cta[c]:         #不匹配就返回错误
                    return False
            return True
        return [*filter(f, A)]              #过滤解包成列表
```
