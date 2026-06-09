### 解题思路
直接用power函数求幂自然会溢出，因此自己写一个函数，当大于10e7的时候取余即可

### 代码

```cpp
class Solution {
public:

    int cuttingRope(int n) {
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    if(n%3 == 1)
    {
        return CalculateProduce(3,n/3 - 1) * 4 %  1000000007;
    }
    else if(n%3 == 2)
    {

        return (CalculateProduce(3,n/3) * 2) % 1000000007;
    }
    else
    {
        return (CalculateProduce(3,n/3)) % 1000000007;
    }

}
    long long int CalculateProduce(int n, int k)
    {
        long long int res = 1;
        for(int i = 0; i < k; i++)
        {
            res = res * n;
            if(res > 1000000007)
                res = res %1000000007;
        }
        return res;
    }
};
```