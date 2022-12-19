同《剑指offer》第14题，P96页。

### 1. 动态规划
### 代码
```cpp
class Solution {
public:
    int integerBreak(int n) {
        if ( n < 2 )
            return 0;
        if ( n == 2 )
            return 1;
        if ( n == 3 )
            return 2;
        
        vector<int> res( n+1, 0 );
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        res[3] = 3;

        for ( int i = 4; i < n+1; ++i ) {
            int maxVal = 0;
            for ( int j = 1; j <= i/2; ++j ) {
                int val = res[j] * res[i-j];
                if ( maxVal < val )
                    maxVal = val;
            }
            res[i] = maxVal;
        }

        return res[n];        
    }
};
```



### 2. 贪心
### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        int ans = 1;
        while(n>4){
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};
```