执行用时 :116 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :22.6 MB, 在所有 C++ 提交中击败了100.00%的用户
状态机性能100%，无敌！周赛中，写这题花了将近半小时，哭辽
时间复杂度：O(m*n),m,n为地图的长和宽
# **解法思路：（代码详细注释）**
基于状态机原理，实现了路径变向有向图。
**下面展示了从各个状态出发，可能的下一个状态**
**从street1出发：**
![image.png](https://pic.leetcode-cn.com/3ffee35f62b6a8bccd6daebaae0d8a17b3b8632da228dc009df93172a6227acb-image.png)
**从street2出发：**
![image.png](https://pic.leetcode-cn.com/02d0f98fc53276a66506d241dc8056b66e44cdf92b04add753a543a939453513-image.png)
**从street3出发：**
![image.png](https://pic.leetcode-cn.com/4e9f7750dca52be41d94e38d218d21d37ae144d30ada7f3d32bd8e8af7898479-image.png)
**从street4出发：**
![image.png](https://pic.leetcode-cn.com/24ccad423e6bda58e0d003559cb8e3dbdfe7aca628290910827a6761cf12812e-image.png)
**从street5出发：**
![image.png](https://pic.leetcode-cn.com/9c2245cf27e5c8eafdd8c89de088fc641f66f7dfe670f7b69e985d401a94e32a-image.png)
**从street6出发：**
从状态转移过程中得到12个转移值，并合成了dp数组
![image.png](https://pic.leetcode-cn.com/113a54e218f8cd9b76851ecc6923f6204ec894f00d85dec72faa97a3106b09b6-image.png)
也就是要确定从位置s[i]到s[i+1]的方向，从而利用grid确定位置s[i+1]可以行进的方向。
**核心：**
**定义dp[d][g]:以方向d从位置s[i]到达s[i+1],位置s[i+1]是第g种路口，dp[d][g]就表示从位置s[i+1]离开的方向**
每次的变向有上下左右4个方向，第二次变向去掉到来的方向，还有3种可能，从而得知一共只有12种状态，也就是dp数组中大于等于0的值
```
class Solution {
public:
    bool onfoot(int direction,vector<vector<int>>& grid){
        int curx=0,cury=0;
        int dirx[]={-1, 0, 1, 0};//dirx,diry组成了4个列向量，分别是四个方向的单位向量
        int diry[]={ 0, 1, 0,-1};
        //dp[d][t]:沿着d方向，到了t路口，其下一个方向值，用direction=dp[direction][grid[x][y]]更新下一位置的步进方向
        int dp[4][7]={
            {-1, -1,  0,  3,  1, -1, -1},
            {-1,  1, -1,  2, -1,  0, -1},
            {-1, -1,  2, -1, -1,  3,  1},
            {-1,  3, -1, -1,  2, -1,  1},
        };
        if (0 == grid.size()-1 && 0 == grid[0].size()-1)
                return true;//起点就是目的地
        while(0 <= curx && curx < grid.size() && 0 <= cury && cury < grid[0].size()){
            curx+=dirx[direction];//朝着direction方向前进一个单位
            cury+=diry[direction];
            if (curx >= 0 && cury >= 0 && curx < grid.size() && cury < grid[0].size())
                direction=dp[direction][grid[curx][cury]];//更新下一次行走的方向
            if (direction<0)
                return false;//无法行走，可能是两种路口不相通
            if (curx == grid.size()-1 && cury == grid[0].size()-1)
                return true;//到达目的地
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int direction=-1;//北东南西：0,1,2,3
        if (grid[0][0]==1 || grid[0][0]==6)//起始只能向右
            return onfoot(1,grid);
        if(grid[0][0]==2 || grid[0][0]==3)//起始只能向左
            return onfoot(2,grid);
        if (grid[0][0]==4)//起始能向左或向左
            return (onfoot(2,grid) || onfoot(1,grid));
        return false;
    }
};
```
