### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        #长度不够先排除
        if len(s)<k:
            return False
        
        #统计每个字母出现次数
        dic = collections.defaultdict(int)
        for c in s:
            dic[c]+=1
        jishu = 0
        oushu = 0
        for c in dic.values():
            if c%2!=0:
                jishu+=1
        if jishu>k:
            return False
        
        return True
```