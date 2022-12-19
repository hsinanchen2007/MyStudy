小白。。。刚开始不理解这个gridColSize啥意思，在英文题解上看到了才懂了。看到题解还没有C语言版的给大家发一个。
还有一点不理解是count在出了if判断之后值就变了，具体是多少也看不到。有没有大神解释一下，这个应该不是全局和局部的关系吧。。
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int length = 0;
    int count;
    for(int i=0;i<gridSize;i++){
        for(int n=0;n<gridColSize[i];n++){
           // count=0;
            if(grid[i][n]==1){
                count = 0;
                if(((i+1)<gridSize)&&(grid[i+1][n]==1)){
                    count++ ;
                }
                if(((i-1)>=0)&&(grid[i-1][n]==1)){
                    count ++;
                }
                if(((n+1)<gridColSize[i])&&(grid[i][n+1]==1)){
                    count ++;
                }
                
                if(((n-1)>=0)&&(grid[i][n-1]==1)){
                    count ++;
                }
                length += (4 - count) ;
            }
           // length += (4 - count) ;
        }
    }
    return length;
}