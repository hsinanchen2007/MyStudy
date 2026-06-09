### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *p1, const void *p2)
{
    int *a1 = *(int **)p1;
    int *a2 = *(int **)p2;
    //printf("%d,%d,%d,%d\n", a1[0],a1[1],a2[0],a2[1]);
    return a1[1] > a2[1];

}
int maxEvents(int** events, int eventsSize, int* eventsColSize){
    qsort(events, eventsSize, *eventsColSize * sizeof(int), cmp);
    int visited[100001] = { 0 };
    int count = 0;
    for (int i = 0; i < eventsSize; i++) {
        for (int j = events[i][0]; j <= events[i][1]; j++) {
            if (visited[j] == 1) {
                continue;
            }
            else if (visited[j] == 0) {
                //printf("%d\n", j);
                visited[j] = 1;
                count++;
                break;
            }
        }
    }
    return count;
}
```