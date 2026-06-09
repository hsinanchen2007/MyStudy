### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        string val = to_string(num);
        int res;

        for (int i = 0; i < val.length(); i++) {
            if (val.at(i) == '6') {
                val.replace(i, 1, "9");
                break;
            }
        }

        istringstream is(val);
        is >> res;
        return res;
    }
};
```