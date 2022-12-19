### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.empty() || s2.empty())
            return false;
        string temp_s1 = s1;
        string temp_s2 = s2;
        sort(temp_s1.begin(), temp_s1.end());
        sort(temp_s2.begin(), temp_s2.end());
        if (temp_s1 == s2 || s1 == temp_s2 || temp_s1 == temp_s2)
            return true;
        
        return false;
    }
};
```