### 解题思路
![image.png](https://pic.leetcode-cn.com/b94ae44a60e18580ddd6cf300c191ee1ac53eaf334c580362915dec3bfb9b278-image.png)
设有首项A1，n个数的公差为1等差数列，有(n-1+2*A1)*n=2*N;所以我们只需要求出2*N的某种因子i的数目，该因子i具有：2*N/i-i为奇数。

### 代码

```cpp
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        N*=2;
        int sqr=sqrt(N);
        //cout<<sqr;
        int a=0;
        int res=0;
        for(int i=1;i<=sqr;i++)
        {
            if(N%i!=0)
            continue;
            else
            {
                a=N/i;
                if((a-i)%2==1)
                res++;
            }
        }
        return res;
    }
};
```