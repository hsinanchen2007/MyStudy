### 解题思路
1.先做异或运算，结果为进位标志，在做与运算并左移1位，在将没有进位的结果与与运算的结果做异或运算得结果。
2.a为结果，b为进位结果，不断检查b是否为0判断是否还有进位。

### 代码

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while( b != 0){
            int temp = a ^ b;
            b = ((unsigned int)(a & b) << 1);
            a = temp;
        }
        return a;
    }
};
```