```
struct Time {
    int begin;
    int end;
};
#define MAX_SIZE 200000
int Comp(void *a, void *b) {
    struct Time *x = a;
    struct Time *y = b;
    return (*x).begin - (*y).begin;
}
int* minAvailableDuration(int** slots1, int slots1Size, int* slots1ColSize, int** slots2, int slots2Size, int* slots2ColSize, int duration, int* returnSize){
    struct Time time[MAX_SIZE] = {0};
    for (int i = 0; i < slots1Size; i++) {
        time[i].begin = slots1[i][0];
        time[i].end = slots1[i][1];
    }
    for (int i = 0; i < slots2Size; i++) {
        time[i + slots1Size].begin = slots2[i][0];
        time[i + slots1Size].end = slots2[i][1];
    }
    int size = slots1Size + slots2Size;
    qsort(time, size, sizeof(struct Time), Comp);
    int l = 0;
    int r = l + 1;
    while (l < r && r < size) {
        if (time[l].end - time[r].begin < duration) {
            l = r;
            r++;
        } else if (time[r].end - time[r].begin < duration) {
            r++;
        } else {
            break;
        }
    }
    if (r == size) {
        *returnSize = 0;
        return NULL;
    }
    int *result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, 2 * sizeof(int));
    *returnSize = 2;
    result[0] = time[r].begin;
    result[1] = time[r].begin + duration;
    return result;
}
```
