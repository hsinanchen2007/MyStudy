![image.png](https://pic.leetcode-cn.com/6cf3ed196c6d61404c4c0d31f87640dbc79c86d109653677ba3b993b7813a77b-image.png)
解题思路：主要有两点，1、计算二进制形式1的个数。2、判定上述个数是否为质数。比较好理解。
```
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for(int i=L;i<=R;i++)
        {
            int tmp = i,count=0;
            while(tmp != 0)
            {
                tmp &= tmp-1;
                ++count;
            }
            if(isPrime(count)) ++res;
        }
        return res;
    }
    bool isPrime(int num)
    {
        if(num<2) return false;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i == 0) return false;
        }
        return true;
    }
```
