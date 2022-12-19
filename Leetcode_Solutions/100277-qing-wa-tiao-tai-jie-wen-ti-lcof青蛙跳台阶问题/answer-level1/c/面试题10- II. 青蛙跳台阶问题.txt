### 解题思路
递归太慢，找规律用迭代，像斐波那契数列。

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        int a=1,b=2,ans=1;
        if(n==2)
        ans=2;
        for(int i=3;i<=n;i++)
        {
            ans=(a+b)%1000000007;
            a=b;
            b=ans;
        }
        return ans;
    }
};
```