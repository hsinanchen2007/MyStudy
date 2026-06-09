### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string result=s.substr(n,s.length()-n)+s.substr(0,n);
        return result;
    }
};
```