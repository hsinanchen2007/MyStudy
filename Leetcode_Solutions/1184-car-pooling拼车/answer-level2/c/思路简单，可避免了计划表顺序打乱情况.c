//数组已距离点为索引，记录每个点时的乘客数量，如果乘客数量超过cap时就返回false
//避免了计划表顺序打乱情况
```
#define MAPSIZE 1001
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int passangermap[MAPSIZE] = { 0 };
    for (int i = 0; i < tripsSize; i++) {
        for (int j = trips[i][1]; j < trips[i][2]; j++) {
            passangermap[j] += trips[i][0];
            if (passangermap[j] > capacity) {
                return false;
            }
        }
    }
    return true;
}
```
