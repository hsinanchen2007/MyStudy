来凑个数。。。
按照加号或者减号切分，计算每部分的结果加起来
```py
class Solution:
    def calculate(self, s: str) -> int:
        res = []
        minus = [1]
        tmp_s = ""
        for char in s:
            if char == " ":
                continue
            elif char == "+" and tmp_s != "":
                res.append(tmp_s)
                tmp_s = ""
                minus.append(1)
            elif char == "-":
                if len(tmp_s) == 0:
                    minus = [-1]
                else:
                    minus.append(-1)
                    res.append(tmp_s)
                    tmp_s = ""
            else:
                tmp_s += char
        res.append(tmp_s)
        val = 0
        for idx, sub_s in enumerate(res):
            val += minus[idx] * self.cal_prod_div(sub_s)
        return val
                
    def cal_prod_div(self, s):
        res = 1
        tmp_s = ""
        last_cal = "*"
        for idx, char in enumerate(s):
            if char == "*" or char == "/" or idx == len(s) - 1:
                num = int(tmp_s) if idx != len(s) - 1 else int(tmp_s + char)
                if last_cal == "*":
                    res *= num
                elif last_cal == "/":
                    res //= num
                tmp_s = ""
                last_cal = char
            else:
                tmp_s += char
        return res
```