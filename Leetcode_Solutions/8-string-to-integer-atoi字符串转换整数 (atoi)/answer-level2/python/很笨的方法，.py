### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/772e907160d4d627223146434d585f34936e86d871f0a3f49c16ab1101adc0a8-image.png)

笨蛋笨方法，直接转为list处理，根据有无符号分别处理

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        string = str.lstrip()
        str_list = list(string)
        num = []
        if str_list != "" and str_list:
            if str_list[0] == "-" or str_list[0] == "+":
                if len(str_list) > 1:
                    if str_list[1].isdigit():
                        num.append(str_list[0])
                        for a in str_list[1:]:
                            if a.isdigit():
                                num.append(a)
                            else:
                                break

            elif str_list[0].isdigit():
                num.append(str_list[0])
                for a in str_list[1:]:
                    if a.isdigit():
                        num.append(a)
                    else:
                        break

            numm = "".join(num).replace("+", "")
            if (numm.startswith('-') and numm[1:] or numm).isdigit():
                numm = int(numm)
                if numm > 2147483647:
                    numm = 2147483647
                if numm < -2147483648:
                    numm = -2147483648
            else:
                numm = 0
        else:
            numm = 0
        return numm
```