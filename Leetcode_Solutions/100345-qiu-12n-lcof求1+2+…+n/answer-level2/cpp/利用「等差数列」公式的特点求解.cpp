```
class Solution {
public:
    int sumNums(int n) {

        char a[n][n+1];  // 1 + 2 + ... + n = ( n * (n+1) ) / 2
						 // n * (n + 1) 的值始终为「偶数」
						 // sizeof( a ) = n * (n + 1)
        return ( sizeof(a) >> 1 );
    }
};
```
