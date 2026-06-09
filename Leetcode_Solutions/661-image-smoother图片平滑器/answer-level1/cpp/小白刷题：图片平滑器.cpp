暴力破解，遍历数组计算平均灰度，需要注意边界情况

代码：
```
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        int col = M[0].size();
        vector<vector<int>> ans(row,vector<int>(col));
        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col ; j++) {
                int temp = M[i][j];
                int num = 1;
                if(i) {
                    temp += M[i - 1][j];
                    num++;
                    if(j) {
                        temp += M[i - 1][j - 1];
                        num++;
                    }
                    if(j < col - 1) {
                        temp += M[i - 1][j + 1];
                        num++;
                    }      
                }
                if(j) {
                    temp += M[i][j - 1];
                    num++;
                }
                if(j < col - 1) {
                    temp += M[i][j + 1];
                    num++;
                }
                if(i < row - 1) {
                    temp += M[i + 1][j];
                    num++;
                    if(j) {
                        temp += M[i + 1][j - 1];
                        num++;
                    }
                    if(j < col - 1) {
                        temp += M[i + 1][j + 1];
                        num++;
                    }
                }
                ans[i][j] = temp / num;
            }
        }
        return ans;
    }
};
```
