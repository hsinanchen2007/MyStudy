```
int que[50000] = {0};
int cnt, head, tail;
void enQue(int a)
{
    que[head] = a;
    head++;
    head = head%50000;
    cnt++;
}
void deQue(int *a)
{
    *a = que[tail];
    tail++;
    tail = tail%50000;
    cnt--;
}
void emptyQ()
{
    cnt = 0;
    head = 0;
    tail = 0;
}
bool canReach(int* arr, int arrSize, int start){
    int curr, nextl, nextr;
    int *visit;
    if ((arr == NULL) || (arrSize == 0)) {
        return false;
    }
    visit = calloc(arrSize, sizeof(int));
    emptyQ();
    curr = start;
    enQue(curr);
    while (cnt > 0) {
        deQue(&curr);
        visit[curr] = 1;
        if (arr[curr] == 0) {
            return true;
        }
        if ((curr + arr[curr] < arrSize) && (visit[curr + arr[curr]] == 0)) {
            nextr = curr + arr[curr];
            enQue(nextr);
        }
        if ((curr - arr[curr] >= 0) && (visit[curr - arr[curr]] == 0)) {
            nextl = curr - arr[curr];
            enQue(nextl);
        }
    }
    return false;
}
```
