### 解题思路
4的幂末尾只能是4或者6，过滤之后再利用2的幂判断方法

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        int k = num % 10;
        if (k != 4 && k !=6) return false;
        return (num&(num-1)) == 0;
    }
};
```