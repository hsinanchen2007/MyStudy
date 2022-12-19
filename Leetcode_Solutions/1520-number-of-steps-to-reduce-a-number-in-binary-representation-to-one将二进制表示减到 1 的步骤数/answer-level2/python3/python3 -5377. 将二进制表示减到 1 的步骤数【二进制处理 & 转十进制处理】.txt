### 解题思路
+ 转int再写不行，但我还没弄明白为啥不行
    【更新】
    我弄明白了，我用了`num = num/2`，返回值为浮点数，python默认17位小数的精度，自动四舍五入了
    改用`num = num//2`整数除法就好了
+ 直接对二进制数组进行操作
偶数时，最后一位是'0',除以2即去掉最后一位，整体右移一个单位
奇数时，二进制加法，注意首位进位的问题

### 代码
二进制直接处理
```python3
class Solution:
    def numSteps(self, s: str) -> int:
        tmp = 0
        while s != '1':
            if s[-1] == '0':
                s = s[:-1]
                tmp += 1
            else:
                tmp += 1
                ans = 1
                s = '0'+ s
                for i in range(len(s)-1,-1,-1):
                    if ans==1 and s[i]=='1':
                        s = s[:i]+'0'+s[i+1:]
                        ans = 1
                    elif ans==1 and s[i]=='0':
                        s = s[:i]+'1'+s[i+1:]
                        ans = 0
                    elif ans==0:
                        break
                if s[0] == '0':
                    s = s[1:]
        return tmp
```

转十进制处理
```python3
class Solution:
    def numSteps(self, s: str) -> int:
        s_ = '0b' + s
        num = int(s_, 2)
        res = 0
        while num != 1:
            if num % 2 == 0:
                num //= 2
            else:
                num += 1
            res += 1
        return res
```
