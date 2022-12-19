### 解题思路
都递增排序
遍历每个房子：
当暖气位置大于房子位置时就不用再遍历暖气了，后面暖气离当前房子更远。记录当前房子最近暖气的位置lastj
下一个房子直接从lastj开始找，lastj右边的肯定还不如lastj近 



冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。

所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。

说明:

给出的房屋和供暖器的数目是非负数且不会超过 25000。
给出的房屋和供暖器的位置均是非负数且不会超过10^9。
只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:

输入: [1,2,3],[2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。


### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int cmp(const void* a, const void*b){
    return *(int*)a - *(int*)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    int i = 1, lastj = 0,j,temp, min = 0,item_min;

    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);

    for (i = 0; i < housesSize; i++) {
        item_min = abs(houses[i] -  heaters[lastj]);
        //对于房子和暖气都是递增排序的话， 上一个房子最近暖气的左边都不用考虑了，
        //所以从上一个房子的最近暖气开始找
        for(j = lastj; j<heatersSize; j++) {
            temp = abs(houses[i] - heaters[j]);
            if(temp < item_min){
                item_min = temp;
                lastj = j;
            }
            //对于递增排序， 如果暖气位置已经大于房子位置了， 再往下就没必要找了。
            if(heaters[j] > houses[i])
                break;
        }
        //对每个房子都找到他最近的。
        min = MAX(item_min, min);
    }
    return min;
}
```