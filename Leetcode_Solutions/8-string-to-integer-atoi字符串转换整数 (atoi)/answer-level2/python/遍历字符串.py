### 解题思路
遍历字符串，遇到空格则指向下一个位置，遇到'-'/'+'/数字则开始截取字符串，直到遇到非数字或到字符串末尾，如果截取到的字符串只是'-'/'+'，则返回0，否则转为数值，判断范围，输出数值。遇到其他字符则返回0。

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        index = 0
        for i in str:
            if(i ==' '):
                index +=1
                continue
            elif(i =='-' or i =='+' or i.isdigit()):
                tem = i
                index+=1
                while(index<len(str) and str[index].isdigit()):
                    tem = tem+str[index]
                    index+=1
                if(tem == '-' or tem=='+'):
                    return 0
                ans = int(tem)
                if(ans<-(2**31)):
                    ans = -(2**31)
                if(ans>2**31-1):
                    ans = 2**31-1
                return ans

            else:
                return 0
        return 0
```