### 解题思路
对应一个字典和一个列表，然后循环目标数即可

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        str1 = ""
        dic = {1 :"I",4 : "IV", 5 : "V",9 : "IX", 10: "X",40 : "XL", 50 : "L",90 : "XC", 100 : "C", 400 : "CD", 500 : "D", 900 : "CM", 1000 : "M"}
        list1 = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        
        for i in range(len(list1)):
                while num >= list1[i]:
                    num -= list1[i]
                    str1 += dic[list1[i]]
                if num  ==  0:
                    break

        return str1
```