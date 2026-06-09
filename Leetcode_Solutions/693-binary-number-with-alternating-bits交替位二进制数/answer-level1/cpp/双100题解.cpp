### 解题思路
构造一个控制变量如果连续两次出现相同数字 则返回 false;

### 代码

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 思路：构造一个控制变量如果连续两次出现相同数字 则返回 false;

        bool flag = (n%2);
        n >>= 1;
        while (n) {
            if (n%2 == flag) return false;
            n >>= 1;
            flag = !flag;
        }

        return true;
    }
};
```