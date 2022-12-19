
    int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
        int maxtop[gridSize];
        int maxleft[gridColSize[0]];
        int count = 0;
        
        for(int i = 0; i < gridColSize[0]; i++)
            maxtop[i] = 0;
        
        //找到左边和顶部的天际线
        for(int i = 0; i < gridSize; i++){
            maxleft[i] = 0;
            for(int j = 0; j < gridColSize[i]; j++){
                maxleft[i] = maxleft[i] >= grid[i][j]?maxleft[i]:grid[i][j];
                maxtop[j] = maxtop[j] >= grid[i][j]?maxtop[j]:grid[i][j];
            }
        }

        //计算出每一个数能够增高的层数，并将其累加
        for(int i = 0; i < gridSize; i++){
            for(int j = 0; j < gridColSize[i]; j++){
                //不能超过两边最小的那个数            
                count += (maxleft[i] <= maxtop[j] ? maxleft[i]:maxtop[j])-grid[i][j];
            }
        }
        
        return count;
    }