//主要就是判断n为奇数的时候是+1还是-1，当(n+1)/2可以被2整除就+1，反过来就-1，n为3的时候需要单独拿出来
```
class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        if (n == 1) return 0;
        long n1 = n;
        while (n1 != 1) {
            if (n1 == 3) {
                ans += 2;
                break;
            }
            else if (n1 % 2 == 0) {
                ans += 1;
                n1 /= 2;
            }
            else {
                if (((n1 + 1)/2)%2 == 0) {
                    n1 += 1;
                    ans += 1;
                }
                else {
                    n1 -= 1;
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
```
