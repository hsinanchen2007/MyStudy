### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int c=s.length();
        string ans;
        ans+=s.substr(n,c-n);
        ans+=s.substr(0,n);
        return ans;
    }
};
```