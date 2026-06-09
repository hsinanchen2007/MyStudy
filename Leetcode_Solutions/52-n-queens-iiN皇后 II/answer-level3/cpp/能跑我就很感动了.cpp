### 解题思路
参考人家的代码终于看懂写出来了，从以前就觉得这个好难，别人家的代码一个比一个秀，都没看懂，直到今天

### 代码

```cpp
class Solution {
public:
    int totalNQueens(int n) {
        int **map = new int *[n];
        for(int i=0;i<n;i++){
            map[i] = new int[n]{0}; //将所有元素设为0
        }
        
        int ans = 0;
        backtracking(map,n,&ans,0);
        return ans;
    }

    bool judge_queenXY(int **map,int MAX,int x,int y){
        for(int i=0;i<MAX;i++){
            if(map[i][x] == 1 || map[y][i] == 1){ //此(x,y)格十字内存在皇后
                return false;
            }
        }
        for(int i=0,j=0;i<MAX;i++,j++){
            
            if((y+i < MAX && x+j < MAX) && map[y+i][x+j] == 1){ //最大值没有超出棋盘且右下存在皇后
                return false;
            }
            if((y-i >= 0 && x-j >= 0) && map[y-i][x-j] == 1){ //最小值没有超出棋盘且左上存在皇后
                return false;
            }
        }
        for(int i=0,j=0;i<MAX;i++,j++){
            if((y+i < MAX && x-j >= 0) && map[y+i][x-j] == 1){ //左下存在皇后
                return false;
            }
            if((y-i >= 0 && x+j < MAX) && map[y-i][x+j] == 1){ //右上存在皇后
                return false;
            }
        }
        return true; //此座标路线上没有任何皇后
    }
    bool backtracking(int **map,int MAX,int *ans,int next){
        bool put_queen = false;
        if(next == MAX){ //到最后一列都有皇后摆入 得出一个解
            ++*ans;
            return true;
        }
        for(int i=next;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                if(judge_queenXY(map,MAX,j,i)){ //检查攻击范围是否有其他皇后
                    map[i][j] = 1;
                    put_queen = true;
                    backtracking(map,MAX,ans,next+1); //进入回溯
                    
                    //进入回溯后改回原样
                    put_queen = false;
                    map[i][j] = 0;
                }
            }
            if(!put_queen) //第i行放不下任何皇后，代表走错路，浪费空间了
                return false;
        }
        return false;
    }
};
```