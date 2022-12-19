### 解题思路
把坐一个人的，两个人的，三个人的分别选出来就可以了。

### 代码

```c
//
// Created by l00286453 on 2020/4/5.
//
// n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]

int comparearry(const void *a, const void * b)
{
    int *aa = *(int **)a;
    int *bb = *(int **)b;
    if(aa[0] == bb[0]) {
        return aa[1] -bb[1];
    }
    return aa[0] - bb[0];
}

int  cacuCanSeat(int map[11])
{
    if(map[2] ==0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0 && map[8] == 0 && map[9] == 0) {
        return 2;
    }
    else if(map[4] ==0 && map[5] == 0 && map[6] == 0 && map[7] == 0 ) {
        return 1;
    }
    else if(map[2] ==0 && map[3] == 0 && map[4] == 0 && map[5] == 0 && (map[6] == 1 || map[7] == 1 || map[8] == 1 || map[9] == 1)) {
       return 1;
    }

    else if( (map[2] ==1 || map[3] == 1 || map[4] == 1 || map[5] == 1) && (map[6] == 0 && map[7] == 0 && map[8] == 0 && map[9] == 0)) {
      return 1;
    } else
    {
        return 0;
    }


}


int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){

    int map[11] = {0};
    int cnt = 0;
    int totalcnt = 2*n;
    if(reservedSeats == 0 || reservedSeatsSize == 0) {
        return totalcnt;
    }
    qsort(reservedSeats,reservedSeatsSize,sizeof(int *),comparearry);
    for(int i = 0 ; i < reservedSeatsSize; i++) {
        printf("%d %d\r\n", reservedSeats[i][0],reservedSeats[i][1]);
    }


    int line = reservedSeats[0][0];
    map[reservedSeats[0][1]]=1;
    int line1;
    for(int i = 1 ; i < reservedSeatsSize; i++) {
         line1 = reservedSeats[i][0];
         if(line1 == line) {
             map[reservedSeats[i][1]]=1;
         }
         else {
             cnt = cacuCanSeat(map);
             cnt = 2- cnt;
             totalcnt-=cnt;
             memset(map,0,sizeof(map));
             map[reservedSeats[i][1]]=1;
             line = line1;
         }
    }
    cnt = cacuCanSeat(map);
    cnt = 2- cnt;
    totalcnt -= cnt;
    return totalcnt;

}
```