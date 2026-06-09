### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        string result;
        if (num == 0) {
            result = "0";
            return result;
        }
        if (num < 0) {
            result += "-";
            num = -num;
        }
        stack<int> S;
        while (num > 0 ) {
            S.push(num % 7);
            num = num / 7;
        }
        while (!S.empty()) {
            result += ('0' + S.top());
            S.pop();
        }
        return result;
    };
};
```