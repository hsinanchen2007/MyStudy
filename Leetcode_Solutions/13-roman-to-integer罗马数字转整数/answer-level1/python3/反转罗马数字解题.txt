### 解题思路
1、将罗马数字分为正常和特殊，存在字典中
2、将输入的罗马字符串反转
3、while循环获取罗马字符串，也是分为正常和特殊
4、特殊的就加特殊的值，正常的就加正常的值
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        base_dict = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        special_dict = {"IV":4,"IX":9,"XL":40,"XC":90,"CD":400,"CM":900}
        # 特殊的罗马数字I、X、C
        roman_reverse = s[::-1]
        n = 0
        i = 0
        while i < len(roman_reverse):
            roman_num = roman_reverse[i]
            roman_special_num = roman_reverse[i:i+2][::-1]
            if roman_special_num not in special_dict.keys():
                n += base_dict[roman_num]
                i += 1
            else:
                n += special_dict[roman_special_num]
                i += 2
        return n
```