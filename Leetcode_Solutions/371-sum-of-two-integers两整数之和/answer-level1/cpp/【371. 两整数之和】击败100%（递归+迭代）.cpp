## 思路一：递归
利用二进制位进行运算。分两步：
1. 不考虑进位进行相加
2. 加上进位，直到进位为0

sum = a ^ b，得到无进位和。
a & b，得到进位，因为是进位，所以左移一位进行相加。考虑到无符号溢出问题，所以转为无符号数。
**注意：最小负数左移溢出，所以转为无符号数**
### 代码
```c++
class Solution {
public:
    int getSum(int a, int b) {
        int sum, c;
        sum = a ^ b;
        c = ((unsigned int)(a & b)) << 1;
        if (c != 0) {
            return getSum(sum, c);
        }
        return sum;
    }
};
```

## 思路二：迭代
### 代码
```c++
class Solution {
public:
    int getSum(int a, int b) {                
        while (b != 0) {
            int c = a & b;
            a = a ^ b;
            b = (unsigned int)c << 1;            
        }
        return a;
    }
};
```

