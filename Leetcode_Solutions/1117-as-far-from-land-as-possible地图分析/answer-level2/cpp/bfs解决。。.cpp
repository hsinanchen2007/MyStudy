### 解题思路
又是看题半小时做题十分钟（转一个别人的思路，因为我没看懂题目）

作者：lately
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/
![image.png](https://pic.leetcode-cn.com/9393893fba0ffa4870d24c6e8827dee13967ba882aad02b2049e41441f302ba6-image.png)

在这里插入图片描述
看懂了题目这道题就挺简单的。就是遍历所有的陆地，然后bfs不断的一轮一轮扩大陆地

### 代码

```cpp
class Solution {
public:
    
    struct point{
      int x;
      int y;  
     
    };
    int maxDistance(vector<vector<int>>& grid) {
        queue<point> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){ //遍历所有陆地，放入队列
                if(grid[i][j] == 1)
                {
                    point a;
                    a.x = i;
                    a.y = j;
                     q.push(a);
                }
               
            }
        }
        if(q.empty() || q.size() == grid.size() * grid[0].size())//如果没有陆地或是全部都是陆地
            return -1;
        int ans = 0;
         int dir[4][2] = {{1,0}, {-1,0},{0,1}, {0,-1}};
        while(!q.empty()){
            point p = q.front();
            q.pop();
            ans = grid[p.x][p.y]; // 记录本次扩大的陆地的值

            for(int i = 0; i < 4; i++){
                int dx = p.x + dir[i][0];
                int dy = p.y + dir[i][1];
                if(dx >= 0 && dx < grid.size() &&  dy >= 0 && dy < grid[0].size()){
                    if(!grid[dx][dy]) //如果是海洋
                    {
                        grid[dx][dy] = ans + 1;
                        point b;
                        b.x = dx;
                        b.y = dy;
                        q.push(b);
                    }
                }
            }
        }
        return ans - 1 ;
    }
};
```