### 解题思路
这题不配拥有解题思路

1 <= k < s.length <= 10000
给出没有上述条件的解法

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n==s.size()||n==0)return s;
        if(n>s.size())n-=s.size();
        return s.substr(n)+s.substr(0,n);
    }
};
```