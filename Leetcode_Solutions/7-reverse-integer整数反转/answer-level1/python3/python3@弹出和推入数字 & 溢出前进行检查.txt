给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。这题难度不大很很适合新手练手。

## 暴力法：
好像这题也不存在什么暴力法的，只是用简单的思路来处理一下：
直接来：

```python
 def reverse_force(self, x: int) -> int:
        if -10 < x < 10:
            return x
        str_x = str(x)
        if str_x[0] != "-":
            str_x = str_x[::-1]
            x = int(str_x)
        else:
            str_x = str_x[:0:-1]
            x = int(str_x)
            x = -x
        return x if -2147483648 < x < 2147483647 else 0
```
运行结果，效果还是 不错的
```css
leetcode 网页提交：
执行用时 :48 ms, 在所有 Python3 提交中击败了30.26%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了5.44% 的用户

vscode插件提交：
1032/1032 cases passed (32 ms)
Your runtime beats 89.8 % of python3 submissions
Your memory usage beats 5.44 % of python3 submissions (13.7 MB)
```
## 优化解
我们可以一次构建反转整数的一位数字。在这样做的时候，我们可以预先检查向原整数附加另一位数字是否会导致溢出。
反转整数的方法可以与反转字符串进行类比。

我们想重复“弹出” x 的最后一位数字，并将它“推入”到 res 的后面。最后，res 将与 x 相反。

优化解：
时间复杂度：O(log(x))，x中大约有log10(x) 位数字。
空间复杂度：O(1)
```python
def reverse_better(
        self, 
        x: int) -> int:
       
        
        y, res = abs(x), 0
        # 则其数值范围为 [−2^31,  2^31 − 1]
        boundry = (1<<31) -1 if x>0 else 1<<31
        while y != 0:
            res = res*10 +y%10
            if res > boundry :
                return 0
            y //=10
        return res if x >0 else -res
```

这题没有考什么深的东西，不过可以复习一下python的字符运算语法：

复习一下python的位运算符：
- (a & b) 
按位与运算符：参与运算的两个值,如果两个相应位都为1,则该位的结果为1,否则为0	
输出结果 12 ，二进制解释： 0000 1100

- (a | b) 
按位或运算符：只要对应的二个二进位有一个为1时，结果位就为1。	
输出结果 61 ，二进制解释： 0011 1101

- (a ^ b) 
按位异或运算符：当两对应的二进位相异时，结果为1	
输出结果 49 ，二进制解释： 0011 0001

- (~a ) 
按位取反运算符：对数据的每个二进制位取反,即把1变为0,把0变为1 。~x 类似于 -x-1	
输出结果 -61 ，二进制解释： 1100 0011，在一个有符号二进制数的补码形式。

- a << 2 	
左移动运算符：运算数的各二进位全部左移若干位，由 << 右边的数字指定了移动的位数，高位丢弃，低位补0。
输出结果 240 ，二进制解释： 1111 0000

- a >> 2 
右移动运算符：把">>"左边的运算数的各二进位全部右移若干位，>> 右边的数字指定了移动的位数	
输出结果 15 ，二进制解释： 0000 1111


python赋值运算符：
- *=	乘法赋值运算符	c *= a 等效于 c = c * a
- /=	除法赋值运算符	c /= a 等效于 c = c / a
- %=	取模赋值运算符	c %= a 等效于 c = c % a
- **=	幂赋值运算符	c **= a 等效于 c = c ** a
- //=	取整除赋值运算符	c //= a 等效于 c = c // a

运行结果：

```css
Your runtime beats 95.84 % of python3 submissions
Your memory usage beats 99.88 % of python3 submissions (12.7 MB)
```

[源码储存在github上，欢迎来提bug哦！-点击访问](https://github.com/Freen247/leetcode)
如果觉得不错请给我一个star谢谢了[Stray_Camel(＾Ｕ＾)ノ~ＹＯ](https://boywithacoin.cn/ "https://boywithacoin.cn/")

