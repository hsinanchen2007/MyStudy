```
class Solution {
public:
    int lcm(int p, int q) {
        return p / __gcd(p, q) * q;
    }
    int s[2][2] = {{3, 0}, {2, 1}};
    int mirrorReflection(int p, int q) {
        int k = lcm(p, q);
        int n = k / p;
        int m = k / q;
        return s[n & 1][m & 1];
    }
};
```

![image.png](https://pic.leetcode-cn.com/18a343033bc0b03393313ada5a916e2ba03c7a3eabb5aaefe3a92b055031ce37-image.png)
