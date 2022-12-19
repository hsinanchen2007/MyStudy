### 解题思路
没什么技巧，理清所有可能就完事，个人觉得自己写的很小学生！

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        str1 = str.lstrip()
        if str1 == '':
            return (0)
        if str1[0] in {'-','+'}:
            for i in range(1,len(str1)):
                if str1[1]  not in {'0','1','2','3','4','5','6','7','8','9'}:
                    return (0)
                elif str1[i] not in {'0','1','2','3','4','5','6','7','8','9'}:
                    s = str1[:i]
                    s0 = int(s)
                    if s0 > 2**31-1:
                        return (2**31-1)
                    if s0 < -2**31:
                        return (-2**31)
                    else:
                        return (s0)
            if str1[len(str1)-1] in {'0','1','2','3','4','5','6','7','8','9'}:
                s0 = int(str1)
                if s0 > 2**31-1:
                    return (2**31-1)
                if s0 < -2**31:
                    return (-2**31)
                else:
                    return (s0)   
        if str1[0] in {'0','1','2','3','4','5','6','7','8','9'}:
            for i in range(1,len(str1)):
                if str1[i] not in {'0','1','2','3','4','5','6','7','8','9'}:
                    s = str1[:i]
                    s0 = int(s)
                    if s0 > 2**31-1:
                        return (2**31-1)
                    if s0 < -2**31:
                        return (-2**31)
                    else:
                        return (s0)
            if str1[len(str1)-1] in {'0','1','2','3','4','5','6','7','8','9'}:
                s0 = int(str1)
                if s0 > 2**31-1:
                    return (2**31-1)
                if s0 < -2**31:
                    return (-2**31)
                else:
                    return (s0)          
        else:
            return (0)

            


        

```