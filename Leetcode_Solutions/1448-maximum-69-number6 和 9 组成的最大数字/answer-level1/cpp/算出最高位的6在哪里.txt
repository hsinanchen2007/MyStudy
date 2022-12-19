### 解题思路
关键点：算出最高位的6在哪里

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        int result = num;
        int seq6 = 0;
        int cnt = 0;
        while (num) {
            ++cnt;
            if (num % 10 == 6) {
                seq6 = cnt;
            }
            num /= 10;
        }
        if (seq6 != 0) {
            result += 3*pow(10, seq6-1);
        }

        return result;
    }
};
```