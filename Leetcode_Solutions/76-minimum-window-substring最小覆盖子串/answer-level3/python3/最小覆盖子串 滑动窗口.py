### 解题思路
双指针, 一开始思路是正确的, 一个指针j先走直到满足要求, 之后另一个指针i再走不断缩小字符串.
后面没想到的是当缩小到不满足条件时i,j怎么走. 一开始错误的认为不满足条件时i应该直接跳到j处然后重新遍历, 实际上是当不满足条件时j往前走, 满足条件时i往前走
因为对包含字母没有顺序要求. 所以需要两个dict去map字母的count

### 代码
```
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import Counter, defaultdict
        counter, current = dict(Counter(t)), defaultdict(int)
        ls, lt = len(s), len(t)
        i = j = count = 0
        res = ''
        lres = float('inf')
        while j<ls:
            if s[j] in counter:
                current[s[j]] += 1
                if current[s[j]]<=counter[s[j]]: # 因为先+1,这里应该是<=
                    count += 1
            while count==lt:
                if j+1-i < lres:
                    res = s[i:j+1]
                    lres = j+1-i
                if s[i] in counter:
                    current[s[i]] -= 1
                    if current[s[i]]<counter[s[i]]: # 这里是<, 和上面做一下区分
                        count -= 1
                i += 1
            j += 1
        return res
```
再贴一个错误代码, 反省一下
```
if len(s)<len(t): return ''
        from collections import Counter, defaultdict
        dt, ds = dict(Counter(t)), defaultdict(int)
        i = j = ls = 0
        res, lt = '', len(t)
        while j<len(s):
            if s[j] in dt:
                ds[s[j]] += 1
                ls += 1
                while lt==ls: # 这个判断条件有问题, 正确的判断条件应该是ds中包含dt中的所有字符且每个字符的数量大于等于dt中的数量!
                    if s[i] in ds: 
                        res = s[i:j+1] if not res or len(res)>j-i+1 else res
                        ds[s[i]] -= 1
                        ls -= 1
                    i += 1
            j += 1
        return res 
```

所以应该改成用一个match去标记然后和len(t)比较, 只有某个字符的数量符合要求了才match++
```
char c1 = s[right];
    if (needs.count(c1)) {
        window[c1]++; // 加入 window
        if (window[c1] == needs[c1])
            // 字符 c1 的出现次数符合要求了
            match++;
    }
    right++;

    // window 中的字符串已符合 needs 的要求了
    while (match == needs.size()) {
        // 更新结果 res
        res = minLen(res, window);
        char c2 = s[left];
        if (needs.count(c2)) {
            window[c2]--; // 移出 window
            if (window[c2] < needs[c2])
                // 字符 c2 出现次数不再符合要求
                match--;
```