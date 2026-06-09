自己总结的，希望能帮到大家，大佬不要喷我谢谢,博文地址在这里：[Python3解法大全](https://blog.csdn.net/weixin_43071838/article/details/104533872)
题目要求：给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
题目解析：看到这个题我第一反应是想怎么把这个数字拆成一位一位的，之前记得有个方法但是突然想不起来了，我就干脆不想了就把这个数字变成string然后再利用map拆成数组，然后一位位加起来就好了，代码如下：

    def addDigits(self, num: int) -> int:
        while num >= 10:
            digit = list(map(int, str(num)))
            #因为我不想再用一个变量接结果我就把num先置零，以防历史值影响计算
            num = 0
            for i in range(len(digit)):
                num += digit[i]
        return num
下面来说说大佬们的规律，一个数xyz按位相加有什么规律呢？（xyz代表百位千位和十位）
xyz = 100*x + 10*y + z = 99*x + 99*y + (x+y+z)
x，y，z的最大值可能都是9，所以（x+y+z）之和可能是两位数也可能是一位数。如果是一位数正好就是我们模9的余数，如果是两位数则又变成了
mn = 10*m + n = 9*m + (m+n)
m最大为1 n最大为8 所以（m+n）是一位数，综上xyz按位相加的值就是模9取余的值，到这里原理讲完了，至于4位数5位数同理，接下来看代码吧：

    def addDigits(self, num: int) -> int:
        if (num % 9 == 0) and (num != 0):
            return 9
        else:
            return num % 9
还有一种写法就是我们常见的模10取位，这种方法太常见了不赘述了，看代码吧：

    def addDigits3(self, num: int) -> int:
        while num >= 10:
            sum = 0
            while num > 0:
                sum += num % 10
                num //= 10
            num = sum
        return num