• 下面这个代码思路是对的，但是时间复杂度超时了。
```
class Solution {
public:
    bool isprimenumber(int n)
    {
        for(int i = 2 ; i <= sqrt(n); i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n==1) return 0;
        int cnt = 0;
        for(int i = 2;i < n; i++)
        {
            if(isprimenumber(i)) cnt++;
        }
        return cnt;
    }
};

```
• 比较优秀的算法了，思想也比较简单。一个数（大于2的）如果不是质数，那么必定在这之前会有一个数乘以n等于它。
```
class Solution {
public:
    int countPrimes(int n) {
        if(n==1) return 0;
        int cnt = 0;
        vector<bool> sign(n,true);
        for(int i = 2;i < n; i++)
        {
            if(sign[i])
            {
                cnt++;
                for(int j = i;j < n;j+=i)
                {
                    sign[j] = false;
                }
            }
        }
        return cnt;
    }
};



```
• 把上面的代码改成用bitset，更节省空间。适合处理大数)
```
class Solution {
public:
    int countPrimes(int n) {
        if(n > 1000000000) return 0;
        int cnt = 0;
        bitset<100000000> sign;
        sign.set();
        for(int i = 2;i < n; i++)
        {
            if(sign[i])
            {
                cnt++;
                for(int j = i;j < n;j+=i)
                {
                    sign[j] = 0;
                }
            }
        }
        return cnt;
    }
};
```

