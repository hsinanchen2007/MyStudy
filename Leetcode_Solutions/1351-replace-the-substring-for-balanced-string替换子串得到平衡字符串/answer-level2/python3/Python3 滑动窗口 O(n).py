# 经典滑动窗口题

## 思路：
1. 统计字符个数
1. 只考虑大于n // 4的字符，目标找到最短的子串将这些多的字符替换掉。
1. 窗口中s[l,r]就是子串candidate:
    1）如果子串里包含了足够多要替换的字符，则l += 1， 缩小考察范围；
    2）如果子串里需要换掉的字符不够，则r += 1，考察更多的字符；

### 举个栗子：
    ‘WQWRQQQW’
- 统计字典为counter = {W:3,Q:4,R:1}
- 只考虑出现次数大于 n // 4 = 2的字母：counter = {W:3,Q:4}
- 我们的目标是把字符串中多余的字母替换掉，即使得 counter_balanced = {W:2,Q:2,E:2,R:2}
- 开始时 l = r = 0，此时s[l,r] = 'W',那么此子串不足以将W和Q替换完，所以我们继续考察后面的字符串，r += 1
- 到了r = 4时，此时s[l,r] = 'WQWRQ'，那么可替换掉的W有两个，Q有两个，对比counter_balanced和counter
我们可以知道，其实我们只需要换掉一个W和两个Q。此时我们可以考虑缩小考察范围，以获得最小的子串，l += 1
- 直到l = 1时，此时s[l,r] = 'QWRQ'，我们就可以更新最小子串的长度。
- 当l移动到一定程度的时候，子串里的字母又不够替换了，此时我们再移动r。长此以往，就能得到最短替换子串了。

以下为具体实现：
```
class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        b = n // 4
        from collections import Counter
        counter = Counter(s)
        counter = {key:value for key,value in counter.items() if value > b}
        
        if not counter or n < 4:
            return 0
        rmove = True
        
        l,r = 0,0
        minlen = n
        
        while l <= r and r < n:
            
            if s[r] in counter and rmove:
                counter[s[r]] -= 1
            elif l > 0 and s[l - 1] in counter and not rmove:
                counter[s[l - 1]] += 1

            if {key:value for key,value in counter.items() if value > b}:
                r += 1
                rmove = True
            else:
                minlen = min(minlen, r - l + 1)
                l += 1
                rmove = False
                         
        return minlen
```
第一次写题解，写的也不咋简洁，望大佬多多指教。
