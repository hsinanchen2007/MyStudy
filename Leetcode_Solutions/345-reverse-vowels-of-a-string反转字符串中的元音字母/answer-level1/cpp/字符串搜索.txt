### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, l = s.length() - 1;
        string a = "aoeiuAOEIU";
        while (i < l)
        {
            while (i < l && a.find(s[i]) == a.npos) i++;
            while (i < l && a.find(s[l]) == a.npos) l--;
            if (i < l) {swap(s[i],s[l]); i++; l--;}
        }
        return s;      
    }
};
```