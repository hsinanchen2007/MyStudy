### 解题思路 正向
假设输入正确
从左到右（顺序）遍历字符串
那么：左边已经有I，那么再出现V 就说明表达数是4 所以
```
elif i == "V":
    if sums % 5 == 1:
        sums += 3
```
如果出现的是X，说明表达数是9 所以
```
elif i == "X": # 10
    if sums % 10 == 1:
        sums += 8
```
其他的以此类推
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        sums = 0
        for i in s:
            if i == "I":
                sums += 1
            elif i == "V":
                if sums % 5 == 1:
                    sums += 3
                else:
                    sums += 5
            elif i == "X": # 10
                if sums % 10 == 1:
                    sums += 8
                else:
                    sums += 10
            elif i == "L": # 50
                if sums % 50 == 10:
                    sums += 30
                else:
                    sums += 50
            elif i == "C": # 100
                if sums % 100 == 10:
                    sums += 80
                else:
                    sums += 100
            elif i == "D": # 500
                if sums % 500 == 100:
                    sums += 300
                else:
                    sums += 500
            elif i == "M": # 1000
                if sums % 1000 == 100:
                    sums += 800
                else:
                    sums += 1000
        return sums
```
### 解题思路 逆向
假设输入正确
从右到左（逆序）遍历字符串s
如果是"V" "L" "D" 直接加对应数值
如果是"I" "X" "C" "M" 并且分别不小于 "V" "L" "D" 则减去对应数值
### 代码
```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        sums = 0
        lenth = len(s)
        for i in range(lenth):
            if s[lenth-i-1] == "I":
                if sums >= 5:
                    sums -= 1
                else:
                    sums += 1
            elif s[lenth-i-1] == "V":
                sums += 5
            elif s[lenth-i-1] == "X":
                if sums >= 50:
                    sums -= 10
                else:
                    sums += 10
            elif s[lenth-i-1] == "L":
                sums += 50
            elif s[lenth-i-1] == "C":
                if sums >= 500:
                    sums -= 100
                else:
                    sums += 100
            elif s[lenth-i-1] == "D":
                sums += 500
            elif s[lenth-i-1] == "M":
                sums += 1000
        return sums
```

