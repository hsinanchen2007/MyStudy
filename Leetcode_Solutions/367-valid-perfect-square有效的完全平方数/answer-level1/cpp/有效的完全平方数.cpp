#  有效的完全平方数
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

```
输入：16
输出：True
```
示例 2：

```
输入：14
输出：False
```

<hr>

##  解法1：递增判断

```
public:
    bool isPerfectSquare(int num) {
        int i=1;
        long n=i*i;
        while(n<=num)
        {
            if(n==num)
                return true;
            else 
            {
                i++;
                n=pow(i,2);
            }
        }
        return false;
    }
};
```

##  解法2：二分法
```
class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        int mid=start+(end-start)/2;
        while(start<=end)
        {
            if(pow(mid,2)>num)
            {
                end=mid-1;
            }
            else if(pow(mid,2)<num)
            {
                start=mid+1;
            }
            else return true;
            mid=(end-start)/2+start;
        }
        return false;
    }
};
```

##  解法3：公式法
利用 1+3+5+7+9+…+(2n-1)=n^2，即完全平方数肯定是前n个连续奇数的和

```
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0)
        {
            num-=i;
            i+=2;
        }
        return num==0;
    }
};
```

