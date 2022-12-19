基本思想：
深度优先遍历，碰到1尝试找以(i,j)为左上角能构造的最大正方形；
helper用于递归求解该正方形的最大边长。
时间复杂度最差O(M*N*min(M,N)^2)，空间复杂度O(min(M,N)) (递归导致)
```
class Solution {
    int res,m,n;
public:
    int helper(vector<vector<char>>& matrix,int ix,int iy,int k)
    {
        int i=ix+k-1;
        int j=iy+k-1;
        if(i>=n || j>=m)
        return k-1;
        for(int t=iy;t<=j;t++)
        {
            if(matrix[i][t]=='0')
            return k-1;
        }
        for(int t=ix;t<i;t++)
        {
            if(matrix[t][j]=='0')
            return k-1;
        }
        return helper(matrix,ix,iy,k+1);
    }
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        n=matrix.size();
        if(n==0)
        return 0;
        m=matrix[0].size();
        res=0;
        for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            if(matrix[i][j]=='1')
            {
                matrix[i][j]='0';
                res=max(res,helper(matrix,i,j,2));
            }            
        }
        return res*res;

    }
};
```
