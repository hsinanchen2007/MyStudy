#  计数质数
统计所有小于非负整数 n 的质数的数量。

示例:

```
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```

<hr>
质数定义：质数又称素数。一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做质数；否则称为合数。

##  解法1：

```
class Solution {
public:
    int countPrimes(int n) {
        int res=1;//从3开始计算，所以初始为1
        if(n<3) return 0;
        else 
        {
            for(int i=3;i<n;i++)
            {
                if(i%2==0)
                    continue;
                bool flag=true;//false表示不是素数
                for(int j=3;j<=sqrt(i);j+=2)
                {
                    if(i%j==0)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
```

##  解法2：思路与解法1相同

```
class Solution {
public:
    bool isPrime(int n)
    {
        if(n < 3)
            return n > 1;
        if(n % 2 == 0)
            return 0;
        int stop = sqrt(n) + 1;
        for(int i = 3; i <= stop; i += 2)
        {
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
    
    int countPrimes(int n) {
        if( n < 3 ) return 0;
        int count = 0;
        for(int i = 2; i < n; ++i)
        {
            if(isPrime(i))
            {
                count++;
            }  
        }
        return count;
    }
};
```

##  解法3：厄拉多塞筛法
西元前250年，希腊数学家厄拉多塞(Eeatosthese)想到了一个非常美妙的质数筛法，减少了逐一检查每个数的的步骤，可以比较简单的从一大堆数字之中，筛选出质数来，这方法被称作厄拉多塞筛法(Sieve of Eeatosthese)。

**具体操作**：先将 2~n 的各个数放入表中，然后在2的上面画一个圆圈，然后划去2的其他倍数；第一个既未画圈又没有被划去的数是3，将它画圈，再划去3的其他倍数；现在既未画圈又没有被划去的第一个数 是5，将它画圈，并划去5的其他倍数……依次类推，一直到所有小于或等于 n 的各数都画了圈或划去为止。这时，表中画了圈的以及未划去的那些数正好就是小于 n 的素数。

```
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n,true);
        int res=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(num[i])
            {
                int k=2;
                while(k*i<n)
                {
                    num[k*i]=false;
                    k++;
                }
            }
        }
        for(int i=2;i<n;i++)
        {
            if(num[i])
                res++;
        }
        return res;
    }
};
```

