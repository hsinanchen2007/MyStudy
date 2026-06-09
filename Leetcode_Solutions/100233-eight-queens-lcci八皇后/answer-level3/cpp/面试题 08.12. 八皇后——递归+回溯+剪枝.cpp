```
class Solution {
private:
    bool Judge(vector<int>& judge, int idx) {
        int n = judge.size();
        for(int i = 0; i < n; i++) {
            if(judge[i] + n - i == idx || idx + n - i == judge[i]) {
                return true;
            }
        }
        return false;
    }
    void Dfs(vector<vector<string>>& res, vector<bool>& flag, vector<string>& arr, vector<int>& judge) {
        int n = arr.size();
        int idx = judge.size();
        if(idx >= n) {
            res.push_back(arr);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(flag[i] || Judge(judge, i)) {
                continue;
            }
            flag[i] = true;
            arr[idx][i] = 'Q';
            judge.push_back(i);
            Dfs(res, flag, arr, judge);

            flag[i] = false;
            arr[idx][i] = '.';
            judge.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> arr(n, string(n, '.'));
        vector<bool> flag(n, false);
        vector<int> judge;
        Dfs(res, flag, arr, judge);

        return res;
    }
};
```
