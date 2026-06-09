来个不一样的解法，利用双指针加eval()函数

# 思路：
用left=0，right标记第一个数字和最后一个数字出现的位置

首先strip()去掉左右的空格

然后判断第一个字符是不是正负号，是的话left置为1

判断left后一个字符是否为数字，不是直接返回0

遍历不断更新right，找到第一个不是数字的字符后break

用res=str[left:right+1]提取纯数字字符串

需要注意的是，可能数字全为0.所以用lstrip()将左边的0清除

最后利用eval()函数将双引号去除，并判断是否需要填正负号

注意一些细节就ok了

下面代码都写有注释，用时28ms时间复杂度o(n)
```python []
class Solution(object):
    def myAtoi(self, str):
        str=str.strip()#去除空格
        if str=="" :return 0;#特殊情况 str="0"
        left=0;right=0
        maxi=2147483647;mini=-2147483648#用于后面判断是否越界
        if str[0]=='+' or str[0]=='-': left=1#判断第一个字符是否为正负号
        if (left==1 and len(str)==1) or str[left]<'0' or str[left]>'9': return 0#注意特殊情况 str="+"
        for i in range(left,len(str)):#right移动到第一个不是数字的地方
            if str[i]>='0' and str[i]<='9':
                right=i
            else:
                break
        res=str[left:right+1].lstrip('0')#去除左边的0
        if len(res)==0:return 0#清除后可能没数字
        else :res=eval(res)#eval是个非常好用的函数，自行了解
        if left==1 and str[0]=='-':#判断正负
            res=-res
        if res>maxi: return maxi
        elif res<mini: return mini
        else :return res
            
        
        
```
