
## 解决方案

本文给出了两种解决方法。

第一种方法 是 转化为字符串判断是否是回文。

第二种方法 是直接处理int型， 将输入值x的后半段拎出来，与前半段比较，看是否是回文。

## 方法一：转化为字符串处理

参考代码：

        public bool IsPalindrome(int x)
        {
            string str = x.ToString();
            var chars = str.ToCharArray();
            Array.Reverse(chars);
            string reverseStr = new string(chars);
            if (str == reverseStr) return true;
            else return false;
        }
	
	
#### 执行结果

执行结果 通过。 执行用时： 84ms, 内存消耗 17.5M

#### 复杂度分析

**时间复杂度：O(n)**

处理长度为n的字符串

**空间复杂度：O(1)**

只用了几个变量来存值



## 方法二：int型反转一半数字

初始化y=0，我们将x的个位（最右边的数字）依次移动到y的右侧，这种移动将把x的后半段移动到y，然后我们比较x与y是否相等即可。

对于x的移动，我们使用取余整除的方式来将个位pop出来，并将pop值添加到y的右侧。

将x的个位数pop出来：

            int pop = x % 10;
            x /= 10;

将pop值添加到y的右侧：

            y = y * 10 + pop;

比如对于1221来说，第一次移动后，x=122,y=1, 第二次移动后， x=12,y=12,此时移动结束，因为x与y相等，所以1221是回文数字。

而对于奇数长度的输入来说则有点小区别，比如12321 . 第一次移动后 x=1232,y=1,第二次移动后 x=123, y=12, 第三次移动 x=12 ,y=123 . 我们可以在第三次移动后结束移动。此时判断x与y/10是相等的，所以12321也是回文数字。

综合上面对于偶数与奇数的分析，可以得到代码中 【while(条件) 移动；】中的条件为x>y. 而是否是回文数的判断条件为 【x与y相等】 或者 【x与y/10相等】。

参考代码：

        public bool IsPalindrome(int x)
        {
            if (x < 0) return false;
            if (x < 10) return true;
            if (x % 10 == 0) return false;
            int y = 0;
            while (x > y)
            {
                int pop = x % 10;
                x /= 10;
                y = y * 10 + pop;
            }
            return (x == y) || (x == y / 10);
        }
	
	
#### 执行结果

执行结果 通过。 执行用时： 76ms, 内存消耗 15.8M

#### 复杂度分析

**时间复杂度：O(n)**

while循环进行次数为n/2左右，所以为O(n).    这里n表示长度，官方题解的O(lg(n))中的n指的是输入值x.

**空间复杂度：O(1)**

只用了几个变量来存值


## 参考资料汇总

题目：

[https://leetcode-cn.com/problems/palindrome-number/](https://leetcode-cn.com/problems/palindrome-number/)

官方题解：

[https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode/](https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode/)

