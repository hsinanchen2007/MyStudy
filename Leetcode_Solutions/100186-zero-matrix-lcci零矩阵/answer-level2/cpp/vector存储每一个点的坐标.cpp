不能直接遍历把遇到的值为0的点行和列全变成0，因为这会影响到其他的点
定义了一个二维数组专门用来存储值为0的坐标，然后遍历整个二维数组，根据每一个点的坐标把行和列替换成0

```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> p;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    p.push_back(t);
                }
            }
        }
        for(int k=0;k<p.size();k++)
        {
            vector<int> a=p[k];
            int i;
            for(i=0;i<matrix[a[0]].size();i++)
            {
                matrix[a[0]][i]=0;
            }
            for(i=0;i<matrix.size();i++)
            {
                matrix[i][a[1]]=0;
            }
        }
    }
};
```
