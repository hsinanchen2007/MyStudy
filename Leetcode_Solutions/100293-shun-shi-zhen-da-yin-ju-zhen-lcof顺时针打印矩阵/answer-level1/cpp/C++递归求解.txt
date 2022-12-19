### 解题思路
依次遍历最外层，然后去掉最外层已经遍历过的元素，再递归遍历，直到matrix为空
![image.png](https://pic.leetcode-cn.com/0a480f6817b221c90844466430d982e1fe88c8ebe53978914b7508e6e469bd65-image.png)
### 代码

```cpp
class Solution {
public:
    void dfs(vector<vector<int>> matrix, vector<int>& ans) {
        if (matrix.size() == 0) {
            return;
        }
        //这个判空条件, 不要忘了
        if (matrix[0].size() == 0) {
            return;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        //首行
        for (int i = 0; i < col; i++) { 
            ans.push_back(matrix[0][i]);
        }
        //尾列
        for (int i = 1; i < row - 1; i++) {
            ans.push_back(matrix[i][col-1]);
        }
        //尾行
        for (int i = col - 1; i >= 0; i--) { 
            //前面首行已经遍历，不再重复
            if (row == 1) { 
                break;
            }
            ans.push_back(matrix[row-1][i]);
        }
        //首列
        for (int i = row - 2; i >= 1; i--) { 
            //前面尾行已经遍历，不再重复
            if (col == 1) {
                break;
            }
            ans.push_back(matrix[i][0]);
        }
        
        //去掉最外层元素
        vector<vector<int>> matrixNew;
        for (int i = 1; i < row - 1; i++) {
            vector<int> tmp;
            for (int j = 1; j < col - 1; j++) {
                tmp.push_back(matrix[i][j]);
            }
            matrixNew.push_back(tmp);
        }
        dfs(matrixNew, ans);
        return;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        dfs(matrix, ans);
        return ans;
    }
};
```