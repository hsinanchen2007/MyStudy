### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans(0);
        for (int i = 0, j = 0, level = 0; s[i] != '\0'; ++i) {
            if (s[i] == ' ') {
                 ++level;
                 j = 0;
            }
            else {
                if(j == ans.size() ) {
                    string tmp;
                    ans.push_back(tmp);
                }
                int m = level - ans[j].size();
                ans[j].append(m, ' ');
                ans[j].push_back(s[i]);
                j++;
            }
            // cout<< j << " "<< ans.size() <<endl; 
        }
        
        return ans;
    }
};
```