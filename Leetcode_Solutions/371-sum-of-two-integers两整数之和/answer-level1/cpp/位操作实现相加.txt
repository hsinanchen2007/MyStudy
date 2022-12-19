### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int getSum(int a, int b) {
          while (a & b) {// 有进位就进入循环
            int n = a;
            int m = b;
            a = n ^ m;  //无进位的相加
            b = (unsigned int)(n & m) << 1;  //进位,负数不支持左移操作，就强制转换为无符号数
        }
        return a ^ b;

    }
};
```