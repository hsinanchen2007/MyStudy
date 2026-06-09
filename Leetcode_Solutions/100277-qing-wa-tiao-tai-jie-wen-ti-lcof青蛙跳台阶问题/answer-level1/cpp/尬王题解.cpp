### 解题思路
反过来的斐波那契数列，你品，你细品。。。

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n==0){return 1;}
        if(n==1){return 1;}
        if(n==2){return 2;}
        int zero = 2;int one = 1;int res;
        for(int i =n-3;i>=0;i--)
        {
            res = (zero+one)%1000000007;
            one = zero;
            zero = res;
        }
        return res;
    }
};
```