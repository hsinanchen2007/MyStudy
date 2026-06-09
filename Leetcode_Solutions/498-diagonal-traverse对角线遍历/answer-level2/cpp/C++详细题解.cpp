通过题目描述可知，要对一个以特定顺序遍历矩阵的对角线。遍历的顺序是先斜上，再斜下，以此循环。因此我们可以将一次斜上加一次斜下遍历为一个循环。

我的做法比较笨

1. 先向斜上方遍历，直到超出矩阵范围，手动将它放到向斜下方向遍历的起始位置
2. 再向斜下方遍历，直到超出矩范围，最后将它手动放到下一次循环的起始位置
3. 循环1，2步骤，直到答案的数组size 等于 matrix的元素个数

难点在于

1. 当遍历过程过半后，需要增加操作才将它放到下一次行动的起始位置。
2. 注意当遍历过程过半时，该次循环的判断条件，根据数组行数的奇偶而有所不同
```
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若矩阵为空，直接返回空的答案
        int m = matrix.size();
        int n = matrix[0].size();
        pair <int,int> temp = {0,0}; //用来遍历的point
        int flag = 1; //记录遍历过程是否过半
        while(ans.size() != m*n)
        {   //upward，这部分描述斜向上
            while(0 <= temp.first && temp.second < n)
            {
                ans.push_back(matrix[temp.first][temp.second]);
                -- temp.first;
                ++ temp.second;
            }
            ++ temp.first;
            if(flag > n/2) //当遍历过半后，要有额外的操作来将point放到正确的位置
            {
                -- temp.second;
                ++ temp.first;
            }
            //downward，这部分描述斜向下
            while(temp.first < m && 0 <= temp.second)
            {
                ans.push_back(matrix[temp.first][temp.second]);
                ++ temp.first;
                -- temp.second;
            }
            ++ temp.second;
            if(flag > m/2) ////当遍历过半后，要有额外的操作来将point放到正确的位置
            {
                -- temp.first;
                ++ temp.second;
            }
            if(flag == m/2 && m%2==0) //若在中间状态，比较特殊。
            {
                -- temp.first;
                ++ temp.second;
            }
            ++ flag;
        }
        return ans;
    }
};
```



