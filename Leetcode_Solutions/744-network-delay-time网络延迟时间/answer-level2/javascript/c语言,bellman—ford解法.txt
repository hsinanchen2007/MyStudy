bellman——ford算法，按照顶点-边 2层循环，中间松弛操作即可，代码如下：
```c []
int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    int d[101];
    for (int i=1;i<=N;i++){
        d[i]=0xffff;
    }
    for (int i=0;i<timesSize;i++){
        if(times[i][0] == K){
            d[times[i][1]]=times[i][2];
        }
    }
    d[K]= 0;
    /*bellman——ford*/
    for (int i=1;i<=N;i++){
        for (int j=0;j<timesSize;j++){
            /*松弛*/
            if (d[times[j][1]]>d[times[j][0]]+times[j][2]){
                d[times[j][1]] = d[times[j][0]]+times[j][2];
            }
        }
    }
    int tmp = -1;
    for (int i=1;i<=N;i++){
        if(d[i]==0xffff){
            return -1;
        }
        tmp = tmp < d[i]?d[i]:tmp;
    }
    return tmp;
}
```

