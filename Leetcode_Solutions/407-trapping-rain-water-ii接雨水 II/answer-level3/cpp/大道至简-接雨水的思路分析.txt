首先，我们还是要明确一个观点，我们必须要把题目抽象的概念具化成我们所熟悉的东西，这样写起代码来
才能够逻辑清晰，得心应手。

从 [lt42.接雨水](https://leetcode-cn.com/problems/trapping-rain-water/solution/da-dao-zhi-jian-shuang-zhi-zhen-xiang-xi-fen-xi-sh/)中我们可以得到启发，其实这不过是一个3D版的接雨水而已，联系到具体生活现实，其实很好解决。
根据“木桶效应”，
接到的雨水的高度由这个容器周围最短的“木板”来确定的。所以我们还是通过这样的想法继续构造代码。
那么问题来了，
Q1.我们要如何找到这块最短“木板”？
Q2.如何根据这块“木板”来求出雨水的容量？

(套用评论区大佬的话)
**问题1**的答案很好解决，那就是通过优先队列(最小堆priority_queue)依次放入边界信息来得到这个最短围栏高度
**问题2**的答案是根据这个最短边界这个点的位置我们进行广度优先搜索(BFS)来得到相应的邻接点的高度
如果邻节点的高度比它小，那么邻节点可储蓄的水为二者高度之差，此时在邻节点设置围栏高度为当前围栏高度即可。

明确了上述这几个步骤，那么代码也就自然而然的出来了。
(当然，具体实现代码还有一些小细节，我在注释中会表明。)

核心代码段，对应问题2
根据“木桶效应”，找到比当前节点高度要低的邻接点后，用雨水填至与当前节点持平的高度，
并把这个高度再赋予这个邻接点(自然而然的思维)

```
    if(h>heightMap[new_x][new_y])
    {
        res+=h-heightMap[new_x][new_y];
        heightMap[new_x][new_y]=h;//
    }
```

代码块：

```
//构造x,y,h的边界信息
struct Item{
    int x,y;
    int h;
    Item(int _x,int _y,int _h){
        x=_x,y=_y;
        h=_h;
    }
};

class Solution {
public:
    static constexpr int delta[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    struct cmp{
        bool operator()(const Item& a,const Item& b)
        {
            return a.h>b.h;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size()<3||heightMap[0].size()<3) return 0;
        priority_queue<Item,vector<Item>,cmp> Q;//优先队列Q

        int row=heightMap.size(),col=heightMap[0].size();
        vector<bool> mark(row*col+1,0);//设置标记数组，防止出现重复的遍历

        //将四周的边界点加入到优先队列中。
        for(int i=0;i<row;i++)
        {
            Q.emplace(i,0,heightMap[i][0]);
            mark[i*col]=1;
            Q.emplace(i,col-1,heightMap[i][col-1]);
            mark[i*col+col-1]=1;
        }
    
        for(int i=1;i<col-1;i++)
        {
            Q.emplace(0,i,heightMap[0][i]);
            mark[i]=1;
            Q.emplace(row-1,i,heightMap[row-1][i]);
            mark[(row-1)*col+i]=1;
        }

        int res=0;
        while(!Q.empty())
        {
            auto p=Q.top();//最小边界点
            int x=p.x;
            int y=p.y;
            int h=p.h;
            Q.pop();

            for(auto d:delta)//BFS
            {
                int new_x=x+d[0];
                int new_y=y+d[1];

                if(new_x<0||new_x>=row||new_y<0||new_y>=col||mark[new_x*col+new_y])  
                    continue;

                if(h>heightMap[new_x][new_y])
                {
                    res+=h-heightMap[new_x][new_y];
                    heightMap[new_x][new_y]=h;
                }

                //把当前节点的相邻邻接点放入到优先队列中
                Q.emplace(new_x,new_y,heightMap[new_x][new_y]);
                mark[new_x*col+new_y]=1;
            }
        }
        return res;
    }
};
```
