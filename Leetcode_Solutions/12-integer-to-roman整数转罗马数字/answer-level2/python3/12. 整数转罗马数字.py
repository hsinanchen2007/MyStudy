### 解题思路
此处撰写解题思路
采用递归
### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        res =""
        if num >=1000 and num//1000:
            return res+"M"*(num//1000)+self.intToRoman(num%1000)
        if num>=900 and num<1000:
            return res+"CM" +self.intToRoman(num%900)
        if num>=500 and num<900:
            return res+"D"+self.intToRoman(num%500)
        if num>=400 and num<500:
            return res+"CD"+self.intToRoman(num%400)
        if num>=100 and num<400:
            return res + "C"*(num//100)+self.intToRoman(num % 100)
        if num>=90 and num <100 :
            return res + "XC"+self.intToRoman(num % 90)
        if num>=50 and num <90 :
            return res + "L"+self.intToRoman(num % 50)
        if num>=40 and num<50:
            return res + "XL"+self.intToRoman(num % 40)
        if num>=10 and num <40 :
            return res + "X"*(num//10)+self.intToRoman(num % 10)
        if num>=9 and num<10:
            return res + "IX"+self.intToRoman(num % 9)
        if num >= 5 and num < 9:
            return res + "V"+self.intToRoman(num % 5)
        if num>=4 and num<5:
            return res + "IV"+self.intToRoman(num % 4)
        if num<4:
            return res+(num*"I")
```