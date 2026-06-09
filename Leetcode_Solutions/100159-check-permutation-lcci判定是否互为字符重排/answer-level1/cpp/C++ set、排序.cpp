### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // bool CheckPermutation(string s1, string s2) {
    //     if(s1.size() != s2.size())
    //         return false;
    //     return set(s1.begin(), s1.end()) == set(s2.begin(), s2.end());
    // }

    bool CheckPermutation(string s1, string s2) {

        if(s1.size() != s2.size())
            return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
```