### 解题思路
此处撰写解题思路
No string 解答回环数判断，核心为10进制的数问题。任何数都可以表示为 十进制数的特点=10^2*k+10^1*j+10^0*l
that is the essence. 10进制数的表示方法，科学计数法。
                                       Remember that air is no man. 
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # num-1 == num-size
        # num-2 == num-size-1
        # 思路如此
        # 不用string
        # 如何获取高位数
        # 如何获取低位数
        # 1， 获取高位数
        # x = 120403 为例
        # 任何数都可以表示为 十进制数的特点=10^2*k+10^1*j+10^0*l
        # 获取1---> x / 100000 = 1 %10 = 1
        # 获取2---> x / 10000 = 12%10 = 2
        # 获取0---> x / 1000 = 120%10= 0
        # 无错误
        # 获取低位数 3 倒数第一位 x % 10^1 = 3 / 10^0 = 3
        # 依次为 0 倒数第二位 x % 10^2 = 3 /10^1 = 0
        # 可证成立
        # algorithm：
        # 1. 获取length 
        # 2. high = length， low = 1， 每次比较高低位 ，若==成立，low+=1 high -=1,while 退出条件为low > high,(可以包含单双数两种情况，具体证明略)
        y = x 
        # 不改变原有的参数，生成副本，用于别的用处（获取size）
        if x<0:
            return False
        if x<10:
            return True
        sum = 0
        while y//10!=0:
            # 例子y = 11, sum = 1
             sum+=1
             y = y//10
        # sum 为高位次幂
        # 
        high = sum
        low = 1
        print("hello", high, "end")
        while low <= high:
            # 获取高，
            left = (x // pow(10, high))%10
            right = (x % pow(10, low))// pow(10,low-1)
            print(left, right)
            if left != right:
                return False
            low += 1
            high -= 1
        return True


```