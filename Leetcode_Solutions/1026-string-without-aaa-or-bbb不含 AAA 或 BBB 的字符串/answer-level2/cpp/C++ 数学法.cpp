不妨设A <= B
1. 选择较大的数B，两个一组，一共能分成n = (B + 1) / 2组
2. 接下来将A一个个插入到B的形成的n个空缺中，如果A没有插入完，那么将剩下A - (B + 1) / 2个数。将这些数继续从头一个个插入到n个空缺中即可
```
class Solution {
public:
    string func(int A, int B, char a, char b) {
        if (A > B)
            return func(B, A, b, a);
        string res;
        int delta = A - (B + 1) / 2;
        while (A > 0 || B > 0) {
            if (B > 0) {
                res += string(min(2, B), b);
                B -= 2;
            }
            if (A > 0) {
                res += a;
                A -= 1;
            }
            if (delta > 0 && A > 0) {
                res += a;
                delta -= 1;
                A -= 1;
            }
        }
        return res;
    }
    string strWithout3a3b(int A, int B) {
        return func(A, B, 'a', 'b');
    }
};
```
![image.png](https://pic.leetcode-cn.com/0ac5a4e0fa7a3eb9261bbf4b76b41b939decf07ab4bc388ad97b55df4db00317-image.png)
