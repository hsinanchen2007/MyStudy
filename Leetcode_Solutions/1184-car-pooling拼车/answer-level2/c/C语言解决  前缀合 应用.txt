### 解题思路
1.辅助数组，记录每一站的上下人数
2.辅助数组求前缀和，即为每一站的乘客人数
3.判断每一站的乘客人数是否大于capacity

### 代码

```c
#define LOCATIONS_NUM 1001

// 前缀和 应用
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    if (trips == NULL || tripsSize == 0) {
        return true;
    }

    // 1.辅助数组 记录每一站的上下人数
    int locationEvent[LOCATIONS_NUM] = {0};
    for (int i = 0; i < tripsSize; i++) {
        int startLocation = trips[i][1];
        int endLocation = trips[i][2];
        locationEvent[startLocation] += trips[i][0];
        locationEvent[endLocation] -= trips[i][0];
    }

    // 2. 每一站人数即为locationEvent数组的前缀和
    int passengersArray[LOCATIONS_NUM] = {0};
    passengersArray[0] = locationEvent[0];
    for (int i = 1; i < LOCATIONS_NUM; i++) {
        passengersArray[i] = passengersArray[i - 1] + locationEvent[i]; // 前缀和
    }

    // 3. 判断每一站人数是否大于capacity
    for (int i = 0; i < LOCATIONS_NUM; i++) {
        if (passengersArray[i] > capacity) {
            return false;
        }
    }

    return true;
} 
```