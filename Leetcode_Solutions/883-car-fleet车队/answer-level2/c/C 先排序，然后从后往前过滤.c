### 解题思路
按照每辆车的position从小到大排序，计算对应的到达终点需要的时间，对时间进行操作；
从后往前遍历；

### 代码

```c
#define ZERO 1e-6 //double型数值比较，通常设置一个比较精度
int comp(double *a, double *b){
    return *a > *b ? 1 : -1;
}
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize){
    if(position == NULL || positionSize == 0) return 0;
    if(positionSize == 1) return 1; //0和1的情况
    int fleetNum = 1; //起始值设为1
    double car[positionSize][2];
    for(int i = 0; i < positionSize; i++){
        car[i][0] = position[i];
        car[i][1] = (double)(target - position[i]) / speed[i];  //计算时间
    }
    qsort(car, positionSize, sizeof(car[0]), comp);//排序

    for(int i = positionSize - 1; i > 0; i--){

        if(car[i][1] < car[i - 1][1]){
            fleetNum++;//i车时间小于于（i-1）车时，后面的车就追不上，车队加1
        }
        else if(car[i][1] > car[i - 1][1]){
            car[i - 1][1] = car[i][1];//i车时间大于（i-1）车时，会追上且被前面的车堵上，时间为i车时间，此时车队数不增加
        }
    }
    return fleetNum;
}
```