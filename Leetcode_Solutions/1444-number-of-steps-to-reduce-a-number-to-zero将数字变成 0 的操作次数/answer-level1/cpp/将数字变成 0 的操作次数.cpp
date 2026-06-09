### 解题思路
涉及加减乘除取余等简单算术运算 使用位运算更为快捷
除以2  可以 右移一位代替（前提是非负）
减一   可以 用 &= -2（0xfffffffe） 代替
条件判断  num & 0x1 == 1   优先级为 先判断0x1 == 1 所以要加括号 (num & 0x1) == 1
### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while (num) {
            ++count;
            (num & 0x1) == 1 ? num &= -2 : num >>= 1;
        }
        return count;
    }
};
```