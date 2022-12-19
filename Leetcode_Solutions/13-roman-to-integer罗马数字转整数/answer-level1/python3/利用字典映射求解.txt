### 解题思路
常规字典映射+特殊字典映射
复杂度分析：
时间复杂度：O（n），空间复杂度：O（1）

### 代码

```python3
class Solution:
    map_dict = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
    }
    smap_dict = {
        "IV": 4,
        "IX": 9,
        "XL": 40,
        "XC": 90,
        "CD": 400,
        "CM": 900
    }
    skeys = "IXC"

    def romanToInt(self, s: str) -> int:
        trans_num = 0
        need_continue = False
        for i in range(len(s)):
            if need_continue:
                need_continue = False
                continue
            if s[i] in self.skeys:
                if i < len(s) - 1:
                    try:
                        trans_num += self.smap_dict[s[i:i+2]]
                    except KeyError as e:
                        trans_num += 0
                    else:
                        need_continue = True
                        continue
            trans_num += self.map_dict[s[i]]
        return trans_num
```