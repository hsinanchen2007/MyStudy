### 解题思路

### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                ans.append("[.]");
            }
            else
                ans += address[i];
        }
        return ans;
    }
};
```