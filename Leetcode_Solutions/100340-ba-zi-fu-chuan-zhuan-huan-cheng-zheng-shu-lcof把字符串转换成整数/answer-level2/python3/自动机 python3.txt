灵魂画手新作：
![image.png](https://pic.leetcode-cn.com/4574defb87820dca31689ffd1fe0dc8b8dffff441e38906209ee0a8bf8bb2e29-image.png)

一共五个状态：0-开始状态、1-刚刚读入一个空格、2-刚刚读入一个正负号、3-刚刚读入一个数字、4-结束。
举个例子，读完正负号后面能接什么呢？（也就是**状态2**能接受什输入呢？）
只能是数字。所以状态2只有一个合法输入。
其他状态同理。

代码部分：
```
class Solution:
    def strToInt(self, str: str) -> int:
        stat = [
            #  state 0 start
            {'space':1, 'sign':2, 'num':3},
            # state 1 space 
            {'space':1, 'sign':2, 'num':3},
            # state 2 sign
            {'num': 3},
            # state 3 num
            {'num':3, 'space':4, 'sign':4, 'others':4},
            # state 4 end
            {}
        ]
        statNow = 0
        numStr = ''
        for char in str:
            numStr += char

            # just for reading 
            if char == ' ':char = 'space'
            elif char in '+-':char = 'sign'      
            elif '0'<=char<='9': char = 'num'
            else: char = 'others'

            # wrong input
            if char not in stat[statNow]: return 0

            # state transition
            statNow = stat[statNow][char]
            
            if statNow == 4 : break
        if statNow not in [3,4]:return 0
        if statNow == 4:numStr = numStr[:-1]

        if int(numStr) <= -2147483648 : return -2147483648
        if int(numStr) >= 2147483647: return 2147483647
        return int(numStr) 
```
状态机，妙啊。
试图用英文写注释ing...
运行效率好像不高，不过这不是重点，重点是我终于会状态机解题了。（尽管是个easy题。


