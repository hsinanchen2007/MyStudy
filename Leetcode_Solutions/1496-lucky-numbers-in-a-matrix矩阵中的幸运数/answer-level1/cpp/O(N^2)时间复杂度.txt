### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // O(n)的辅助空间save存储每行的最小元素的纵坐标save[0] = 4;(0,4)为该行的最小元素
        // 选取每列的最大元素，如果其行数所指向的纵坐标与当前坐标相同即为所求元素第4列指示0行
        vector<int> res = {};
        int col = matrix.size();
        if(col == 0) return res;
        int row = matrix[0].size();
        if(row == 0) return res;
        vector<int> save(max(col,row), -1);
        for(int i=0; i<col; ++i)
        {
            
            int target = matrix[i][0];
            save[i] = 0;
            for(int j=1; j<row; ++j)
            {
                if(target > matrix[i][j])
                {
                    target = matrix[i][j];
                    save[i] = j; // 存储最小元素的纵坐标
                }
            }
        }
        // for(int i=0; i<save.size(); ++i) cout << save[i] <<endl;
        for(int i=0; i<row; ++i)
        {
            int target = matrix[0][i];
            int cur = 0; 
            for(int j=1; j<col; ++j)
            {
                if(target < matrix[j][i]) 
                {
                    target = matrix[j][i];
                    cur = j;
                }
            }
            if(save[cur] == i) res.push_back(matrix[cur][i]);
        }
        return res;
    }
};
```