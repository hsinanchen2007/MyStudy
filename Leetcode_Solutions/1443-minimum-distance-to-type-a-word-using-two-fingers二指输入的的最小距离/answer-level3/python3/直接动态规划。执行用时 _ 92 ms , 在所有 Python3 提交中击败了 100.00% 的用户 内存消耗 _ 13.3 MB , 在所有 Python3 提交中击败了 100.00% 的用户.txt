### 解题思路
直接动态规划
两根手指，一根在前，一根在后，last记录前一根手指的字母，字典cur记录前手指在last时，后手指在各个字母的最小移动距离。当一个新字母ch进来时，分两种情况：（1）前手指移到ch上，（2）后手指移到ch。分别计算两种情况后，得到下一阶段的状态cur，即前手指在ch上，后手指在各个字母上的最小距离

### 代码

```python3
class Solution:
    def minimumDistance(self, word: str) -> int:
        import functools
        @functools.lru_cache(None)
        def get(a,b):
            if not a or a == b:
                return 0
            na, nb = ord(a)-ord('A'), ord(b)-ord('A')
            x1,y1 = na//6, na%6
            x2,y2 = nb//6, nb%6
            return abs(x1-x2)+abs(y1-y2)
        cur = {'':0}#状态字典：后手指在各个字母上时的最小距离
        last = word[0] #前手指的字母
        for ch in word[1:]:
            if ch == last:
                continue
            num = get(last,ch) #前手指字母到新字母的距离
            to = float('inf')
            for k,v in cur.items():
                to = min(to,v+get(k,ch)) #前手指不动，后手指移到新字母
                cur[k] += num #后手指不动，前手指移到新字母
            if last not in cur or to < cur[last]:
                cur[last] = to #前手指变后手指
            last = ch #前手指移到新字母
        return min(cur.values())
            
            
```