### 解题思路
这个算法惊艳到我了，我一直认为能够完全用纯数学解决的算法才是完美算法，这个解法我没想到，偷师！
其实运行效果这么差，一个是Python本身的问题，再就是gcd的计算问题了，同样的实现方法，用c写效果会好一点

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        candidate_len = math.gcd(len(str1), len(str2))
        candidate = str1[: candidate_len]
        if str1 + str2 == str2 + str1:
            return candidate
        return ''
```