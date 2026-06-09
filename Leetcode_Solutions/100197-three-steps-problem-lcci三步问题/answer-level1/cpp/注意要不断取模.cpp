

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        vector<int> help(n+1,0);
        help[1]=1;
        help[2]=2;
        help[3]=4;
        for(int i=4;i<=n;i++)
            help[i]=((help[i-1]%1000000007+help[i-2]%1000000007)%1000000007+help[i-3]%1000000007)%1000000007;
        return help[n];
    }
};
```