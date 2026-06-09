### 解题思路


### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ret;
        for(auto i : address){
            if(i != '.') ret += i;
            else ret.append("[.]");
        }
        return ret;
    }
};
```