
DB,分左上和右下，理解点有两条：

1.左上一遍，右下一遍一定可以完成目标。我们可以假设一个矩阵中只有有一个0，在正向遍历时没遇到这个0之前都是无效的，相当于没更新，当遇到这个0之后的其右下方得到正确更新，那么反向传递时就可以正确更新之前的点；当0多于一个时，每个0的上下左右紧邻的点在两次循环中都可以确定为正确值（即1），然后这些紧邻的点的正确值向四周扩散，可以传递性的扩散到每个非0点，这种扩散碰撞时就取更小的。（玄学解释，手动画图理解0_0）

2.初始将每个值设置为INT_MAX-1，是因为在min(dist[i-1][j]+1,dist[i][j])中的dist[i-1][j]+1，设置为INT_max-1可以防止超出INT的正数范围。

```
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX-1));

        //左上
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0)dist[i][j]=0;
                else{
                    if(i>0)dist[i][j]=min(dist[i][j],dist[i-1][j]+1);
                    if(j>0)dist[i][j]=min(dist[i][j],dist[i][j-1]+1);

                }
            }
        }
        //右下
        for(int i=rows-1;i>=0;i--)
            for(int j=cols-1;j>=0;j--){
                if(matrix[i][j]==0)continue;
                else{
                    if(i<rows-1)dist[i][j]=min(dist[i+1][j]+1,dist[i][j]);
                    if(j<cols-1)dist[i][j]=min(dist[i][j+1]+1,dist[i][j]);
                }
            }

        return dist;
    }
```
