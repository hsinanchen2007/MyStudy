### 解题思路
这题其实学过数据结构的很容易想到用广度优先的方法来写，必须要借助栈的结构来进行。 有个小tips，索引的时候用 /和%分别得到其行标和列标。

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        int m=grid.size(), n=grid[0].size();
        int temp=0;
        int cout=0;
        for (int i=0;i<m*n;i++)
            {           
                if(grid[i/n][i%n]==2) q.push(i);
                
            }
            bool flag=0;
        if(q.empty()) flag=1;
        while(!q.empty())
        {
            int sizeq= q.size();
            for(int j=0;j<sizeq;j++)
            {
            temp=q.front();
            //传染
            if(temp/n-1>=0){
                if(grid[temp/n-1][temp%n]==1) {
                    grid[temp/n-1][temp%n]=2;
                    q.push(n*(temp/n-1)+temp%n);
                }
            }
            if((temp/n+1)<m){
                if(grid[temp/n+1][temp%n]==1) {
                    grid[temp/n+1][temp%n]=2;
                    q.push(n*(temp/n+1)+temp%n);
                }
            }
            if(temp%n-1>=0){
                if(grid[temp/n][temp%n-1]==1) {
                    grid[temp/n][temp%n-1]=2;
                    q.push(n*(temp/n)+temp%n-1);
                }
            }
            if(temp%n+1<n){
                if(grid[temp/n][temp%n+1]==1) {
                    grid[temp/n][temp%n+1]=2;
                    q.push(n*(temp/n)+temp%n+1);
                }
            }
            q.pop();
            }  
            cout=cout+1;

        }
        for (int i=0;i<m*n;i++)
            {           
                if(grid[i/n][i%n]==1) return -1;
                
                
            }

        if(flag) return 0;
        
        return cout-1;


    }
};
```