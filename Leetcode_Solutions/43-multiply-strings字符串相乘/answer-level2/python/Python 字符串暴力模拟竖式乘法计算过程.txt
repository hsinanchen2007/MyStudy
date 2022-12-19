## 前言
没有做过上一题的朋友建议先把 [上一题 415](https://leetcode-cn.com/problems/add-strings/) 做掉，

__本题是上一题的升级版__，区别在于 415 是求两个字符串的和，而43是求两个字符串的乘积。

## 竖式乘法
我们先来简单回顾一下小学老师教过的列竖式求乘法的过程：

如下图所示，两个数M和N相乘的结果可以由 __M 乘上 N 的每一位数的和得到__。

举例 `123 * 45 = 123 * 5 + 123 *40 = 615 + 4920 = 5535`

![图片1.png](https://pic.leetcode-cn.com/41cfd0b1d235e669eeb090ec5eec24560440e4d34ec27c021773b96f5fc6cfac-%E5%9B%BE%E7%89%871.png){:width="140px"}
{:align="center"}


## 本题分析
字符串的乘法也可以由列竖式计算的方法得到：

1. 让`num1` 依次乘上 `num2` 的每一位的和
2. 把第一步里得到的所有和累加在一起，就可以得到 `num1 * num2` 的结果。

有了上面的分析，可以得到下面的主函数：
```Python []
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == "0" or num2 == "0": #处理特殊情况
            return "0"
        
        l1, l2 = len(num1), len(num2) 
        if l1 < l2: 
            num1, num2 = num2, num1 #保障num1始终比num2长， 个人习惯
            l1, l2 = l2, l1
            
        num2 = num2[::-1] #注意要倒过来乘，方便进位
        res = "0"
        for i, digit in enumerate(num2):
            tmp = self.StringMultiplyDigit(num1, int(digit)) + "0" * i #计算num1和num2的当前位的乘积
            res = self.StringPlusString(res, tmp) #计算res和tmp的和

        return res
```

搭好了骨架之后，接下来就是实现 __辅助函数__ 的功能， 辅助函数有三个：

第一个函数是为了计算一个字符串和一个整数的乘积：

__核心思路__ 是：
1. 开一个数组 `res`, `res[i] = int(string[i]) * n`
2. 乘完之后再调用第二个辅助函数处理 `res` 里的进位
3. 最后把 `res` 转成字符串返回


```Python []
    def StringMultiplyDigit(self,string, n):
        #这个函数的功能是：计算一个字符串和一个整数的乘积，返回字符串
        #举例：输入为 "123", 3， 返回"369"
        s = string[::-1]
        res = []
        for i, char in enumerate(s):
            num = int(char)
            res.append(num * n)
        res = self.CarrySolver(res)
        res = res[::-1]
        return "".join(str(x) for x in res)
```
第二个函数为了处理乘法结果里的进位：

思路：

把每一位上超过 10 的部分都向后进位，

注意处理最后一位进位时数组需要 append 一下，否则会 __下标越界__ 。
```Python []
    def CarrySolver(self, nums):  
        #这个函数的功能是：将输入的数组中的每一位处理好进位
        #举例：输入[15, 27, 12], 返回[5, 8, 4, 1]
        i = 0
        while i < len(nums):
            if nums[i] >= 10:
                carrier = nums[i] // 10
                if i == len(nums) - 1:
                    nums.append(carrier)
                else:
                    nums[i + 1] += carrier
                nums[i] %= 10
            i += 1
```
第三个函数为了把两个字符串加在一起：

思路：跟第一个辅助函数类似，但更简单，

直接每一位加在一起然后再调用第二个辅助函数处理进位。

PS：[第415题](https://leetcode-cn.com/problems/add-strings/) 就是要写这个函数
```Python []
 def StringPlusString(self, s1, s2):
        #这个函数的功能是：计算两个字符串的和。 
        #举例：输入为“123”， “456”, 返回为"579"
        #PS：LeetCode415题就是要写这个函数
        l1, l2 = len(s1), len(s2)
        if l1 < l2:
            s1, s2 = s2, s1
            l1, l2 = l2, l1
        s1 = [int(x) for x in s1]
        s2 = [int(x) for x in s2]
        s1, s2 = s1[::-1], s2[::-1]
        for i, digit in enumerate(s2):
            s1[i] += s2[i]
            
        s1 = self.CarrySolver(s1)
        s1 = s1[::-1]
        return "".join(str(x) for x in s1)
```

## 所有代码
```Python []
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == "0" or num2 == "0": #处理特殊情况
            return "0"
        
        l1, l2 = len(num1), len(num2) 
        if l1 < l2: 
            num1, num2 = num2, num1 #保障num1始终比num2大
            l1, l2 = l2, l1
            
        num2 = num2[::-1]
        res = "0"
        for i, digit in enumerate(num2):
            tmp = self.StringMultiplyDigit(num1, int(digit)) + "0" * i #计算num1和num2的当前位的乘积
            res = self.StringPlusString(res, tmp) #计算res和tmp的和

        return res
    
    def StringMultiplyDigit(self,string, n):
        #这个函数的功能是：计算一个字符串和一个整数的乘积，返回字符串
        #举例：输入为 "123", 3， 返回"369"
        s = string[::-1]
        res = []
        for i, char in enumerate(s):
            num = int(char)
            res.append(num * n)
        res = self.CarrySolver(res)
        res = res[::-1]
        return "".join(str(x) for x in res)
        
    def CarrySolver(self, nums):  
        #这个函数的功能是：将输入的数组中的每一位处理好进位
        #举例：输入[15, 27, 12], 返回[5, 8, 4, 1]
        i = 0
        while i < len(nums):
            if nums[i] >= 10:
                carrier = nums[i] // 10
                if i == len(nums) - 1:
                    nums.append(carrier)
                else:
                    nums[i + 1] += carrier
                nums[i] %= 10
            i += 1
                    
        return nums
    
    def StringPlusString(self, s1, s2):
        #这个函数的功能是：计算两个字符串的和。 
        #举例：输入为“123”， “456”, 返回为"579"
        #PS：LeetCode415题就是要写这个函数
        l1, l2 = len(s1), len(s2)
        if l1 < l2:
            s1, s2 = s2, s1
            l1, l2 = l2, l1
        s1 = [int(x) for x in s1]
        s2 = [int(x) for x in s2]
        s1, s2 = s1[::-1], s2[::-1]
        for i, digit in enumerate(s2):
            s1[i] += s2[i]
            
        s1 = self.CarrySolver(s1)
        s1 = s1[::-1]
        return "".join(str(x) for x in s1)
```

## 复杂度分析
时间复杂度为 $O(MN)$，M 和 N 分别为 `num1`，`num2` 的长度

空间复杂度为 $O(M + N)$
