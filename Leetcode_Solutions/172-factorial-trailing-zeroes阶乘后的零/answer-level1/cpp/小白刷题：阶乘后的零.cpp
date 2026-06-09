阶乘后的零，只需看所有因子中5因子的个数

代码：
```
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long temp = 5;
        while(n >= temp) {
            ans += n / temp;
            temp = temp * 5;
        }
        return ans;
    }
};
```
