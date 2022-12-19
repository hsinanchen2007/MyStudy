### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto p : s){
            if(p >= 97 && p <= 122) t.push_back(p - 32);
            if(p >= 65 && p <= 90) t.push_back(p);
            if(p >= 48 && p <= 57) t.push_back(p);
        }
        bool ans = true;
        for(int i = 0, j = t.size() - 1;i < j;++i){
            if(t[i] == t[j])--j;
            else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};
```