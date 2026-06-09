```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        find(S, 0, S.size()-1, "", res);
        return res;
    }
    void find(string S, int i, int j, string pre, vector<string>& res)
    {
        if(i>j)
        {
            res.push_back(pre);
            return;
        }
        if(S[i]>='a' && S[i]<='z')
        {
            find(S, i+1, j, pre+S[i], res);
            find(S, i+1, j, pre+char(S[i]-'a'+'A'), res);            
        }
        else if(S[i]>='A' && S[i]<='Z')
        {
            find(S, i+1, j, pre+char(S[i]-'A'+'a'), res);            
            find(S, i+1, j, pre+S[i], res);
        }
        else
        {
            find(S, i+1, j, pre+S[i], res);
        }
    }
};
```
