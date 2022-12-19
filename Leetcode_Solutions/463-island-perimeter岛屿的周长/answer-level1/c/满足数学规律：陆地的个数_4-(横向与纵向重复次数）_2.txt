### 解题思路
此处撰写解题思路

### 代码

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
      int n=gridSize;int m=gridColSize[0];    
      int count=0;int count_row=0;int count_col=0;int index=0;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        if(grid[i][j]==1){
                                count++;
                                index=j;
                while(index!=m-1&&grid[i][index]==grid[i][index+1]){
                                        count_row++;
                                        count++;
                                        index++;}
                j=index+1;}}}
        for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                        if(grid[i][j]==1){
                                index=i;
                while(index!=n-1&&grid[index][j]==grid[index+1][j]){
                        count_col++;
                        index++;}
                i=index+1;}}}
        int answer=count*4-(count_row+count_col)*2;
        return answer;
}
```