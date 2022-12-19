//差分算法
/*5.2	差分介绍
对于数组array[N]中的某一段进行增减操作，通过差分可在O（n）时间内完成。如
trips = [[2,1,5],[3,3,7]]
第一步：更新array[1] = 2(表示上车), array[5] = -2(表示下车了);
第二步：更新array[3] = 3(表示上车), array[7] = -3(表示下车了);
第三步：进行求和,得到结果array[] = {0,2,2,5,5,3,3,0};*/
/*#define MAX_SIZE 1001
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int array[MAX_SIZE] = {0};
    int sum[MAX_SIZE] = {0};
    int i,j;
    //对数组进行计算，计算当前每个地点都剩余多少人
    for (i = 0; i < tripsSize; i++) {
        array[trips[i][1]] = array[trips[i][1]] + trips[i][0];
        array[trips[i][2]] = array[trips[i][2]] + (-trips[i][0]);
    }

    sum[0] = array[0];
    //printf("array[0]=%d",array[0]);
    if (sum[0] > capacity) {
        return false;
    }
    //对剩余每个点的人数进行求和，能够求出每个地点的最大人数
    for (i = 1; i < MAX_SIZE; i++) {
        //printf("array[%d]=%d",i,array[i]);
        sum[i] = sum[i - 1] + array[i];
        if (sum[i] > capacity) {
            return false;
        }
    }
    return true;
}*/

#define MAX_SIZE 1001
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int array[MAX_SIZE] = {0};
    int sum[MAX_SIZE] = {0};
    int i,j;
    //对数组进行计算，计算当前每个地点都剩余多少人
    for (i = 0; i < tripsSize; i++) {
        //对这个每个地点的人数进行加减
        //比如2 1 5 ， 则array[1]=2,array[2]=2,array[3]=2,array[4]=2,array[5]=0
        //比如3 3 7 ， 则                      array[3]=3,array[4]=3,array[5]=3,array[6]=3,array[7]=0
        //进行求和，就是{0,2,2,5,5,3,3,0}
        for (j = trips[i][1]; j < trips[i][2]; j++) {
            array[j] = array[j] + trips[i][0];
        }
        // 最后一个站点下车，array[5]=0,
    }

    //对剩余每个点的人数进行求和，能够求出每个地点的最大人数
    for (i = 0; i < MAX_SIZE; i++) {
        //printf("array[%d]=%d\n",i,array[i]);
        if (array[i] > capacity) {
            return false;
        }
    }
    return true;
}