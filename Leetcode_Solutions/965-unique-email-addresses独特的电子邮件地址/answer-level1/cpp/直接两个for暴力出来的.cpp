### 解题思路
没什么思路，一个个用if来对比。

### 代码

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(int j = 0; j < emails.size(); j++)
        {
            string sot = "";
            bool t = 0;
            for(int i = 0; i < emails[j].size(); i++)
            {
                if(emails[j][i] == '@')
                {
                    sot += emails[j].substr(i);//从emails[j][i]的位置开始直到最后
                    break;
                }
                else if(emails[j][i] == '+')
                {
                    t = 1;
                }
                else if(emails[j][i] != '.' && t == 0)
                {
                    sot += emails[j][i];
                }             
            }
            st.insert(sot);
        }
        return st.size();
    }
};
```