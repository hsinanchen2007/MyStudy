仔细观察，顺时针旋转一周是有规律的。所以以顺时针旋转一周为周期，根据所得到的规律直接赋值即可。
```
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        if(m==0)
            return ans;
        if(m==1)
            return matrix[0];
        int n=matrix[0].size();
        int num=0,k=0;
        while(num<m*n)
        {
            for(int i=k;i<n-k;i++)
            {
                ans.push_back(matrix[k][i]);
                num++;
                if(num==m*n)
                    return ans;
            }
            for(int i=k+1;i<m-k;i++)
            {
                ans.push_back(matrix[i][n-k-1]);
                num++;
                if(num==m*n)
                    return ans;
            }
            for(int i=n-k-2;i>=k;i--)
            {
                ans.push_back(matrix[m-k-1][i]);
                num++;  
                if(num==m*n)
                    return ans;      
            }
            for(int i=m-k-2;i>=k+1;i--)
            {
                ans.push_back(matrix[i][k]);
                num++;
                if(num==m*n)
                    return ans;
            }
            k++;
        }
        return ans;
    }
```
