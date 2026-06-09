vector<bool> haveFind；z



```
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int numStu = M.size();
        int ans = 0;
        vector<bool> haveFind(numStu, false);
        for (int i=0; i<numStu; ++i) {
            if (haveFind[i] == false) {
                ++ans;
                Dfs(M, haveFind, i, numStu);
            }
        }
        return ans;
    }
private:
    void Dfs(vector<vector<int>>& M, vector<bool> &haveFind, int stu, int numStu)
    {
        haveFind[stu] = true;
        for (int i=0; i<numStu; ++i) {
            if (i != stu && M[stu][i] == 1 && haveFind[i] == false) {
                Dfs(M, haveFind, i, numStu);
            }
        }
        return;
    }
};
```
