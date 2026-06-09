### 解题思路
题目无非就是凑出`1/10`的概率出来，而现在我们只有`1/7`的概率，可以利用乘法原则`1/10=1/5 * 1/2`。
因为是随机的，所以每一次的选择都不会影响下一次的概率分布，所以代码中凑出`1/5`和`1/2`的方式是可行的。
### 代码

```cpp
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int first = 7, second = 4;
        while (first > 5) first = rand7();
        while (second == 4) second = rand7();
        return first + (second > 4 ? 5 : 0);
    }
};
```