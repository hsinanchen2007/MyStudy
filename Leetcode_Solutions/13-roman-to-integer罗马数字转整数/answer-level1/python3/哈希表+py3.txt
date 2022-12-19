### 解题思路
先转换为哈希表然后通过从后向前的哈希表检索来计算结果

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dict1 = {
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000,
            "IV":4,
            "IX":9,
            "XL":40,
            "XC":90,
            "CD":400,
            "CM":900,
            }
        i = len(s)-2
        j = len(s)
        ans = 0
        while j > 0:
                if s[i:j] in dict1:
                    ans += dict1[s[i:j]]
                    i-=2
                    j-=2
                else:
                    i+=1
                    ans += dict1[s[i:j]]
                    i-=2
                    j-=1
                    if i < 0:
                        i+=1
        return ans

```