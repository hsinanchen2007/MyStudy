### 解题思路

- 字符列表 转 整数列表
- 整数列表低位对应位置相加
- 对相加结果进行进位处理：反转以后即从低位开始处理进位，进位到下一位；
- 最后处理最后一位，看是否需要添1，最后记得反向
### 代码

```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        num1 = list(map(int,num1))
        num2 = list(map(int,num2))
        l1 = len(num1)
        l2 = len(num2)
        #低位对应位置相加
        if l1<=l2:
            num2[l2-l1:]=list(map(lambda x :x[0]+x[1] ,zip(num2[l2-l1:],num1[:]))) 
            num = num2[::-1]
        else:
            num1[l1-l2:]=list(map(lambda x :x[0]+x[1] ,zip(num1[l1-l2:],num2[:])))
            num = num1[::-1]
        #进位处理    
        for i in range(len(num)-1):
            if num[i]>=10:
                num[i]=num[i]%10
                num[i+1]+=1
        if num[-1]>=10:
            num[-1]=num[-1]%10
            num.append(1)
        return ''.join(map(str,num[::-1]))

```