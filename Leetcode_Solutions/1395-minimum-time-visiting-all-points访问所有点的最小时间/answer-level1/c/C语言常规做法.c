观察发现，两点之间最短时间等于两点横坐标差值的绝对值与两点纵坐标差值的绝对值较大的那个。程序中，利用"?:"结构，可以减少变量数目，减小内存消耗。
```c
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int i,deltax,deltay,time=0;
    for(i=1;i<pointsSize;i++){
        deltax=points[i][0]>points[i-1][0]?points[i][0]-points[i-1][0]:points[i-1][0]-points[i][0];
        deltay=points[i][1]>points[i-1][1]?points[i][1]-points[i-1][1]:points[i-1][1]-points[i][1];
        time=time+(deltax>deltay?deltax:deltay);
    }
    return time;
}
```