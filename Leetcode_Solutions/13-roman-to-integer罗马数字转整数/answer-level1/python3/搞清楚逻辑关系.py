### 解题思路
    这道题目主要是要求理解，就是罗马数字转整数的过程中，一般都是大的字母在前，小的字母在后，如果有小的数字在前面，那么就用后面一个大的字母减去这个小的字母。理解了就很好做了。
    使用一个字典，将字母和整数对应起来，然后在所给罗马数字长度内遍历处理。

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dict = {"I": 1, "V": 5, "X": 10, "L":50, "C": 100, "D": 500, "M": 1000 }
        ans = 0
        for i in range(len(s)):
            if i<len(s)-1 and dict[s[i]]<dict[s[i+1]]:
                ans-=dict[s[i]]
            else:
                ans+=dict[s[i]]
        return ans
```