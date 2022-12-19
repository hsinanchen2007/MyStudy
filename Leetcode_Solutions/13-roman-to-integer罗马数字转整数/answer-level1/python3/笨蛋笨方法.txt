### 解题思路1
实在想不到方法的话，大不了全部替换一边嘛！注意先替换组合型~

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        a = s.replace("IV", "4+").replace("IX", "9+").replace("XL", "40+").replace("XC", "90+").replace("CD", "400+").replace("CM", "900+")
        a = a.replace("I", "1+").replace("V", "5+").replace("X", "10+").replace("L", "50+")
        a = a.replace("C", "100+").replace("D", "500+").replace("M", "1000+")
        sum = eval(a[:-1])
        return sum

```

### 解题思路2
稍微观察一下，IV,IX等等组合都是某个数字与后面两个组合得到的，值相当于右边减去左边，所以有了第二个方法。

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dic = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        s_list = list(s)
        n = len(s_list)
        num = 0

        for i in range(n):
            if i != n-1:
                if dic[s_list[i]] < dic[s_list[i+1]]:
                    num += -dic[s_list[i]]
                else:
                    num += dic[s_list[i]]
            else:
                num += dic[s_list[i]]

        return num

```