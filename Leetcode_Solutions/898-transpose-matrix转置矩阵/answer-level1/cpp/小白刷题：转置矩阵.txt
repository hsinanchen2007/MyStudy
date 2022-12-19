送分题，创建新数组存储返回值，ij互换位置即可

代码：
```
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ans;
        int row = A.size();
        int col = A[0].size();
        for(int j = 0 ; j < col ; j++) {
            vector<int> v;
            for(int i = 0 ; i < row ; i++)
                v.push_back(A[i][j]);
            ans.push_back(v);
        }
        return ans;
    }
};
```
