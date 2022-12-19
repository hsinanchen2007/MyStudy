汉明距离就是两数异或之后“1”位的个数

代码：
```
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int ans = 0;
        while (x) {
            if (x % 2 == 1)
                ans++;
            x = x >> 1;
        }
        return ans;
    }
};
```
