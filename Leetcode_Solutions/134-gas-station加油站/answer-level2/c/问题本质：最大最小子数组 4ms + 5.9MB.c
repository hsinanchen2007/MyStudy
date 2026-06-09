### 解题思路
1、判断是否可以循环就看累计的油是不是正数就行。
2、从哪里出发的问题可以当做最大最小子数组的问题考虑。
2.1 假设从i到j累积的油是最多的，那么从i出发肯定可以循环。于是找最大子数组就行。
2.2 假设最大子数组跨越了数组最后和开头，那么常规的最大子数组算法就不行了。但这种情况下，最小子数组肯定没有跨越分界点，于是找最小子数组，从最小子数组后的一个点出发肯定可以循环。
2.3 比较最大子数组和最小子数组的绝对值，小的那个就是跨了分界点的，取另一个的结果就行。

### 代码

```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int left_gas, *diff;
    int i, last_p1, last_p2, start_p, cur_gas, left_max, left_min;

    left_gas = 0;
    diff = malloc(sizeof(int) * gasSize);
    for (i = 0; i < gasSize; i++) {
        diff[i] = gas[i] - cost[i];
        left_gas += diff[i];
    }
    if (left_gas < 0) {
        return -1;
    }

    //最大子数组
    last_p1 = 0;
    start_p = 0;
    cur_gas = 0;
    left_max = 0;
    for (i = 0; i < gasSize; i++) {
        cur_gas += diff[i];
        if (cur_gas < 0) {
            start_p = i + 1;
            //printf("change start_p [%d]\n", start_p);
            cur_gas = 0;
        } else {
            if (cur_gas > left_max) {
                left_max = cur_gas;
                last_p1 = start_p;
            }
        }
    }

    //最小子数组
    last_p2 = 0;
    cur_gas = 0;
    left_min = 0;
    for (i = 0; i < gasSize; i++) {
        cur_gas += diff[i];
        if (cur_gas > 0) {
            //printf("change last_p2 [%d]\n", last_p2);
            cur_gas = 0;
        } else {
            if (cur_gas < left_min) {
                last_p2 = i + 1;
                left_min = cur_gas;
            }
        }
    }
    //printf("max %d, min %d\n", left_max, left_min);

    if (left_max + left_min >= 0) {
        return last_p1;
    } else {
        return last_p2;
    }

}
```