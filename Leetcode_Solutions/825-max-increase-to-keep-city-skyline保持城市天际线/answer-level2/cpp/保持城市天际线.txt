1.定义两个容器分别存储每行每列中的最大值，行的最大值好求，列的最大值通过转置之后便和行求的最大值方法相同
2.计算原始矩阵中的总和
3.找规律，其实最后的矩阵
水平方向：8，7，9，3
垂直方向：9，4，8，7
形成的新矩阵：min(8,9),min(8,4),min(8,8),min(8,7)
             min(7,9),min(7,4),min(7,8),min(7,7)
             min(9,9),min(9,4),min(9,8),min(9,7)
             min(3,9),min(3,4),min(3,8),min(3,7)
其实形成的新矩阵就是对于每个水平方向的值通过和竖直方向的值做比较取较小值，形成新矩阵的一行
4.最终结果：新矩阵的和-原来矩阵的和
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum=0;
        vector<int> a;//存放水平方向的各个行中的最大值
        vector<int> b;//存放竖直方向上各个行中的最大值
        int hang;
        int lie;
        int **g;
        int len=grid.size();
        g=(int **)malloc(sizeof(int *)*len);
        for(int i=0;i<len;i++)
        {
            g[i]=(int *)malloc(sizeof(int)*len);
        }//动态定义新数组
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            g[j][i]=grid[i][j];//g用来存放grid的转置
        }
        for(int i=0;i<grid.size();i++)
        {
            lie=0;
            hang=0;
            for(int j=0;j<grid[i].size();j++)
            {
                sum=sum+grid[i][j];//计算原来矩阵的和
                lie=max(lie,g[i][j]);//取该列中的最大值
                hang=max(hang,grid[i][j]);//取该行中的最大值
            }
            a.push_back(hang);
            b.push_back(lie);
        }
        int sums=0;
        for(int i=0;i<a.size();i++)
        {
            int value=a[i];
            for(int j=0;j<b.size();j++)
            {
                int value1=min(value,b[j]);//每次取两者中的最小值来形成新的矩阵
                sums+=value1;//新矩阵的总和
            }
        }
        int values=sums-sum;
        return values;
    }
};