### 解题思路
穷举所有类型

### 代码

```cpp
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> m = {{'1','1'},{'6','9'},{'9','6'},{'8','8'},{'0','0'}};
        int len = num.size();
        for(auto i = 0; i < len; ++i){
            auto it = m.find(num[i]);
            if(it == m.end())
                return false;
            if(num[len-i-1] != m[num[i]])
                return false; 
        }
        return true;
    }
};
```