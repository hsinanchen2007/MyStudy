### 解题思路
深度优先搜索，开始我也没有考虑要更改的颜色与原来颜色相同的情况，在执行深度优先搜索前先判断一下就行了。
当前点位置不符合规范和颜色与指定点不同为退出条件，然后对当前点的上下左右四点进行深度优先搜索。

### 代码

```cpp
class Solution {
public:
    // vector<vector<int>> image;
    int target;
    int row;
    int col;
    vector<int> t={1,0,-1,0};
    vector<int> u={0,1,0,-1};  
    int newColor; 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        this->row=image.size();
        this->col=image[0].size();
        this->target=image[sr][sc];
        this->newColor=newColor;
        if(image[sr][sc]==newColor) return image;
        dfs(image,sr,sc);
        return image;
    }
    void dfs(vector<vector<int>>& image,int x,int y){
        if(x<0||x>=row||y<0||y>=col) {return;}
        
        if(image[x][y]!=target){
            return ;
        }
        // vector<int> t={1,0,-1,0};
        // vector<int> u={0,1,0,-1};
        for(int i=0;i<4;i++){
            image[x][y]=newColor;
            dfs(image,x+t[i],y+u[i]);
        }
    }
};
```