### 解题思路
初始思路：运用长度为s1的滑窗对s2的子串进行检查，调用collections.Counter对s1计数，滑动过程中，对s2字串计数，循环过程中如果两个计数器相等，则返回True，否则最后返回False。
缺点：慢，如果s1很长的话会重复数很多次。

优化：维护两个个长为26的数组，一个是对s1的字符计数（保持不变），另一个是s2滑窗子串的字符计数，每一轮新的循环只更新新加入的字符计数和出窗字符的计数，减少重复计数过程。

### 代码

```python3
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if not s2:
            return False
        if not s1:
            return True
        
        if len(s1) > len(s2):
            return False
        
        l1, l2, a = [0] * 26, [0] * 26, ord('a')

        for i in range(len(s1)):
            l1[ord(s1[i]) - a] += 1
            l2[ord(s2[i]) - a] += 1
        
        if l1 == l2:
            return True
        
        for i in range(len(s1), len(s2)):
            l2[ord(s2[i]) - a] += 1
            l2[ord(s2[i - len(s1)]) - a] -= 1
            if l1 == l2:
                return True
        return False
```