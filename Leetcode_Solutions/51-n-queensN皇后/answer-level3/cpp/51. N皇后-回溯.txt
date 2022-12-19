### 解题思路
```
    void backtrack(int& n, vector<int> track){
        if(track.size() == n){
            res.push_back(track);
            return;
        }
        for(int i = 0; i < n; i++){
            // 条件
            if(find(track.begin(), track.end(), i) == track.end() && condition(track, i)){
                track.push_back(i);
                backtrack(n, track);
                track.pop_back();
            }
        }
    }
```


执行用时 :16 ms, 在所有 C++ 提交中击败了40.15%的用户

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    bool condition(vector<int>& track, int& i){
        for(int j = 0; j < track.size(); j++){
            if((track[j] - j) == (i - track.size()) || (track[j] + j) == (i + track.size())){
                return false;
            }
        }
        return true;
    }
    void backtrack(int& n, vector<int> track){
        if(track.size() == n){
            res.push_back(track);
            return;
        }
        for(int i = 0; i < n; i++){
            if(find(track.begin(), track.end(), i) == track.end() && condition(track, i)){
                track.push_back(i);
                backtrack(n, track);
                track.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rt;
        if(n == 0) return rt;
        vector<int> track;
        backtrack(n, track);
        if(!res.empty()){
            for(auto tmp: res){
                vector<string> solution;
                for(int i = 0; i < tmp.size(); i++){
                    string s;
                    for(int j = 0; j < n; j++){
                        if(j == tmp[i]) s += 'Q';
                        else s += '.';
                    }
                    solution.push_back(s);
                }
                rt.push_back(solution);
            }
        }
        return rt;
    }
};
```