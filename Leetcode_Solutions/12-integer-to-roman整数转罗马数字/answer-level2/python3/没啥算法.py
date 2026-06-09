### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        Roman_dict = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        Roman = ''
        for key in Roman_dict:
            n = num // Roman_dict[key]
            num = num - n*Roman_dict[key]
            Roman += n*key
        return Roman
```