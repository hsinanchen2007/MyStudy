```
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> indices;
        // 用l来辨别 ‘)’是否有效
        int l = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(')
            {
                indices.push_back(i);
                l++;
            }
            else if(s[i] == ')')
            {
                // 此时')'无效
                if(l == 0 )
                {
                    indices.push_back(i);
                }
                else
                {
                    indices.pop_back();
                    l--;
                }
            }
        }

        string res;
        int idx = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            // indices里保存的下标为升序，因此从左到右遍历即可
            if(idx < indices.size() && i == indices[idx])
            {
                idx++;
            }
            else
            {
                res += s[i]; 
            }
        }
        return res;
    }
};
```
