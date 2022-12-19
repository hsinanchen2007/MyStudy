### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        if str == '':return 0
        str1 = str
        ans = 0
        i = 0
        #从非空开始
        while i < len(str1):
            if str1[i] == ' ':
                if i== len(str1) - 1:
                    return 0
                i+= 1
            else:
                break 
        str1 = str1[i:]
        
        #单独拿出来负号，结尾相乘
        temp = 1
        if len(str1) >1:
            if str1[0] == '-' :
                temp = -1
                str1 = str1[1:]
            elif str1[0] == '+':
                temp = 1
                str1 = str1[1:]
        elif len(str1) == 1 and (str1[0] == '-' or str1[0] == '+'):
            return 0
        #处理无效字符以后,例3.1415  答案为3
        i = 0
        while i < len(str1):
            if str1[i] not in ['1','2','3','4','5','6','7','8','9','0']:
                break
            else:
                i += 1
        str1 = str1[:i]
        # print(str1)

        #开始转数字
        k = 0  #10的k次方
        for i in range(len(str1)-1,-1,-1):
            if str1[i] not in ['1','2','3','4','5','6','7','8','9','0']:
                return 0
            # print(str1[i],10**k)
            a =  int(str1[i]) * (10**k)
            # print(a)
            ans += a
            k += 1
        result = temp*ans

        if result > 2 ** 31-1:
            return 2**31-1
        elif result < (-2)**31:
            return (-2)**31
        else:
            return result

```