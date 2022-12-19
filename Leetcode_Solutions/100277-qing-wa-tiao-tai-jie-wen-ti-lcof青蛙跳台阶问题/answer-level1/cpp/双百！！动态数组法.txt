### 解题思路
##n=1时有1种，n=2时有2种跳法

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n<=1) return 1;
        
        vector<int> a;
        a.push_back(0);
        a.push_back(1);
        a.push_back(2);
        int i;
        for( i=3;i<=n;i++)
        {
            a.push_back((a[i-1]+a[i-2])%1000000007);

        }
        
        return a[n];


    }
};
```