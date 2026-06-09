### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        excel_dict = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8, 'I': 9, 'J': 10, 'K': 11, 'L': 12,'M': 13, 'N': 14,
                      'O': 15, 'P': 16, 'Q': 17, 'R': 18, 'S': 19, 'T': 20, 'U': 21, 'V': 22, 'W': 23, 'X': 24, 'Y': 25, 'Z': 26}
        res_int = 0
        index = 0
        for i in range(-1, -len(s)-1, -1):
            res_int += int(excel_dict[s[i]]) * 26 ** index
            index += 1

        return res_int
```