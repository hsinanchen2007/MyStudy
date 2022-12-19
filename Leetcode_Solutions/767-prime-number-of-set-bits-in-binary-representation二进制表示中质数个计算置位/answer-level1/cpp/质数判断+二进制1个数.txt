鶸题解（如有错误，恳请指正）：

二进制1个数：
```c++ []
       while(n!=0)
        {
            n&=n-1;//清除最低位的1
            cnt++;
        }
```
注解：

在二进制中，n =（n-1）+1

取最低位为0的情况，当n=6时：

6（0110）= 5（0101）+1（0001）

0110砍掉末尾1，应为0100，即为4，则：

4（0100）= 6（0110）&5（0101）

取最低位为1的情况，当n=5时：

5（0101）= 4（0100）+1（0001）

0101砍掉末尾1，应为0100，即为4，则：

4（0100）= 5（0101）&4（0100）

综上可知，`对n进行-1操作后，必定会使n最低位的1后移或消失（本质上也是后移）`

而进行与运算时，就会将所有不同位置零，即从最低位1位置开始向后全部置零，对n来说就消去了最低位1；

有几个1能被消掉，就有几个1；


质数判断：
```c++ []
        bool isPrime(int num)
        {
          if(num<2) return false;
          for(int i=2;i*i<=num;i++)//这里注意使用sqrt的效率较低，可使用i*i提高效率；
          {
              if(num%i==0) return false;
          }
          return true;
        }
```
AC代码：
```c++ []
class Solution {
public:
    // int prime[11]={2,3,5,7,11,13,17,19,23,29,31};
    int countPrimeSetBits(int L, int R) {
        int ans=0;
        for(int i=L;i<=R;i++)
        {
            int tmpNum=i,tmpCnt=0;
            while(tmpNum!=0)
            {
                tmpNum&=tmpNum-1;
                tmpCnt++;
            }
            // for(int j=0;j<11;j++)
            // {
            //     if(tmpCnt==prime[j])
            //     {
            //         ans++;
            //         break;
            //     }
            // }
            if(isPrime(tmpCnt)) ans++;
        }
        return ans;
    }
    bool isPrime(int num)
    {
        if(num<2) return false;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0) return false;
        }
        return true;
    }
};
```


