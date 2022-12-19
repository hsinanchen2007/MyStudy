
逆序后再处理
```python []
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if num1=='0' and num2=='0':
            return '0'
        num1=list(num1)
        num2=list(num2)
        if len(num1)>len(num2):
            num1,num2=num2,num1
        #逆  序
        num1=num1[::-1]
        num2=num2[::-1]
        #求最小长度 设置进位标志
        min_length=min(len(num1),len(num2))
        max_length=max(len(num1),len(num2))
        flag=0
        result=''
        for i in range(min_length):
            #设置该位相加和
            sum_=int(num1[i])+int(num2[i])+flag
            if sum_>=10:
                flag=1
                result=str(sum_%10)+result
            elif sum_<10:
                flag=0
                result=str(sum_)+result
        #较长字符串剩余部分遍历
        for i in range(min_length,max_length):
            sum_1=int(num2[i])+flag
            if sum_1>=10:
                flag=1
                result=str(sum_1%10)+result
            else:
                flag=0
                result=str(sum_1)+result
        if flag==1:
            result=str(1)+result
        return result
```

