### 解题思路
## 一、判断正负
     根据题意负数必不是回文数，故直接返回false
     若为正数，则开始处理

## 二、正数处理
     判断正读反读都一样，我首先想到的是依次取出该数的高位（high_num）和低位（low_num）进行比较
     以 12321 为例 先得到数的位数备用，该数位数x_num = 5
     1.先取最高位和最低位：low_num = x % 10 / 1 = 1; high_num = x / 10000[10 ^ (5-1)] % 10 = 1，      相等，------ 12321 % 10 / 1 = 1   ==   12321 / 10000 % 10 = 1
     2.次高位和次低位：low_num = x % 100 / 10 = 2；high_num = x / 1000[10 ^ (4-1)] % 10 = 1，相       等，------12321 % 100 / 10 = 2  ==  12321 / 1000 % 10 = 2
     3.发现不需要再判断，该数是回文数，返回true

## 三、发现处理时的规律
     整个处理过程类似一个二分法一样的循环，可以发现结束条件时x模的那个数（mod_num）大于了x除的数          (div_num)
     而每次循环mod_num会乘10，div_num会除10
     式中还有两个变量分别是：
         为了取出低位而除的数（low_div）,该数每次循环后乘10，以便于下次循环可以取下一位低位
         为了取出高位而模的数（high_mod），该数再循环中一直为10,因为每次比较都是取高位数的个位，故不          需要改变

## 以下为代码 欢迎指出错误和不足之处！0.0
     

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int low_div = 1, high_mod = 10, x_num = 0, mod_num = 10， div_num;

        for (int t =x; t != 0; x_num++) t /= 10;
        div_num = pow(10, x_num-1);

        while (mod_num <= div_num) 
        {
            if ((x % mod_num) / low_div == (x / div_num) % high_mod) 
            {
                mod_num *= 10;
                low_div *= 10;
                div_num /= 10;
            }
            else return false;
        }

        return true;
    }
};
```

### 执行结果
2020/3/16
执行用时：12ms ---C++中击败86.18%
内存消耗：7.6MB ---C++中击败100.00%