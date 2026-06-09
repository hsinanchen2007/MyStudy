### 解题思路
对每一种题设要求理解到位，按要求输出，if语句判断到底！！！

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:

        str = str.strip() # 去除首尾空格
        if str == "":  # 如果为空则返回0
            return 0
        first = str.split(" ")[0] # 只需要判断空格分隔的第一个字符串
        flag = '' # 存放标志位
        res = '' # 存放结果的字符串
        if  ord(first[0])>=ord("A"): # 如果首字是字母时
            return 0
        for j,char in enumerate(first):
            # 如果首字是正符号，则将其存到标志位
            if char in ["+","-"] :
                if j != 0:
                    break
                else:
                    flag = char
                    continue
            if ord(char) >=ord('0') and ord(char) <= ord('9'):
                res = ''.join([res,char])
            else:
                break
        # 将标志位转换为 +1 和 -1
        if flag:
            flg = int(''.join([flag,'1']))
        else:
            flg = 1
        # 对结果进行处理，满足题述要求 
        if res:
            if int(res)>=pow(2,31):
                res = pow(2,31)
                if flg>0:
                    return flg * (res-1)
                else:
                    return flg * res
            else:
                return int(res) * flg
        return 0
```