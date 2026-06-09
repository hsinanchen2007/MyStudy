### 解题思路
我好弱，一点算法的样子都没有，都快成穷举了:(
主要是想给第一个数字/符号/字母一个标记
### 代码
```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        res = 0
        flag = 1
        n =  {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}
        first = [0,0,0]
        first_c = False
        first_flag = False
        first_num = False
        for char in str:
            if char == ' ':
                if first_c:
                    break
                else:
                    continue
            elif char in n:
                first_num = True
                first[1] = 1 if not first_c else first[1]
                res = res*10 + n[char] 
            elif char == '+':
                if not first_c:
                    first_flag = True
                    first[0] = 1 if first_flag and not first_c else first[0]
                else: break     
            elif char == '-':
                if not first_c:
                    first_flag = True
                    first[0] = 1 if first_flag and not first_c else first[0]
                    flag = -flag
                else:break
            else:
                break
            first_c = True if sum(first)==1 else False
        if first[0]==1:
            res = min(res*flag,(2**31)-1) if flag>0 else max(res*flag,-2**31)
            return res
        elif first[1]==1:
            res = min(res,(2**31)-1) if flag>0 else max(res,-2**31)
            return res
        else:
            return 0