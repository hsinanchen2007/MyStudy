暴力解O(n^2),这里优化到O(n).

一次遍历中记录奇数的行数(odd_rows)和列数(odd_cols)。

此时奇数行和奇数列不重叠的部分为奇数，重叠的部分则为偶数。

下面有多种数学思路，提2个：

 1.循环出来以后用数学求解。
    返回值 = odd_rows * m + odd_cols * n - 2 * odd_rows * odd_cols
 解释：先把行上的所有奇数与列上的所有奇数相加(先不管重叠部分)。再减去重叠的部分(偶数)，由于重叠部分在奇数行和奇数列中分别被当作奇数加了一次，所以减去时需要乘以2。

 2.这样想也行(结果与上相同)：
    返回值 = odd_rols * (m - odd_cols) + odd_cols * (n - odd_rows)
 解释：将奇数行不重叠的部分(奇数)与奇数列不重叠的部分(奇数)相加。


习惯性英文注释，唔介意
```
   int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        vector<bool> row(n,false) , col(m,false); //false is even, true is odd
        int odd_rows = 0, odd_cols = 0;
        for(auto &it : indices)
        {
            row[it[0]] = !row[it[0]];
            col[it[1]] = !col[it[1]];

            //for example, when row[1] change from 2->3, the odd_rows's incresed by 1
            if(row[it[0]])
                odd_rows ++;
            else
                odd_rows --;

            if(col[it[1]])
                odd_cols ++;
            else
                odd_cols --;
        }

        /*odd_rows * m + odd_cols * n adds all odd number either in rows or columnsw
          2 * odd_rows * odd_cols removes the overlaps which are even numbers */
        int res = odd_rows * m + odd_cols * n - 2 * odd_rows * odd_cols;
        return res;
    }
```

附暴力：
```
    int oddCells(int n, int m, vector<vector<int>>& indices)
    {
        vector<vector<bool>> matrix(n, vector<bool>(m, false));
        for(int i = 0; i < indices.size(); i ++)
        {
            if(indices[i][0] >= 0 && indices[i][0] <= n)
            {
                for(int j = 0; j < m; j++)
                {
                    matrix[indices[i][0]][j] = !matrix[indices[i][0]][j];
                }
            }
            if(indices[i][1] >= 0 && indices[i][1] <= m)
            {
                for(int j = 0; j < n; j++)
                {
                    matrix[j][indices[i][1]] = !matrix[j][indices[i][1]];
                }                
            }
        }

        int sum_of_odd = 0;
        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = 0; j < matrix[i].size(); j ++)
            {
                if(matrix[i][j] == true)
                    sum_of_odd ++; 
            }
        }
        return sum_of_odd;
    }
```
