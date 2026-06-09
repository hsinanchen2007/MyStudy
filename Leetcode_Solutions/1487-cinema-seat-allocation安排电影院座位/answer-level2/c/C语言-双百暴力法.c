1、由于n数据太大了，而reservedSeatsSize最大是10000，以reservedSeatsSize进行循环；
2、一排最多可以做两个四人家庭；2345,6789；
3、如果本排没有人占用，则直接乘以2；
4、将reservedSeats排序，
5、循环遍历，空排直接乘以2；
6、非空排将位置标识为1，然后计算本排可以做几个家庭；
7、结束时候计算还有多少空排，直接加上即可。
![image.png](https://pic.leetcode-cn.com/393cdb96d64da9c7771943b1f5b4cd743af98793213a68ccc1208d27400230d1-image.png)

```
#define MAXLEN 11
int cmp(const void *a, const void *b)
{
    int *aptr = *(int**)a;
    int *bptr = *(int**)b;
    if(aptr[0] == bptr[0]) {
        return aptr[1] - bptr[1];
    }
    return aptr[0] - bptr[0];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int *map = malloc(sizeof(int) * MAXLEN);
    int nums = 0;
    int Rindex = 0;
    qsort(reservedSeats,reservedSeatsSize,sizeof(int*),cmp);
    int begin = 1;
    while(Rindex < reservedSeatsSize) {
        memset(map,0,sizeof(int) * MAXLEN);
        /*一排最多做两个4个家庭，如果是空，直接乘以2*/
        if(begin != reservedSeats[Rindex][0]) {
            nums += 2 * (reservedSeats[Rindex][0] - begin);
            begin = reservedSeats[Rindex][0];
        }
        /*排序后，本排已经被占用作为，修改为1*/
        while (Rindex < reservedSeatsSize && reservedSeats[Rindex][0] == begin) {
            map[reservedSeats[Rindex][1]] = 1;
            Rindex++;
        } 
        int flag = 0;
        if(map[2] == 0 && map[3] == 0 && map[4] == 0 && map[5] == 0) {
            flag++;
            nums++; 
        }
        if(map[6] == 0 && map[7] == 0 && map[8] == 0 && map[9] == 0) {
            flag++;
            nums++;
        }
        if(flag == 0 && map[4] == 0 && map[5] == 0 && map[6] == 0 && map[7] == 0) {
            nums++;
        }
        begin++;
    }
    /*一排最多做两个4个家庭，如果结尾还有空余排，直接乘以2*/
    if(begin <= n) {
        nums += 2 * (n + 1 - begin);
    }
    return nums;
}
```
