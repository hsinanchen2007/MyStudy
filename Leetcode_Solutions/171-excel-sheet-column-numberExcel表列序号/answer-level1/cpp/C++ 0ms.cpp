### 解题思路


**该题就是一个26进制数转10进制**

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto ss : s){
            res = res * 26 + (ss - 'A' + 1);
        }
        return res;
    }
};
```