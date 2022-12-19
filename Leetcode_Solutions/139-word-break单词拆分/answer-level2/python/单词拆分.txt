### 解题思路
用一个数组标记i位置是否是匹配点。若当前位置与前面所有是匹配点之间的单词之一在列表中，那么当前位置就是匹配点。

### 代码

```python3
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        l = len(s)
        flag = [True]
        for i in range(1,l+1):
            f = False
            for j,x in enumerate(flag):     #查询list中某个重复值出现的位置
                if x==True:
                    word = s[j:i]
                    if word in wordDict:
                        f = True
            flag.append(f)
        return flag[-1]
```