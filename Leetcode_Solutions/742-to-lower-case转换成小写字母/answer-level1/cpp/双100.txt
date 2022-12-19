### 解题思路


### 代码

```cpp
class Solution {
public:
    string toLowerCase(string str) {
        for (char& ch : str) {
            if (ch>='A'&&ch<='Z')
                ch = ch+32;
        }
        return str;
    }
};
```