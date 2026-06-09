### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(int i = 0; i < emails.size(); i++){
            int j = 0, pos = -1;
            while(emails[i][j] != '@'){
                if(pos == -1 && emails[i][j] == '+') pos = j;
                if(pos == -1 && emails[i][j] == '.') emails[i].erase(j--, 1);
                ++j;
            }
            if(pos != -1) emails[i].erase(pos, j - pos);
            ans.insert(emails[i]);
        }
        return ans.size();
    }
};
```