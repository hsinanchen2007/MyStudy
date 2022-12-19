### 解题思路
方法一：(DFS) O(N)
洪水填充/简单染色问题。

1.当前点(x,y)的四周可以借助两个数组来表示，dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}，那么四周的坐标分别是x=sr+dx[i],y=sc+dy[i],i=0,1,2,3x=sr+dx[i],y=sc+dy[i],i=0,1,2,3
2.依次检查当前点的四个邻接点是否满足条件（颜色一样），是的话递归调用floddFill()

方法二：(BFS) O(N)

1.从当前像素点(sr, sc)开始，修改颜色，并遍历四周，相同颜色则加入queue
2.没有得加的时候，从queue中取出像素点，设置为当前像素点
3.重复1、2，直到queue为空

注意，要用一个额外的二维数组表示某个点是否进入过queue，避免重复进入。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //if(image.empty() || image[0].empty()) 
           // return image;
        int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
        int oldColor = image[sr][sc];
        if(oldColor == newColor) //颜色相同则原路返回
            return image;
        image[sr][sc] = newColor;
        for(int i=0;i<4;i++){
            int x = sr+dx[i],y=sc+dy[i];
            if(x>=0 && x<image.size() && y<image[0].size() && y>=0 && image[x][y]== oldColor)//边界条件 注意x行y列
                floodFill(image,x,y,newColor);
        }
        return image;
    }
};
```