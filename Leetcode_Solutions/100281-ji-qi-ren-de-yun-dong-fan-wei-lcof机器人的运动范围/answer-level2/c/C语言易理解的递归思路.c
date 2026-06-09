**从（0.0）开始，每次都可以走四个方向，但走过的格子用1标记，就不再继续走了，没有走过的格子如果数位和大于k也就不再继续走了。
开了一个move函数模拟每次走的情况。**

```
void move(int **mark, int *number, int x, int y, int m, int n, int k)
{//x和y代表目前坐标，number记录可行的格子数量，mark模拟了一个m*n的二维数组
    if( x < m && y < n && 0 <= x && 0 <= y ){
        if( x/10+x%10+y/10+y%10 <= k && mark[x][y] != 1 ){
            mark[x][y] = 1;//走过的记录1，下次移动到这里就不继续走了
            move(mark,number,x+1,y,m,n,k);//向下移动一格
            move(mark,number,x,y+1,m,n,k);//向右移动一格
            move(mark,number,x-1,y,m,n,k);//向上移动一格
            move(mark,number,x,y-1,m,n,k);//向左移动一格
            (*number)++;//每次进入if的格子必定是满足条件的，所以number+1
        }
    }
}

int movingCount(int m, int n, int k){
    int x=0, y=0, number=0, i=0;
    int **mark = (int **)malloc(m*sizeof(int*));
    for( i=0; i<m; i++ ){
        mark[i] = (int *)calloc(n,sizeof(int));//给每行申请一个n*int的空间，calloc把每个数都清0
    }
    move(mark, &number, x,  y, m, n, k);
    return number;
}
```
