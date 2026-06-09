### 解题思路
ord('a') == 97
状态数组比状态字典更加高效
ix-len(p) 当前子窗口左边相邻索引
ix-len(p)+1 当前子窗口左边索引
### 代码

```python3
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ls, lp, res = [0]*26, [0]*26, [] # state array; 26 lower letter; transform to int-index
        for c in p:
            lp[ord(c)-ord('a')] += 1
        for ix in range(len(s)): # slide windows right index
            if ix-len(p)>=0: # when ix-len(p)<0 没到窗口大小
                ls[ord(s[ix-len(p)])-ord('a')] -= 1 # left out
            ls[ord(s[ix])-ord('a')] += 1 # right in # 复用子窗口结果
            if ls == lp:
                res.append(ix-len(p)+1) # get slide windows left index
        return res
```