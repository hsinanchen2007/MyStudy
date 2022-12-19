题目已规定行程总长度小于1000，因此以总行程为长度开辟数组，缓存每个时刻车上乘客数量。
遍历所有行程，将行程内的人数更新到数组中。
注意：由于乘客先下后上，在行程的end位置，不需要累加。
计算过程中，一旦出现乘客人数大于车容量，即可返回false。

```c

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int passengers[1001] = { 0 };
    for (int i = 0; i < tripsSize; i++) {
        int *trip = &trips[i][0];
        for (int j = trip[1]; j < trip[2]; j++) {
            passengers[j] += trip[0];
            if (passengers[j] > capacity) {
                return false;
            }
        }
    }
    return true;
}
```