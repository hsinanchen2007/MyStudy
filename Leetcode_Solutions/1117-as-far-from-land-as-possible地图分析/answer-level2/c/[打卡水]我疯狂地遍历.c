看着我这用来遍历的变量，仿佛看见一个又一个“菜”字。
但至少写出来了，打卡以示纪念。
### 解题思路
解题的思路用四个字概括，那就是“波心荡漾”。
从海面的0点，顺着矩形的波纹，找到它的1。
+——————+
|　　　　　　|
|　　　0　　|1
|　　　　　　|
+——————+
就像这样。

### 代码

```c
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int i,j,s,n,maxi,flag1,flag2,min,tmp;
    int up,down,left,right;
    flag1=0;flag2=0;
    maxi=0;min=0;tmp=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(0==grid[i][j]){
                min=0;tmp=gridSize+gridColSize[i];
                flag1=1;  //有海洋
                for(s=1;s<=i||s<=(gridSize-j)||s<=j||s<=(gridColSize[i]-i);s++){
                    left=((j-s)>0)?(j-s):0;
                    right=((j+s)<gridSize)?(j+s):gridSize-1;
                    up=((i-s)>0)?(i-s):0;
                    down=((i+s)<gridColSize[i])?(i+s):gridColSize[i]-1;
                    for(n=left;n<=right;n++)
                        if(grid[up][n]) {min=abs(i-up)+abs(j-n);tmp=(tmp>min)?min:tmp;} // 在上面找到一个1
                    for(n=left;n<=right;n++)
                        if(grid[down][n]) {min=abs(i-down)+abs(j-n);tmp=(tmp>min)?min:tmp;} // 在下面找到一个1
                    for(n=up+1;n<down;n++)
                        if(grid[n][left]) {min=abs(i-n)+abs(j-left);tmp=(tmp>min)?min:tmp;} // 在左面找到一个1
                    for(n=up+1;n<down;n++)
                        if(grid[n][right]) {min=abs(i-n)+abs(j-right);tmp=(tmp>min)?min:tmp;} // 在右面找到一个1
                    if(min) break;
                }
            }
            else flag2=1;  //有陆地
            maxi=(maxi<tmp)?tmp:maxi;
        }
    }
    if(flag2&&flag1) return maxi;
    else return -1;
}
```