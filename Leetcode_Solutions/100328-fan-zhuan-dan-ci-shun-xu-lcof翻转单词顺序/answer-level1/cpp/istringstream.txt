### 解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 0)
            return s;
        istringstream ss(s);
        string ans = "", temp;
        vector<string> v;
        while(ss >> temp)
            v.push_back(temp);
        if(v.size() == 0)
            return ans;
        ans += v.back();
        for(int i = v.size() - 2 ; i >= 0 ; i--)
        {
            ans += " ";
            ans += v[i];
        }
        return ans;
    }
};
```