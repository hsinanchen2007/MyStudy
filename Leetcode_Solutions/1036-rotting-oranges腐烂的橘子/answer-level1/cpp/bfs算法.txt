### 解题思路
用队列实现广度优先搜索，创建orange结构体。
首先遍历一次找出输入数据中存在的腐烂的橘子（grid[i][j]==2）同时统计新鲜橘子的数量用cnt表示。
然后队列元素出队，找到四周的新鲜橘子（这里参考官方的方法用两个数组net_x和net_y,加上一个for循环）
符合条件则入队，同时time加1（可以理解成下一层）cnt减1
当队列为空时，循环结束，ans的值等于最后一次出队的元素temp的time
若cnt!=0则表示有新鲜橘子未被感染return -1
否则return ans

### 代码

```cpp
class Solution {
    int cnt=0;
    int ans;
    int net_x[4]={0,1,0,-1};
    int net_y[4]={1,0,-1,0};
    struct orange{
        int x;//橘子的横坐标
        int y;//橘子的纵坐标
        int time;//橘子被感染的时间
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j;
        orange temp,temp2;
        queue<orange> tmp;
        for(i=0;i<grid.size();i++){//第一次遍历，找出最开始的腐烂橘子
            for(j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    temp.x=i;
                    temp.y=j;
                    temp.time=0;
                    tmp.push(temp);
                }
                if(grid[i][j]==1)//统计新鲜橘子的数量
                cnt++;
            }
        }
        while(!tmp.empty()){//bfs广度优先遍历
            temp=tmp.front();
            tmp.pop();
            for(i=0;i<4;i++){
                temp2.x=temp.x+net_x[i];
                temp2.y=temp.y+net_y[i];
                if(temp2.x>=0&&temp2.x<grid.size()&&temp2.y>=0&&temp2.y<grid[temp2.x].size()&&grid[temp2.x][temp2.y]==1){//符合条件则入队；
                    temp2.time=temp.time+1;
                    tmp.push(temp2);
                    grid[temp2.x][temp2.y]++;//感染
                    cnt--;
                }
            }
        }
        ans=temp.time;
        if(cnt==0)
        return ans;
        else
        return -1;
    }
};
```