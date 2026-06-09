```
/*
四平方和定理：
    每个正整数n均可表为四个整数的平方和，如果n % 8 == 7,则n必须由4个不同的正整数的平方和表示
*/
class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;
        for(int a=0; a*a<=n; a++) {
            int b = sqrt(n - a*a);
            if(a*a + b*b == n)
                return (a > 0) + (b > 0);
        }
        return 3;
    }
};
```
