### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        unsigned int c = a & b;
        //无进位循环停止
        while (c) {
            c <<= 1;
            a = a ^ b;
            b = c;
            c = a & b;
        }
        return a ^ b;
    }
};
```