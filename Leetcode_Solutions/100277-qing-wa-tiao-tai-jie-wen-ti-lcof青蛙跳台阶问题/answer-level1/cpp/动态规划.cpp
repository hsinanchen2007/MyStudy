
### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        vector<int> help(n+1,0);
        help[0]=1;
        help[1]=1;
        for(int i=2;i<=n;i++)
            help[i]=(help[i-1]+help[i-2])%1000000007;
        return help[n];
    }
};
```