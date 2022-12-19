### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        
        if(n==0) return s;
        s.push_back(s[0]);
        s.erase(0,1);
        n--;
        return reverseLeftWords(s,n);
    }
};
```