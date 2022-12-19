### 解题思路
1. 深度优先遍历
2. 遍历整个数组，遇到1，ans++，ans是记录岛的个数的
3. 运行一下dfs函数，把这个岛所有陆地给我沉喽，这个岛全部的1变成0
4. 等把grid全遍历完，grid就全是0了，再把ans输出，这个ans就是我们记录的岛的个数
5. 注意：grid竟然是char类型的，所有1和0都要加单引号哦
![image.png](https://pic.leetcode-cn.com/6ca4dbcf01f5fb4db2fb7c2aff39132a93d854ec81a0d70ae3e6694e117ad554-image.png)

### 代码

```cpp
class Solution {
    void dfs(vector<vector<char>> &grid,int cur_i,int cur_j)
    {
        if(cur_i<0||cur_i==grid.size()||cur_j<0||cur_j==grid[0].size()||grid[cur_i][cur_j]=='0') return;
        grid[cur_i][cur_j]='0';
        int di[4]={0,0,1,-1};
        int dj[4]={1,-1,0,0};
        for(int index=0;index<4;index++)
        {
            dfs(grid,cur_i+di[index],cur_j+dj[index]);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j);
                } 
            }
        }
        return ans;
    }

};
```
如果觉得有帮助的话，给我点个赞吧，everybody让我看到你的双手好吗！