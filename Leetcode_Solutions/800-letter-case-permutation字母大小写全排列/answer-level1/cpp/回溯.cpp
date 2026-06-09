### 解题思路
注意分情况搜
### 代码

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int length = S.length();
        DFS(0, S);
        return ans;
    }
    void DFS(int i, string &s)
    {
        if(i == s.size())
        {
            ans.push_back(s);
            return ;
        }
            if(isupper(s[i]))
            {
                DFS(i + 1, s);
                s[i] = tolower(s[i]);
                DFS(i + 1, s);
            }
            else if(islower(s[i])) 
            {
                DFS(i + 1, s);
                s[i] = toupper(s[i]);
                DFS(i + 1, s);
            }
            else
                DFS(i + 1, s);
    }
private:
    vector<string> ans;
};

```