
基于Python3的语言特性，可以很容易的想到将数字转为字符串，再原地反转这一思路，剩下的就是处理好边界问题和特殊情况，还有符号问题

采用分而治之的思想可以将这个问题分为3个小问题：

1. 检查边界
2. 处理符号
3. 原地反转

分别定义3个函数进行处理

1. 检查边界
```
    def check(num):
        if 2**31-1>= num >= -2**31:
            return num
        else:
            return 0
```

2. 处理符号
```
    def getsign(num):
        return 1 if num>=0 else -1
```

3. 原地反转
```
    def myrev(num):
        return int(str(num)[::-1]))

```


最终组合代码如下:

```
class Solution:
    def reverse(self, x: int) -> int:
        # 检查输入合法性
        x = self.check(x)

        # 处理特殊值
        if x == 0:
            return 0
        
        # 返转并添加符号
        ax = abs(x)
        rax = self.myrev(ax)
        return self.check(rax) * self.getsign(x)  # 检查输出
    
    def getsign(self, num):
        """ 获取正负符号 """
        return 1 if num>=0 else -1

    def check(self, num):
        """ 检查边界 """
        if 2**31-1>= num >= -2**31:
            return num
        else:
            return 0

    def myrev(self, num):
        """ 原地翻转 """
        return int(str(num)[::-1])
```
