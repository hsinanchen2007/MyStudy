### 解题思路
以 789 + 456 = 1245 为例，若不算进位，则789+456 = 135,若只算进位，则789 + 456 = 1110。显然135 + 1110 = 1245
不算进位的加法可以使用异或运算，只算进位的加法可以使用与运算再左移1
递归或迭代至进位为0即可
### 代码

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b & 0x7fffffff) << 1;//为什么要&7fffffff，因为负数不能左移，且最高位的1无用处(会左移出去)，因此把最高位的1变成0即可
        return getSum(sum,carry);
    }
};
```