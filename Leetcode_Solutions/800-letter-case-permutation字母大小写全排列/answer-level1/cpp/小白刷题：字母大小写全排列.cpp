全排列，建议递归，首先得出除第一个字符以外的子串对应集合，然后根据第一个字符的情况将集合中的字符串补全

代码：
```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if (S == "") {
            vector<string> ans(1);
            ans[0] = "";
            return ans;
        }
        else {
            char c = S[0];
            S.erase(0, 1);
            vector<string> ans(letterCasePermutation(S));
            int num = ans.size();
            for (int i = 0; i < num; i++) {
                ans[i].insert(0, 1, c);
            }
            if (c >= '0' && c <= '9');
            else {
                vector<string> temp(ans);
                if (c >= 'A' && c <= 'Z')  {
                    for (int i = 0; i < num; i++) {
                        temp[i][0] = temp[i][0] + 32;
                        ans.push_back(temp[i]);
                    }    
                }
                else  {
                    for (int i = 0; i < num; i++) {
                        temp[i][0] = temp[i][0] - 32;
                        ans.push_back(temp[i]);
                    }    
                }
            }
            return ans;
        }
    }
};
```
