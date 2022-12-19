## 解决方案

本文给出了三种解决方案。首先我们可以想到用字符串反转来解决问题，将输入x转化为字符串，反转后输出，过程中注意对特殊情况的判断即可；然后我们想到可以直接处理数字，比如使用long类型来简化溢出的处理。但是由于题目要求【假设我们的环境只能存储得下 32 位的有符号整数】，所以上面两种方法虽然可以通过，但不符合题目要求。符合题目要求的题解 在本文的方法三给出。

## 方法一：转为字符串处理

首先提取符号记录到flag，然后取绝对值后转化为字符串，并进行反转，并将反转后的值尝试转化为int，若失败则返回0，成功则返回转化后的int值，并乘上flag符号。

参考代码：

        public int Reverse(int x)
        {
            if (x == int.MinValue) return 0; // Math.Abs(int.MinValue) 会出错；由于int.MinValue反转后溢出，所以可以提前判断了
            int flag = x > 0 ? 1 : -1; // 把符号取出来
            var chars = Math.Abs(x).ToString().ToCharArray();
            Array.Reverse(chars);
            var reversedStr = new string(chars);
            var result = 0;
            if (int.TryParse(reversedStr, out int parseOkResult))
            {
                result = parseOkResult;
            }
            return result * flag;
        }


#### 执行结果

执行结果 通过。 执行用时： 40ms, 内存消耗 14.9M

#### 复杂度分析

**时间复杂度：O(n)**

当作长度为n的字符串处理

**空间复杂度：O(1)**

如果把 ToCharArray()当作 O(1) 即可，因为x在int.MinValue与int.MaxValue, 长度可以说是相对固定的.


## 方法二：使用long类型来处理

使用long来处理，可以简化对溢出的判断。

参考代码：

        public int Reverse(int x)
        {
            long result = 0;//用long类型判断溢出
            while (x != 0)
            {
                result = result * 10 + x % 10;
                x /= 10;
            }
            if (result > int.MaxValue || result < int.MinValue) return 0;
            return Convert.ToInt32(result);
        }

#### 执行结果

执行结果 通过。 执行用时： 44ms, 内存消耗 14.7M

#### 复杂度分析

**时间复杂度：O(n)**

while循环执行n次

**空间复杂度：O(1)**

只用到了几个常量


## 方法三：直接处理int类型的数字

符合题意的解法。

对于输入x，我们可以从x的最右侧pop出一个数字，将其添加到结果的右侧，这样即可反转x。

这里的pop操作，可以通过【取余】和【除法】来实现。比如1234，对10取余，得到4，这个4即是我们的pop值，而1234整除10得到123。 这样便实现了将4从1234中pop出来。 将pop值添加到结果，可以用result=result*10+pop.

参考代码：

        public int Reverse(int x)
        {
            int result = 0;
            var INT_MAX = int.MaxValue;
            var INT_MIN = int.MinValue;
            while (x != 0)
            {
                int pop = x % 10;
                x /= 10;
                // int.MaxValue == 2147483647
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
                // int.MinValue == -2147483648
                if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;
                result = result * 10 + pop;
            }
            return result;
        }

#### 执行结果

执行结果 通过。 执行用时： 52ms, 内存消耗 14.6M

#### 复杂度分析

**时间复杂度：O(n)**

while循环执行n次

**空间复杂度：O(1)**

只用到了几个常量

## 参考资料汇总

题目：

[https://leetcode-cn.com/problems/reverse-integer/](https://leetcode-cn.com/problems/reverse-integer/)

官方题解：

[https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode/](https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode/)
