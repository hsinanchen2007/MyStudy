看到某位大佬提到的这种想法，不断地去填海，每次循环只填最近的可以填的海，
然后直到某一次循环时发现没有新的海可以填，此时找到最大的一个数字，其就是
离陆地最远的陆地，然后就可以得出解。
效率不高，但是比较好理解。
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //扩大陆地，向将最近的海洋赋值2，然后将2相邻的赋值为3，知道所有的海洋都不为0
        //然后找到最大的一个，计算它到最近的1的距离。
        int count = 1;
        int i,j,mindis,maxnum;
        int max_i,max_j;
        while(count > 0)
        {
            count = 0;
            for(i = 0;i < grid.size();i++)
            {
                for(j = 0;j < grid[i].size();j++)
                {
                    //cout<<grid[i][j];
                    if(grid[i][j] != 1)//为海洋或者被填的海洋，因为被填的海洋有可能填的不是最近的方式
                    {
                        mindis = INT_MAX;
                        if(i-1 >= 0)//上
                        {
                            if(grid[i-1][j] != 0&&grid[i-1][j]<mindis)
                            {
                                mindis = grid[i-1][j];
                            }
                        }
                        if(i+1 < grid.size())//下
                        {
                            if(grid[i+1][j] != 0&&grid[i+1][j] < mindis)
                                mindis = grid[i+1][j];
                        }
                        if(j-1 >= 0)//左
                        {
                            if(grid[i][j-1] != 0&&grid[i][j-1] < mindis)
                                mindis = grid[i][j-1];
                        }
                        if(j+1 < grid[i].size())//右
                        {
                            if(grid[i][j+1] != 0&&grid[i][j+1] < mindis)
                                mindis = grid[i][j+1];
                        }
                        if(mindis != INT_MAX)
                        {
                            mindis++;
                            if(grid[i][j] == 0||mindis < grid[i][j])
                            {
                                grid[i][j] = mindis;
                                count++;
                            }
                        }
                    }
                }
                //cout<<endl;
            }
        }
        maxnum = 0;
        for(i = 0;i < grid.size();i++)
        {
            for(j = 0;j<grid[i].size();j++)
            {
                //cout<<grid[i][j];
                if(maxnum < grid[i][j])
                {
                    maxnum = grid[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
            //cout<<endl;
        }
        if(maxnum == 1)
            return -1;
        return maxnum-1;
    }
};