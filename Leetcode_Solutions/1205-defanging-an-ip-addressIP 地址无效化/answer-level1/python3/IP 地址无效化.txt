### 解题思路
遍历IP地址，若遇到分隔符，则在其两侧添加方括号。
其实也可以一行代码解决，用字符串的replace()方法，进行替换，但是执行效率不够高。

### 代码

```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        i = 0
        result =''
        l = len(address)
        while i <l:
            if address[i] =='.':
                result += '[' + address[i] + ']'
            else:
                result +=address[i]
            i +=1
        return result
       
```