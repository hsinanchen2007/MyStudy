### 解题思路
比较直观的思路，先遍历外圈然后在递归遍历里层矩阵。

### 代码

```cpp
class Solution {
private:
    vector<int> recurFunc(vector<vector<int>>& matrix, int x, int y, int rowNum, int colNum){
        //(x, y)为遍历的起点，rowNum为当前遍历矩阵的行数，colNum为当前遍历矩阵的列数
        vector<int> res;
        //以下为递归终止条件
        if(rowNum <= 0 || colNum<= 0) return res;
        if(rowNum == 1){
            for(int i=y; i<y+colNum; i++) res.push_back(matrix[x][i]);
            return res;
        }
        if(colNum == 1){
            for(int i=x; i<x+rowNum; i++) res.push_back(matrix[i][y]);
            return res;
        }
        //遍历开始
        for(int i=y; i<(y+colNum); i++) res.push_back(matrix[x][i]); //遍历上面
        for(int i=x+1; i<(x+rowNum); i++) res.push_back(matrix[i][y+colNum-1]); //遍历右边
        for(int i=y+colNum-2; i>=y; i--) res.push_back(matrix[x+rowNum-1][i]); //遍历底部
        for(int i=x+rowNum-2; i>=x+1; i--) res.push_back(matrix[i][y]); //遍历左边
        vector<int> inside = recurFunc(matrix, x+1, y+1, rowNum-2, colNum-2); //遍历里层矩阵
        if(inside.size() > 0)res.insert(res.end(), inside.begin(), inside.end()); //拼接结果
        return res;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowNum = matrix.size();
        if(rowNum == 0) return res;
        int colNum = matrix[0].size();
        res = recurFunc(matrix, 0, 0, rowNum, colNum);
        return res;
    }
};
```