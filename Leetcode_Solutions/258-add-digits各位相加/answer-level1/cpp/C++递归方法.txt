### 解题思路
此处撰写解题思路
每一次都是计算一个数字的所有位数之和，所以会想到使用递归的解法。
首先需要明确递归的条件：
（1）递归结束的条件：所有位数之和相加为一个个位数，即小于10；
（2）函数的作用是计算每一个数的所有位数之和，使用到while循环；
（3）可以等价为addDigits(sum)；
### 代码

```cpp
class Solution 
{
public:
    int addDigits(int num) 
    {
        if(num < 10) //递归结束的条件
            return num;
        else
            {
                int sum = 0;
                while(num > 0) //计算出每一位的和
                {
                    int m = num%10;
                    num = num/10;
                    sum += m;
                } 
                int s = addDigits(sum); //递归
                return s;               
            }
    }
};
```