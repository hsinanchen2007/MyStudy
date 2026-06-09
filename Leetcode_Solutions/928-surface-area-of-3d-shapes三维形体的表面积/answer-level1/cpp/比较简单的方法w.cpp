### 解题思路

(比较简单直接QAQ)
单个方块 - 重复值

代码思路
若非空 -> 
    结果+2 (上下方面积 一定有) +4*对应方块 (侧边面积)
    减去上方、左方的重复值 (min 最小值 -> 针对高度 * 2) 针对两个方块

### 代码

```cpp
int min(int fir,int sec){
    return (fir<sec)?fir:sec;
}
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result=0,n=grid.size();
        int i=0,j=0;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]){
                    result+=2+4*grid[i][j];
                    if(i){
                        result-=2*min(grid[i-1][j],grid[i][j]);
                    }
                    if(j){
                        result-=2*min(grid[i][j-1],grid[i][j]);
                    }
                }
            }
        }
        return result;
    }
};
```