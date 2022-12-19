### 解题思路
根据H和堆数，找到速度的上下界，然后使用二分查找求左边界的模板来解题。

### 代码

```c
int hours(int* piles, int pilesSize, int speed)
{
    int res = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] % speed == 0) {
            res += piles[i]/speed;
        }
        else {
            res += piles[i]/speed + 1;
        }
    }
    return res;
}

int minEatingSpeed(int* piles, int pilesSize, int H){
    //times表示平均每个堆吃的小时数, 
    int times = H / pilesSize;
    
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < pilesSize; i++) {
        min = fmin(min, piles[i]);
        max = fmax(max, piles[i]);
    }
    
    int min_speed = times > 1 ? (min - 1)/(times-1) : min;
    if (min_speed == 0) {
        min_speed = 1;
    }
    int max_speed = max / times + 1;
    int res = 0;
    while (min_speed <= max_speed) {
        int mid = min_speed + (max_speed - min_speed)/2;
        if (hours(piles, pilesSize, mid) == H) {
            max_speed = mid - 1;
        }
        else if (hours(piles, pilesSize, mid) > H) {
            min_speed = mid + 1;
        }
        else if (hours(piles, pilesSize, mid) < H) {
            max_speed = mid - 1;
        }
    }
    return min_speed;
}
```