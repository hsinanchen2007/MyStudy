
尝试用原地算法实现了一下。我的主要想法是：假设我对board(i,j)进行从左到右（i依次增大），从上到下（j依次增大）的更新，那么在计算board(i,j)的周围8个细胞时，board(i-1,j-1)，board(i-1,j)，board(i-1,j+1)，board(i,j-1)这四个细胞的数值已经更新，将影响正确计算。所以我设置了一个boardColSize大小的一维数组，每次都将上一行的数值存储下来，并且设置一个辅助变量old，记录board(i,j-1)。

```
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int* row;
    row = (int*)malloc(*boardColSize*sizeof(int));
    int i,j,num,old;
    for(i=0;i<boardSize;i++){
        for(j=0;j<*boardColSize;j++){
            num = 0;
            if(i>0){
                num += *(row+j);
                if(j>0) num += old;
                if(j<*boardColSize-1) num += *(row+j+1);
            } 
            if(i<boardSize-1){
                num += *(*(board+i+1)+j);
                if(j>0) num += *(*(board+i+1)+j-1);
                if(j<*boardColSize-1) num += *(*(board+i+1)+j+1);
            }
            if(j>0) num += *(row+j-1);
            if(j<*boardColSize-1) num += *(*(board+i)+j+1);
            old = *(row+j);                //更新old
            *(row+j) = *(*(board+i)+j);    //更新上一行数据row
            if(*(*(board+i)+j)==0){
                if(num==3) *(*(board+i)+j) = 1;
            }
            else{
                if(num<2||num>3) *(*(board+i)+j) = 0;
            }
        }
    }
}
```
最终结果：
![1.png](https://pic.leetcode-cn.com/790ae8629d1277744578612d428358417867db8c153619746dc5195010c354cd-1.png)

运行时间较慢，我觉得主要是赋值时候指针取值占了太多时间，还可以再改进。

当然这个方法并非最好方法，看了大家的题解才知道，哦原来奥妙在巧妙利用空闲位上，再次打开了新世界的大门[捂脸]


