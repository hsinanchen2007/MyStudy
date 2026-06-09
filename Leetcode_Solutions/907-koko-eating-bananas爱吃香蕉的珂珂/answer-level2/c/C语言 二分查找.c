### 解题思路
问题的关键在于看到如果让koko按照最大的胃口吃香蕉，那么肯定可以在每一个小时吃一堆的情况下吃完。
那么假设速度不够，那么可能需要分为多个小时才能吃完。
从速度为1到10^9，一定存在一个临界点，使用最小的速度，刚好吃完。寻找这个临界点，就是在1-10^9之间找一个数字，可以使用二分法。
下一个是已知一个速度如何获得所用时间。
吃每一堆香蕉，时间向上取整：(num - 1)/speed + 1
累加每一堆的时间。

### 代码

```c
//能否吃完
int possible(int* piles,int pilesSize, int speed, int hour)
{
    int time = 0;
    for (int i = 0; i<pilesSize; i++) {
        time = time + (*(piles + i) - 1)/speed + 1;
    }
    if (time > hour) {
        return 0;
    }
    return 1;
}

int minEatingSpeed(int* piles, int pilesSize, int H){
    int low = 1;
    int high = (int)pow(10,9);
    int mid = 0;
    if ((NULL == piles) || (0 == pilesSize) || (0 == H)) {
        return 0;
    }
    while (low < high) {
        mid = low + (high - low)/2;
        if (!possible(piles, pilesSize, mid,H)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    //当low >=high 并且low来自某一个吃不完的mid,此mid+1一定为这个临界点。
    return low;
}
```