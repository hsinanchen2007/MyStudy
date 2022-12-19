用回溯法，跟全排列一样的解法
```
class Solution {
public:
    vector<string> lists;
    string list;
    vector<bool> used;
    int strLen;
    void backTrace(string S)
    {
        if (list.size() == strLen) {
            lists.push_back(list);
            return;
        }

        int loop;
        for (loop = 0; loop < S.size(); loop++) {
            if (used[loop]) {
                continue;
            }
            list += S[loop];
            used[loop] = true;
            backTrace(S);
            used[loop] = false;
            list.pop_back();
        }
    } 

    vector<string> permutation(string S) {
        if (S.size() == 0) {
            return lists;
        }

        strLen = S.size();
        used.resize(strLen);
        backTrace(S);

        return lists;
    }
};
```
