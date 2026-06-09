**题解：**
>* 暴力题：因为没有用到一点点算法，就是阅读理解题。。
>* 思路一：遍历数组，若找到一个服务器，然后判断同行同列是否还存在服务器，若存在则此服务器可以参与通信
>* 思路二：分别统计每个服务器的行与列的数字和，若单个服务器的行与列的数字和都为1，那么这个服务器就不能通信

**代码如下：**
```cpp
class Solution {
public:
    //思路一：遍历数组，若找到一个服务器，然后判断同行同列是否还存在服务器，若存在则此服务器可以参与通信
    int countServers_1(vector<vector<int>>& grid) {
        int count=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==0)continue;
                bool ok=false;
                for(int k=0;k<n;++k)//判断同列是否有服务器
                    if(grid[i][k]&&k!=j){ok=true;break;}
                for(int k=0;k<m;++k)//判断同列是否有服务器
                    if(grid[k][j]&&k!=i){ok=true;break;}
                if(ok)count++;
            }
        }  
        return count;
    }
    
    //思路二：分别统计每个服务器的行与列的数字和，若单个服务器的行与列的数字和都为1，那么这个服务器就不能通信
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),count=0;
        vector<int> row(m,0),col(n,0);
        //第一次遍历：统计所有的服务器
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                    count++;
                }
        //第二次遍历：删除不能通信的服务器，就是这个服务器的行与列的服务器总和为1的要删除
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==1&&row[i]==1&&col[j]==1)
                    count--;
        return count;
    }
};
```
