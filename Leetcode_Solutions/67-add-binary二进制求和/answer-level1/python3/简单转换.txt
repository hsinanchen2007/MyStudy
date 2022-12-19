方法一：
日常我们怎么算二进制，那么现在依然怎么算。

假如‘11’和‘1’，我们日常算肯定是逐位相加，然后判断是否需要进位。
那么现在我们可以先将其看为十进制相加得到num，然后用tmp作为进位，处理num的每一位。

示意如下：
num=str(11+1)='12'，tmp预设为0，result=''.
num[-1]=2在二进制需要进位，所以我们让result+='0',tmp=1;
num[-2]=1不需进位，但是tmp=1，因此result+='0',tmp=1；
循环完字符串num后我们还需要判断下tmp，若tmp=1，result+='1'。

最后返回result[::-1]。


具体代码为：
```
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        num = str(int(a)+int(b))
        tmp=0
        result=''
        for i in range(-1,-len(num)-1,-1):
            if num[i]=='2' and tmp!=1:
                tmp=1
                result+='0'
            else:
                if tmp==1:
                    if num[i]=='2':
                        tmp=1
                        result+='1'
                    elif num[i]=='1':
                        tmp=1
                        result+='0'
                    else:
                        result+='1'
                        tmp=0
                else:
                    result+=num[i]
        #判断首位是否要进位    
        if tmp==1:result+='1'
        return result[::-1]
```


方法二：
这是看别人的代码，用Python的bin函数
bin函数：bin(10)='0b1010'
所以代码为：
```
        a1=int('0b'+a,2)
        b1=int('0b'+b,2)
        c1=bin(a1+b1)[2:]        
        return c1
```
