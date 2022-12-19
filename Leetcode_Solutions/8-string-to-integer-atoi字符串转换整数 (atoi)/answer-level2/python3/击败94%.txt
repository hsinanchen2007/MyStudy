```
class Solution:
    def myAtoi(self, str: str) -> int:
        str2 = str.strip()
        n1 = len(str2)
        tar1 = ""
        if n1 == 0:
            return(0)
        else:
            for i in range(n1):
                if str2[i].isdigit():
                    tar1 += str2[i]
                elif str2[i] == "+" or str2[i] == "-":
                    if tar1 == "":
                        tar1 += str2[i]
                    else:
                        break
                else:
                    break
        try:
            tar2 = int(tar1)
            if tar2 > 2 ** 31 - 1 or (-2)**31 > tar2:
                if 0 > tar2:
                    return((-2)**31)
                else:
                    return(2**31 -1)
            else:
                return(tar2)
        except ValueError:
            return(0)

```
此题的解法难点在于理清题目中可能存在的所有情况