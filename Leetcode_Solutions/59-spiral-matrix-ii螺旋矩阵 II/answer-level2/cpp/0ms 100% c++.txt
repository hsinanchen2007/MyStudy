```
//螺旋矩阵
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=0,j=0,len=n*n,temp_i,temp_j;
        vector<vector<int>> vec(n,vector<int>(n,0));
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};//四个方向依次循环走
        int index=0;
        for(int k=1;k<=len;k++)
        {
            vec[i][j]=k;//填值
            temp_i=i+direction[index%4][0];
            temp_j=j+direction[index%4][1];
            if(temp_i<n&&temp_i>=0&&temp_j<n&&temp_j>=0&&vec[temp_i][temp_j]==0)//当超过边界或节点未填充时 向前走一步
            {
                i=temp_i;
                j=temp_j;
            }
            else//已经超过边界时 改变前进方向
            {
                index++;
                i+=direction[index%4][0];
                j+=direction[index%4][1];
            }
        }
        return vec;
    }
};
```
