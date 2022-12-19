#  各位相加
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

```
输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
```

<hr>

##  解法1：暴力法
```
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>=10)
        {
            sum=0;
            while(num)
            {
                int temp=num%10;
                sum+=temp;
                num/=10;
            }
            num=sum;
        }
        return num;
    }
};
```

##  解法2：找规律
假设一个三位数整数n=100\*a+10*b+c,变化后addn=a+b+c；
两者的差值n-addn=99a+9b，差值可以被9整除，说明每次缩小9的倍数
那么我们可以对res=num%9，若不为0则返回res，为0则返回9

```
class Solution {
public:
    int addDigits(int num) {
        if(num>9)
        {
            num=num%9;
            if(num==0)
                return 9;
        }
        return num;
    }
};
```

