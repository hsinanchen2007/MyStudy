class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //根据O(m+n)的空间复杂度首次想到的是只标记0元素对应的行和列
        if(matrix.empty()) return;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> up(m,0);//对应行
        vector<int> down(n,0);//对应列
        for(int i=0;i<=m-1;i++)
        {
            for(int k=0;k<=n-1;k++)
            {
                if(matrix[i][k]==0)
                {
                    up[i]=1;
                    down[k]=1;
                }
            }
        }
        for(int i=0;i<=m-1;i++)
        {
            if(up[i]==1)
            {
                for(int k=0;k<=n-1;k++)
                {
                    matrix[i][k]=0;
                }
            }
        }
        for(int k=0;k<=n-1;k++)
        {
            if(down[k]==1)
            {
                for(int i=0;i<=m-1;i++)
                {
                    matrix[i][k]=0;
                }
            }
        }
        return;
    }
};