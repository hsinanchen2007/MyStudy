### 解题思路
后缀：指字符串中除了第一个字符以外，其余字符的全部尾部顺序组合。
![v2-00ecde0eb10f698e8a960fb532a85a09_720w.png](https://pic.leetcode-cn.com/d9694a1e62a71bec7781be61846641b3969390f90b8f6efc9957bb72526b41f5-v2-00ecde0eb10f698e8a960fb532a85a09_720w.png)

> [算法之字符串模式匹配](https://zhuanlan.zhihu.com/p/24649304)
### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        suffixs = set()
        for w in words:
            if len(w) < 2:
                continue
            for i in range(1, len(w)-1):
                suffixs.add(w[i:])
        longWords=set()
        for w in words:
            if w not in suffixs:
                longWords.add(w)
        return len('#'.join(longWords))+1
```