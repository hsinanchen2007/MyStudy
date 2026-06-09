双指针的C语言实现版本
```
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    if (housesSize < 1 || heatersSize < 1) return 0;
    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);
    int i, d, pos = 0, radius = 0;
    for (i = 0; i < housesSize; ++i){
        while (pos < heatersSize - 1 && heaters[pos] < houses[i]) pos++;

        if (heaters[pos] <= houses[i]){
            d = houses[i] - heaters[pos];
            if (d > radius) radius = d;
        } else {
            d = heaters[pos] - houses[i];
            if (pos - 1 >= 0){
                int d2 = houses[i] - heaters[pos - 1];
                if (d2 < d) d = d2;
            }
            if (d > radius) radius = d;
        }
    }

    return radius;
}
```
