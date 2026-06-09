类似斐波那契，循环递推（递推，不是递归，递归重复运算太多，会超时）

代码：
```
class Solution {
public:
    int tribonacci(int n) {
        if (n < 3)
            return (n + 1) >> 1;
        else {
            int a = 0, b = 1, c = 1;
            int temp;
            for (int i = 2; i < n; i++) {
                a = a + b + c;
                temp = a;
                a = b;
                b = c;
                c = temp;
            }
            return temp;
        }
    }
};
```
