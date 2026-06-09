没有自己写排序算法直接调用了c++ sort
```
class Solution {
public:
    string customSortString(string S, string T) {
        
        int res[26];

        //记录每个字母出现的顺序
        for (int i = 0; i < S.size(); i++)
        {
            res[S[i] - 'a'] = i;
        }

        //调用sort函数对T进行排序
        sort(T.begin(), T.end(), [res](char a, char b){
            return res[a-'a'] < res[b-'a'];
        });
        return T;
    }
};
```

欢迎各位大哥指点哈新手上路
