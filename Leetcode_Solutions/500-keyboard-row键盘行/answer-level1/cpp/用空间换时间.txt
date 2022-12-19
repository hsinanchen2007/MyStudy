执行用时 : 0 ms, 在Keyboard Row的C++提交中击败了100.00% 的用户
内存消耗 : 8.6 MB, 在Keyboard Row的C++提交中击败了52.18% 的用户



```
char key[128] = {0,
0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
2,3,3,2, 1,2,2,2, 1,2,2,2, 3,3,1,1, 1,1,2,1, 1,3,1,3, 1,3,0,0, 0,0,0,0,
2,3,3,2, 1,2,2,2, 1,2,2,2, 3,3,1,1, 1,1,2,1, 1,3,1,3, 1,3,0,0, 0,0,0
};
class Solution {
public:

vector<string> findWords(vector<string>& words) {
    vector<string> s;
    bool falge;
    for (int i = 0; i < words.size(); ++i) {
        falge = true;
        for (int j = 0; j < words[i].size() - 1; ++j) {
            if (key[words[i][j]] != key[words[i][j + 1]]) {
                falge = false;
                cout<<words[i][j]<<" ";
                break;
            }
        }
        if (falge) s.push_back(words[i]);
    }    
    return s;
}
};
```
