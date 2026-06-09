### 解题思路
1.首先我们需要知道我们有13种字符串可以用，从小到大分别是：M,CM,D,CD,C,XC,L,XL,X,IX,V,IV,I。
2.其次，同一个字符串可能多次出现，例如整数2000的话，对应于“MM”。
3.最后我们从最大的数开始判断，并且用while循环,执行两步：其一，改变num的值，其二，将字符加到新的字符串当中。

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        str1=""
        while num>=1000:
            num -= 1000
            str1 += "M"
        while num>=900:
            num -= 900
            str1 += "CM"
        while num>=500:
            num -= 500
            str1 += "D"
        while num>=400:
            num -= 400
            str1 += "CD"
        while num>=100:
            num -= 100
            str1 += "C"
        while num>=90:
            num -= 90
            str1 += "XC"
        while num>=50:
            num -= 50
            str1 += "L"
        while num>=40:
            num -= 40
            str1 += "XL"
        while num>=10:
            num -= 10
            str1 += "X"
        while num>=9:
            num -= 9
            str1 += "IX"
        while num>=5:
            num -= 5
            str1 += "V"
        while num>=4:
            num -= 4
            str1 += "IV"
        while num>=1:
            num -= 1
            str1 += "I"
        return str1
```