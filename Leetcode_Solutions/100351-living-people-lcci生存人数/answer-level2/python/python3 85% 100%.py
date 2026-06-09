### 解题思路
用字典记录有人数变化的年份。然后从1900统计到2000的人数，遍历过程中找最大年份。

### 代码

```python3
class Solution:
    def maxAliveYear(self, birth: List[int], death: List[int]) -> int:
        dic = collections.defaultdict(int)
        
        for c in birth:
            dic[c]+=1
        for c in death:
            dic[c+1]-=1
        
        maxn = 0
        cur =0
        res = -1
        for i in range(1900,2001):
            cur+=dic[i]
            if cur>maxn:
                res=i
                maxn = cur
                
        return res
```