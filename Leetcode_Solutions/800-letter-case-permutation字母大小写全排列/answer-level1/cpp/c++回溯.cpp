回溯就是从根节点沿着DFS路径一路向下探，到达终点时，将整个路径path上的节点保存即可；当某条路不通时，无需继续向下探索；由深层次节点回到浅层次节点，状态重置；
针对每个遍历位置（或者遍历节点）处，此题有两种情况：一种保持原样继续递归；另一种递归结束回到初始情况处，变为相反状态，在向下探；

```
class Solution {
public:
    vector<string> res;
    void backtrace(string S, int pos)
    {
        if (pos == S.size()) {
            res.push_back(S);
            return;
        }
        //只有两种选择，要么大写，要么小写
        if (!isalpha(S[pos])) {
            backtrace(S,pos+1);
        }
        else {
            if (S[pos] >= 'a' && S[pos] <= 'z') {
                backtrace(S, pos + 1);
                S[pos] = toupper(S[pos]);
                backtrace(S, pos + 1);
            }
            else if (S[pos] >= 'A' && S[pos] <= 'Z') {
                backtrace(S, pos + 1);
                S[pos] = tolower(S[pos]);
                backtrace(S, pos + 1);
            }
        }
    }
    vector<string> letterCasePermutation(string S) 
    {
        //每个字母转变大小写，加到res中
        backtrace(S, 0);
        return res;
    }
};
```
