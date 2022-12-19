
```
class Solution:
    def romanToInt(self, s: str) -> int:
        dict1 = {
            "IV":"4 ","IX":"9 ","XL":"40 ","XC":"90 ",
            "CD":"400 ","CM":"900 ",
        }
        dict2 = {
            "I": "1 ","V":"5 ","X":"10 ","L":"50 ","C":"100 ","D":"500 ","M":"1000 "
        }
        i = 0
        for key,value in dict1.items():
            s = s.replace(key,value)
        for key,value in dict2.items():
            s = s.replace(key,value)
        s = s.rstrip()
        s = s.split(" ")
        for k in s:
            i += int(k)
        return i
```
编写两个字典存储对应的键值对，两个字典分别为两个字符的罗马字母对应的值和一个字符的罗马字母对应的值，通过遍历字典中键值对的形式利用字符串替代功能将罗马字母翻译为对应的字符串形式（先翻译两个字符的罗马字母再翻译一个字符的罗马字母），再通过字符串的分割保存为列表的形式，遍历列表中的值进行整数转换后相加即可得原罗马字母对应的整数