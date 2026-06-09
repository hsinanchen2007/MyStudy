先将原矩阵值为零的位置在输出矩阵中设为0，其他位置为最大值。
再从左到右从上到下走一遍：输出矩阵中某点的值如果已经是0，那么就跳过，否则为【左边，上边】中最小的那个加1.
最后从右到左从下到上反着来一遍：输出矩阵中某点的值如果已经是0，那么就跳过，否则为【右边，下边】中最小的那个加1.
```
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> distances;
        int n=matrix.size();
        int m=matrix[n-1].size();
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int> temp;
            for(j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    temp.push_back(0);
                }
                else
                    temp.push_back(100);
            }
            distances.push_back(temp);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(distances[i][j]!=0)
                {
                    if(i!=n-1&&j!=m-1)
                    {
                        if(distances[i+1][j+1]==0)
                            distances[i][j]=2;
                    }
                    if(i!=0)
                    {
                        if(distances[i][j]>distances[i-1][j])
                        {
                            distances[i][j]=distances[i-1][j]+1;
                        }
                    }
                    if(j!=0)
                    {
                        if(distances[i][j]>distances[i][j-1])
                        {
                            distances[i][j]=distances[i][j-1]+1;
                        }
                    }
                    if(i!=n-1)
                    {
                        if(distances[i+1][j]==0)
                            distances[i][j]=1;
                    }
                    if(j!=m-1)
                    {
                        if(distances[i][j+1]==0)
                            distances[i][j]=1;
                    }
                }
            }
        }
        
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(distances[i][j]!=0)
                {
                    if(i!=n-1)
                    {
                        if(distances[i][j]>distances[i+1][j])
                        {
                            distances[i][j]=distances[i+1][j]+1;
                        }
                    }
                    if(j!=m-1)
                    {
                        if(distances[i][j]>distances[i][j+1])
                        {
                            distances[i][j]=distances[i][j+1]+1;
                        }
                    }
                }
            }
        }
        return distances;
    }
};

```