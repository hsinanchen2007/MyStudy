### 解题思路
最简单的方式是使用re，这里未采用re，采用多重判断。
lstrip:去除左边空格。

### 代码

```python3
class Solution:
    def myAtoi(self, strs: str) -> int:
        #最简单的方式是使用re，这里未采用re，采用多重判断
        strs=strs.lstrip()#去除左边的空格
        #special case:
        if strs=="":return 0#字符串为空：返回0
        if strs[0] not in '+-0123456789':return 0 #开始为非数字，则返回0
        if strs.isdigit():#若为正数，直接转换后返回
            if int(strs)<2**31:return int(strs)
            else:return 2**31-1#判断是否超界
        if strs[1:].isdigit():#若首字母为+/-，剩下字母组成正数
            if strs[0]=='-':#为负数
                if int(strs)>-2**31:return int(strs)#若为负数未超界直接转换返回
                else:return -2**31
            if strs[0]=='+':#为正数
                if int(strs)<2**31:return int(strs)#若为正数未超界直接转换返回
                else:return 2**31-1
        #截断数字
        numstr=''
        numstr=numstr+strs[0] if strs[0] in '+-0123456879' else ''
        for i in range(1,len(strs)):
            if strs[i] not in '0123456789':break
            numstr+=strs[i]
        if numstr.isdigit():
            if int(numstr)<2**31:return int(numstr)#若为正，直接转换后返回
            else:return 2**31-1
        if numstr[1:].isdigit():
            if numstr[0]=='-':
                if int(numstr)>-2**31:return int(numstr)#若为负数未超界直接转换返回
                else:return -2**31
            if numstr[0]=='+':
                if int(numstr)<2**31:return int(numstr)#若为正数未超界直接转换返回
                else:return 2**31-1
        else:return 0
```