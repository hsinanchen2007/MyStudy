### 解题思路


### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        bool need_div = true;
        int j=1;

        unsigned long long  N = 1;
        unsigned long long  M = 1;

        for( int i=m; i<n+m-1; i++) {//求出(m-1+n-1)(m-1+n-1-1)...(m-1+1)
            N *= i;
            //要在此处除以m！，否则极容易造成溢出
            while (N%j==0 && need_div==true) {//求出m!
                N /= j;
                if (++j == n) {
                    need_div=false;
                }
            }
        }

        return N;
    }
};


```