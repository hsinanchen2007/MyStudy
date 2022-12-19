### 解题思路
把头部删掉，插到尾部

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        char temp;
        for (int i = 0; i < n; i++) {
            temp = s[0];
            s.erase(0,1);
            s.push_back(temp);
        }
        return s;
    }
};
```