### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n = len(s)
        #设置一个map
        occ = collections.defaultdict(int)
        ans = 0
        #从每一个i开始，往后找
        for i in range(n):
            exist = set()
            cur = ""
            for j in range(i, min(n, i + maxSize)):
                exist.add(s[j])
                if len(exist) > maxLetters:
                    break

                cur += s[j]
                #如果符合条件就计算。
                if j - i + 1 >= minSize:
                    occ[cur] += 1
                    ans = max(ans, occ[cur])
        return ans


```