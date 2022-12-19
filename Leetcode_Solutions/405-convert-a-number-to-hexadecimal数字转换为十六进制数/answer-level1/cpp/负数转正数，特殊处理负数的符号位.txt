### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        int n = num;
        char hex[16] = {'0','1','2','3','4','5','6','7','8','9',
                        'a','b','c','d','e','f'};
        if (num < 0) {
            num = num + 1 + INT_MAX;
        }

        deque<char> dq(sizeof(int)*8/4, '0');
        int idx = 0;
        while (num) {
            int mod = num % 16;
            num >>= 4;
            dq[idx] = hex[mod];
            ++idx;
        }
        if (n < 0) {
            // 补齐最高位符号位1，对应1000，即为8
            int high = dq.back() - '0' + 8;
            dq.back() = hex[high];
        }

        while (!dq.empty()) {
            if (dq.back() != '0') {
                break;
            }
            dq.pop_back();
        }

        reverse(dq.begin(), dq.end());
        return string(dq.begin(), dq.end());
    }
};
```