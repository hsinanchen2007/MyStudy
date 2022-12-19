### 思路：
用并查集找到所有可交换位置的集合，排序每个集合内的字符，再插回原字符串。

例如`s = "dcabfge"`, `pairs = [[0,3],[1,2],[0,2],[4,6]]`

那么可交换的集合有`[0,1,2,3]、[4,6]`

排序后的字符分别为`'abcd'`, `'ef'`

插回原字符串最终s = `"abcdegf"`

### 代码：
```python []
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: [int]) -> str:
        p = {i:i for i in range(len(s))}    #初始化并查集

        def f(x):
            if x != p[x]:
                p[x] = f(p[x])
            return p[x]
        
        for i, j in pairs:
            p[f(j)] = f(i)      
        #合并可交换位置
        d = collections.defaultdict(list)
        for i, j in enumerate(map(f, p)):
            d[j].append(i)
        #排序
        ans = list(s)
        for q in d.values():
            t = sorted(ans[i] for i in q)   
            for i, c in zip(sorted(q), t):
                ans[i] = c
        return ''.join(ans)
```

```javascript []
var smallestStringWithSwaps = function (s, pairs) {
    let p = []
    for (let i = 0; i < s.length; i++) {
        p[i] = i
    }
    function f(x) {
        if (x != p[x]) {
            p[x] = f(p[x])
        }
        return p[x]
    }
    for (let x of pairs) {
        p[f(x[1])] = f(x[0])
    }
    let arr = p.map(f)
    let d = {}
    for (let i = 0; i < arr.length; i++) {
        if (!(arr[i] in d)) {
            d[arr[i]] = []
        }
        d[arr[i]].push(i)
    }
    let ans = s.split('')
    for (let q in d) {
        let x = d[q].map(i => s[i])
        let t = x.sort((a, b) => a.localeCompare(b))
        let sq = d[q].sort((a, b) => a - b)
        for (let i = 0; i < t.length; i++) {
            ans[sq[i]] = t[i]
        }
    }
    return ans.join('')
};
```
