```
class Solution {
public:
    int add(int a, int b) {
        while(b != 0) {
            int plus = a ^ b;   // 求没有进位的和
            b = (unsigned int)(a & b) << 1;   // 求进位
            a = plus;
        }
        return a;
    }
};
```
