- 思路是遍历矩阵，每次发现1的时候向右向下延拓，找到最大的正方形边长。
1. 主函数对矩阵做一次遍历。
2. find函数用于计以当期元素为起始点延拓可得到的最大正方形面积，len为边长
3. isExit用于判断是否继续延拓
4. 由于每次延拓过程是是针对起始位置做的延拓，所以矩阵中每个元素都要遍历一次，即使该1元素在正方形中已经出现过也要再次遍历，这样可能会带来冗余计算量。
- 但是我的时间复杂度和空间复杂度都超过了90%以上，效果还不错。
1. 我猜是由于传递引用和使用内联函数的原因
2. 传引用比传值快，而且不会占用额外空间
3. 内联函数不是真正意义上的函数调用，也可以节省时间
```
int maximalSquare(vector<vector<char>>& matrix) 
    {
        int max = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                {
                    int S = find(matrix,i,j);
                    if(S > max)
                        max = S;
                }
            }
        }
        return max;
    }
    int find(vector<vector<char>>& matrix,int row,int col)
    {
        int len = 1;
        while(isExit(matrix,row,col,len))
            len++;
        return len*len;
    }
    inline bool isExit(vector<vector<char>>& matrix,int row,int col,int len)
    {
        if((row + len >= matrix.size()) || (col + len >= matrix[0].size()))
            return false;
        for(int i = 0;i<=len;i++)
        {
            if(matrix[row+len][col+i] == '0')
                return false;
            if(matrix[row+i][col+len] == '0')
                return false;
        }
        return true;
    }
```