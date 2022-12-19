三行代码不就可以了


### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s=s+s.substr(0,n);
        s.erase(s.begin(),s.begin()+n);
        return s;
    }
};
```