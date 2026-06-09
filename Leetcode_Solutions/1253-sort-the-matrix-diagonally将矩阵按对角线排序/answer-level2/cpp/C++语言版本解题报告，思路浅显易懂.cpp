### 解题思路
没有想到其他办法，就使用了最直接的办法，遍历每个斜行把元素拿过来，然后sort一下，再把元素赋值回去
getValues就是取当前斜行的所有元素，sort排序，然后setValues把拍好序的元素赋值。

详细的分析可以看参考一下博客[1329.将矩阵按对角线排序](http://www.iaccepted.net/algorithm/leetcode/241.html)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //本文由iaccepted发表在凌风技术站的leetcode分类下，该分类会持续更新所有leetcode题目解析
        int i, j;
        int rows, cols;
        vector<int> res;
        
        rows = mat.size();
        cols = mat[0].size();
        for (i = 0; i < rows; i++) {
            getValues(mat, res, i, 0);
            sort(res.begin(), res.end());
            setValues(mat, res, i, 0);
        }
        
        for (i = 0; i < cols; i++) {
            getValues(mat, res, 0, i);
            sort(res.begin(), res.end());
            setValues(mat, res, 0, i);
        }
        return mat;
    }
    
private:
    void getValues(vector<vector<int>> &mat, vector<int> &res, int x, int y) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        res.clear();
        while (x < rows && y < cols) {
            res.push_back(mat[x][y]);
            ++x;
            ++y;
        }
    }
    
    void setValues(vector<vector<int>> &mat, vector<int> &res, int x, int y) {
        int size = res.size();
        int i;
        
        for (i = 0; i < size; i++) {
            mat[x][y] = res[i];
            ++x;
            ++y;
        }
    }
};
```