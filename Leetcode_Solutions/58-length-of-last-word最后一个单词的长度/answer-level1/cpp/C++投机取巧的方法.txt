### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream is(s);
        string a;
        while(is>>a);
        return a.size(); 
    }
};
```