![image.png](https://pic.leetcode-cn.com/c695ad60448f343e78dd7d8a6377b5e8abf4649a77a659da0240c06977df0223-image.png)

### 解题思路
利用差分可以避免两轮for循环，仅在上、下车时记录人数变化，从开始到某一点的累计和就是该点的人数

### 代码

```c
#define MAX_NUM 1001

int locationInfo[MAX_NUM]; /* 用于存放每个位置的人数 */

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int preSum = 0;

    if (trips == NULL || tripsSize <= 0 || tripsColSize == NULL || capacity <= 0) {
        return false;
    }

    memset(locationInfo, 0, MAX_NUM * sizeof(int));

    for (int i = 0; i < tripsSize; i++) {
        locationInfo[trips[i][1]] += trips[i][0]; // 上车
        locationInfo[trips[i][2]] -= trips[i][0]; // 下车
    }

    for (int i = 0; i < MAX_NUM; i++) {
        preSum += locationInfo[i];
        if (preSum > capacity) {
            return false;
        }
    }

    return true;
}
```

差分：差分即相邻两个数的差
差分和前缀和的知识可以参考：[https://www.cnblogs.com/MS903/p/11244969.html](https://www.cnblogs.com/MS903/p/11244969.html)