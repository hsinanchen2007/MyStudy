### 解题思路
定义上下左右四个边界，按顺时针扫描边界的行和列，扫描完一行或者一列之后更新边界值并判断边界。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector <int> ans;
        if(matrix.empty()) return ans; 
        //定义上下左右边界
        int up = 0;
        int down = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;

        while(1)
        {
            //每次扫描完边界的行或者列，并更新边界
            for(int i=left; i<=right; i++) ans.push_back(matrix[up][i]); //上边界的左到右边界
            if(++up > down) break;                      //更新上边界
            for(int i=up; i<=down; i++) ans.push_back(matrix[i][right]); //右边界的上到下边界
            if(--right < left) break;
            for(int i=right; i>=left; i--) ans.push_back(matrix[down][i]);//下边界的右到左边界
            if(--down < up) break;
            for(int i=down; i>=up; i--) ans.push_back(matrix[i][left]);   //左边界的下到上边界
            if(++left > right) break;
        }
        return ans;
    }
};
```