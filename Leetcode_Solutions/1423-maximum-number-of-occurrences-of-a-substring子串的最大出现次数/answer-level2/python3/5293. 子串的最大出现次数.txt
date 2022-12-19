### 解题思路
分享一种写法，条件统计

### 代码

```python []
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        return max(
            collections.Counter(
                s[i: i + minSize] 
                for i in range(len(s) - minSize + 1) 
                if len({*s[i: i + minSize]}) <= maxLetters
            ).values(), 
            default=0
        )

```
![image.png](https://pic.leetcode-cn.com/e42a84b0ff614aef39879ef1571148a14e8fabd06fd8e208e02e0efa0c6e5984-image.png)
