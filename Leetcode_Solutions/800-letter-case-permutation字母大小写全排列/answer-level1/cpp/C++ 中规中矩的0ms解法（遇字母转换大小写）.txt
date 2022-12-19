```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans{ S };
        for (int i = 0; i < S.size(); ++i)
            if (isalpha(S[i])) //遇字母
                for (int j = ans.size() - 1; j >= 0; --j) {
                    ans.push_back(ans[j]); //先保存 再转换大小写
                    if (isupper(ans[j][i])) ans[j][i] = tolower(ans[j][i]);
                    else ans[j][i] = toupper(ans[j][i]);
                }
        return ans;
    }
};
```