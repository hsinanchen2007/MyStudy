![SharedScreenshot.jpg](https://pic.leetcode-cn.com/a40bff1e3f67bd7ed7d997c2dba8faa041235c1287f99dbdf4d73e06b558a8b1-SharedScreenshot.jpg)

写3个简单例子，就用数学题作答格式写233：

一、
- 当s = DCLXVI时
- ∵ I=1，V=5，X=10，L=50，C=100，D=500
- ∴  s = DCLXVI = D+'C+L+X+V+I = 500+100+50+10+5+1 = 666

二、


- 当s = XIV时
- ∵ I=1，V=5，X=10
- ∴  s = XIV = (X+I+V)-I×2 = (10+1+5)-1×2 = 14

三、

- 当s = CXLIV时
- ∵ I=1，V=5，X=10，L=50，C=100
- ∴ s = CXLIV = (C+X+L)-X×2+(I+V)-I×2 = (100+10+50)-10×2+(1+5)-1×2 = 144


简而言之下面一段代码的思路就是：
将所有的罗马数字进行相加，且再加一个判断机制：
if 当第N-1位数大于第N位数时，减去第N-1位数的两倍



```python []

class Solution:
    def romanToInt(self, s: str) -> int:
        num_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        numed, nums = 0, 0
        for x in s:
            num = num_dict[x]
            if numed is 0:
                numed = num
            elif num <= nums:
                numed += num
            else:
                numed = numed+num-nums*2
            nums = num
        return numed
```


1. num ：当前数字 （当前正在被遍历的数字num = num_dict[x]）
2. nums ：上一位数字
3. numed ：当前数字之前的所有数字的和
