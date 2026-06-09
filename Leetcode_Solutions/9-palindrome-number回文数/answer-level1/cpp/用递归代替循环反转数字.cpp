### 解题思路
用递归代替循环反转数字

### 代码

```cpp
class Solution {
public:
    int reversed(int x, int& total){
        if (x > 0) {
            int last_number = x % 10;
            if (total <= (0x7fffffff - last_number) / 10) {
                total = total * 10 + last_number;
            }
            reversed(x / 10, total);
        }
        return total;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            int total = 0;
            return (x == reversed(x, total));
        }
    }
};
```