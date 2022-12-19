### 解题思路
要替换的值，是包含了超出平均值字母的数量的子串
找到哪些字母超出了平均值，将思路转换为包含这些超出字母个数的 最短子串， 
counter 代表超出数量的字母多出的个数
windows 代表当前滑动窗口超出数量的字母的个数
一但windows满足了counter，那么就可以计算当前的窗口长度，并且缩短窗口并看是否满足条件
total 代表的是当前窗口还差多少字母满足条件
### 代码

```python3
class Solution:
    def balancedString(self, s: str) -> int:
        b = len(s)//4
        from collections import Counter
        counter = Counter(s)
        # 超出数量的字母个数
        counter = {key:value-b for key,value in counter.items() if value > b}
        # 总共超出了total个
        total = 0
        windows = {}
        for key,value in counter.items():
            total += value
            windows[key] = 0
        if total ==0 :
            return 0
        i = 0
        res = len(s)
        for j in range(len(s)):
            if s[j] in counter:
                if windows[s[j]] < counter[s[j]]:
                    total -= 1
                windows[s[j]]  += 1
            while total == 0:
                res = min(res,j-i+1)
                if s[i] in counter:
                    if windows[s[i]] <= counter[s[i]]:
                        total += 1
                    windows[s[i]] -= 1
                i += 1
        return res
                




```