### 解题思路
这一题是比较两个字符串中各个字符的个数的多少。

和 [299. 猜数字游戏](https://leetcode-cn.com/problems/bulls-and-cows/) 本质上是一样的。
也要注意其的进一步的引用。

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        num_str = [0]*26
        for x in magazine:
            num_str[ord(x)-ord('a')] += 1
        for x in ransomNote:
            num_str[ord(x)-ord('a')] -= 1
            if  num_str[ord(x)-ord('a')]<0:
                return False
        return True
```