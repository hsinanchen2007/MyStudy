这次写的比较麻烦，总的思路分为这么几步:
- 找到所有已经腐烂的水果的坐标，放到队列中
- 按照层次遍历的方式，弹出当前队列中的所有坐标，计数器加一。在此过程中找到临近节点，并将符合条件的子节点入队
- 重复循环，直到队列为空
- 这里的条件就是不能越过边界还有必须是可以腐烂的节点，也就是值为1
- 在此过程中，需要记录腐烂的水果的个数还有总数和空白格子的个数，用来判断是否需要返回-1
```
class Solution {
public:

    //边界指示，用来污染四周
    int IndR[4] = {1,-1,0,0};
    int IndC[4] = {0,0,1,-1};
    //判断是否超过边界
    //这里判断最初出现错误
    bool static checkBorder(int i,int j,vector<vector<int>>& grid){
        if(i < 0 || j<0 || i >= grid.size()) return false;
        else if(j >= grid[i].size()) return false;
        else return true;
    }

    
    
    //说白了就是广度优先
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int res = 0;
        int blank = 0;//空白格子的个数
        int fade = 0;//腐烂的橘子
        int wholeSize = 0;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                wholeSize++;
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                    fade++;
                }else if(grid[i][j] == 0){
                    blank++;
                }
            }
        }


        while(!q.empty()){
            if(wholeSize == (blank+fade)) break;
            int len = q.size();
            for(int i = 0;i<len;i++){
                pair<int,int> front = q.front();
                q.pop();
                //污染周围的橘子
                for(int j = 0 ;j<4;j++){
                    int newR = front.first + IndR[j];
                    int newC = front.second + IndC[j];

                    
                    if(checkBorder(newR,newC,grid) && grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        q.push(make_pair(newR,newC));
                        fade++;
                    }
                }  
                
            }
            res++;   
        }
        if(wholeSize > (blank+fade)) res = -1;
        return res;


    }
};
```
