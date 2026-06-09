## 题目
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0
 

限制：

0 <= n < 2^31
注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/

>来源：力扣（LeetCode）
>链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



## 解法
题目的思路有两种，一个是直接从头开始计算，把所有数字都打印出来，但是这样的最少要打印N个数字。

实际上，我们可以通过数学计算的方法，得到对应的数字。

1. 第一步，找到这个数字对应的实际上是几位数：已知1-9有9个数字，10-99有90个数，每个数都是两位数，一共有$90*2$个数字，100-999有$900*3$个数字，显然在自然数中，$k$位数一共有$9*k*10^{k-1}$个数。
2. 第二步骤，这个数字对应的是序列中的哪个数。在上一个步骤后，我们能知道这个数是几位数，同时我们还把所有数过的数字减掉，在这一步除以k，就能达到这个数属于这个序列的第几个。
3. 求余数。得到这个数字在对应的数中是第几位。

需要注意的细节：如果得到的余数是0代表前一个数字的尾巴。


## 代码
```
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10: return n
        base = 1        # 几位数
        num  = n        # 
        while num // (base*9*10**(base-1)) > 0:
            num -= base*9*10**(base-1)      # 注意
            base += 1
        indexOfNum = num//base
        remainder = num%base
        rightNum = 10**(base-1)+indexOfNum

        if remainder == 0:
            return (rightNum-1)%10
        return rightNum//(10**(base-remainder))%10
```

## 总结
边界问题：余数为0的情况。

 
