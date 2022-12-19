### 解题思路
将二维坐标和一维坐标做对应：(i,j)->i*w+j，其中w为宽，对二维数组进行遍历，若其四周存在1，则将其与当前节点并在一起。再遍历一次二维数组，由于每个岛屿的任意一点执行find操作得到的结果都是一样的，所以只需要建立find操作结果和面积area的映射map，接下来再遍历二维数组，找出一个海洋点，将其四周的陆地加起来再加一则为连通后的面积，遍历所有情况取最大值。
![image.png](https://pic.leetcode-cn.com/8220cafbdb852ceb7c95a402aac8fbf7b9b7d75fc2db32de359000b6f5e11c51-image.png)

### 代码

```cpp
class Solution {
public:
int f[2501];
int len;
void init(){
    for(int i=0;i<len;i++)f[i]=i;
}
int find(int x)
{
    if(x<0||x>=len)return -1;
    return (x==f[x]?x:f[x]=find(f[x]));
}
void merge(int x,int y)
{
    f[find(x)]=find(y);
}
    int largestIsland(vector<vector<int>>& grid) {
        if(grid.size()==1)return 1;
         int w=grid[0].size();
         int h=grid.size();
         len=w*h;
         map<int,int>area;
         init();
         bool allone=true;
         for(int i=0;i<h;i++)
         {
             for(int j=0;j<w;j++)
             {
                 if(!grid[i][j]){
                     allone=false;
                     continue;
                 }
                 if(i>0)
                   if(grid[i-1][j])
                      merge(i*w+j,(i-1)*w+j);
                 if(i<w-1)
                   if(grid[i+1][j])
                      merge(i*w+j,(i+1)*w+j);
                 if(j>0)
                   if(grid[i][j-1])
                      merge(i*w+j,i*w+j-1);
                 if(j<w-1)
                   if(grid[i][j+1])
                      merge(i*w+j,i*w+j+1);
            }
         }
          int maxn=0;
          for(int i=0;i<h;i++)
          {
              for(int j=0;j<w;j++)
              {
                   if(grid[i][j])
                     area[find(i*w+j)]++;
                   else area[i*w+j]=0;
              }
          }
          for(auto it:area)
          {
              int aa=it.second;
              if(aa>maxn)maxn=aa;
          }
          if(!allone)maxn++;
          int artp;
          for(int i=0;i<h;i++)
          {
              for(int j=0;j<w;j++)
              {
                  if(grid[i][j]==0)
                  {
                    artp=0;
                    int up,down,left,right;
                    up=find((i-1)*w+j);
                    down=find((i+1)*w+j);
                    left=find((i)*w+j-1);
                    right=find((i)*w+j+1);
                    int x=-1;
                    if(i>0)
                    {
                        artp+=area[find((i-1)*w+j)];
                    }
                    if(i<h-1){
                        if(down!=up)
                        artp+=area[find((i+1)*w+j)];
                    }
                    if(j>0){
                        if(left!=down&&left!=up)
                        artp+=area[find((i)*w+j-1)];
                    }
                    if(j<w-1){
                        if(right!=up&&right!=down&&right!=left)
                        artp+=area[find(i*w+j+1)];
                    }
                    artp++;
                    if(artp>maxn)maxn=artp;
                  }
              }
          }
          return maxn;
        } 
};
```