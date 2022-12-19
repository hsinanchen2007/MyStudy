### 解题思路
BackTrace(路径，选择列表)
{
    if 退出条件
        记录结果
        退出
    for 场景 in 选择列表
        排除不符合条件的场景
        进行选择:路径增加、选择列表变化
        BackTrace(增加后的路径， 选择后的列表)
        回退选择：路径减少，选择列表回退
}
### 代码

```cpp
class Solution {
public:
    bool IsUsed(int row, int col, const set<pair<int, int>>& used)
    {
        for(auto ite = used.begin(); ite != used.end(); ite++){
            int x = ite->first;
            int y = ite->second;
            if(x == row || y == col){
                return true;
            }
            if(row - x ==  col - y || row - x ==  y - col){
                return true;
            }
        }
        return false;
    }
    void BackTrace(vector<string> sub, int n, int row, set<pair<int, int>> used)
    {
        if(row == n){
            res.push_back(sub);
            return;
        }
        for(int col = 0; col < n; col++){
            if(IsUsed(row, col, used)){
                continue;
            }
            sub[row][col] = 'Q';
            used.insert(make_pair(row, col));
            BackTrace(sub, n, row + 1, used);
            used.erase(make_pair(row, col));
            sub[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> sub(n , string(n, '.'));
        BackTrace(sub, n, 0, set<pair<int, int>>());
        return res;
    }
private:
    vector<vector<string>>  res;
};
```