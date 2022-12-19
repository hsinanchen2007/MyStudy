# 题解
1. 定义一个栈stock，开始依次迭代字符串
2. 迭代期间，记录连续的数字tmp_c及字母串tmp_s，遇到'['或数字结束或字母结束则入栈
3. 遇到']'则开始依次出栈，直到遇到'['停止while循环
4. 出栈期间，先记录栈顶的数据cs，然后判断当前的数据，如果为数字，则相乘，如果为字母，则相加
5. 退出循环后，这时栈顶一定是'['，先pop一次，然后再押入cs
6. 迭代结束后，stock里存储的就只有字符串了，先拼接stock，再加上tmp_s（用于cover输入以字母结尾的情况）

# 执行结果

执行用时 : 36 ms, 在所有 Python3 提交中击败了98.78%的用户   
内存消耗 : 13 MB, 在所有 Python3 提交中击败了96.05%的用户

# 代码

```
class Solution:
    def decodeString(self, s: str) -> str:
        stock = []
        tmp_c, tmp_s = '', ''
        for i in s:
            if i.isdigit():
                tmp_c += i
                if tmp_s:
                    stock.append(tmp_s)
                    tmp_s = ''
            if i == '[':
                stock.append('[')
                stock.append(int(tmp_c))
                tmp_c = ''
            if i.isalpha():
                tmp_s += i
            if i == ']':
                if tmp_s:
                    stock.append(tmp_s)
                    tmp_s = ''
                cs = ''
                while stock and stock[-1]!='[':
                    tmp = stock.pop()
                    if cs == '':
                        cs = tmp
                    else:
                        if isinstance(tmp, int):
                            cs = tmp * cs
                        if isinstance(tmp, str):
                            cs = tmp+cs
                stock.pop()
                stock.append(cs)
                    
        return ''.join(stock) + tmp_s
                
        
```
