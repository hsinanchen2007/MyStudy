### 解题思路
遍历1~n的数，判断是否是质数，然后得出质数的总数count，那么n-count就是非质数的总数，最后
count!*(n-count)!
![image.png](https://pic.leetcode-cn.com/274f6ca5010a18ffd5dfb62b2d36f97869cdb54af0f433e5b21f0952716540a1-image.png)

### 代码

```cpp
class Solution {
public:
    bool iszhishu(int x)
    {
        if(x<2) return false;
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0) return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int count=0;
        for(int i=1;i<=n;i++) 
          if(iszhishu(i))
           count++;
        long int sum=1;
        int mod=pow(10,9)+7;
        for(int i=count;i>1;i--)
        {
            sum=sum*i;
            if(sum>=mod) sum%=mod;
        }
        for(int i=n-count;i>1;i--)
        {
            sum=sum*i;
            if(sum>=mod) sum%=mod;
        }
        return sum;
        
    }
};
```