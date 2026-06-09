顺时针打印矩阵，其与[54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)一致。自己完全写复杂了，题解里的方法却写的极其的简洁优美。
```
class Solution {
public:

    void Rotate(int sr, int er, int sc, int ec, int& k, vector<vector<int>>& matrix, vector<int>& ans)
    {
        if (sr > er || sc > ec)
            return;
        
        bool mR = false, mD = false, mL = false;

        /**
        * 先往右
        **/
        int i = sc;
        while(i <= ec)
        {
            mR = true;
            ans[k++] = matrix[sr][i++];
        }
        
        /**
        * 再往下
        **/
        i = sr+1;
        while(mR && i <= er)
        {
            mD = true;
            ans[k++] = matrix[i++][ec];
        }
        
        /**
        * 再往左
        **/
        i = ec-1;
        while(mD && i >= sc)
        {
            mL = true;
            ans[k++] = matrix[er][i--];
        }

        /**
        * 再往上,注意:起始行起始列的元素已经包含了,不需要重复包含
        **/
        i = er-1;
        while(mL && i > sr)
            ans[k++] = matrix[i--][sc];

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return vector<int>();
        
        int rbegin = 0, rend = matrix.size()-1;
        int cbegin = 0, cend = matrix[0].size()-1;

        vector<int> ans(matrix.size()*matrix[0].size());
        int k = 0;

        while(rbegin <= rend && cbegin <= cend)
        {
            Rotate(rbegin, rend, cbegin, cend, k, matrix, ans);

            /**
            * 缩小包围圈
            **/
            rbegin += 1;
            rend -= 1;
            cbegin += 1;
            cend -= 1;
        }

        return ans;
    }
};
```
