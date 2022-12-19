先把工作和工人分别排序，用双指针寻找合适的工作。
有个坑就是有些难度低的工作，报酬反而比难度高的更高。要特别处理一下。
```
struct Work {
    int dif;
    int pro;
};
int Comp(void *a, void *b) {
    struct Work *x = (struct Work*)a;
    struct Work *y = (struct Work*)b;
    return (*x).dif - (*y).dif;
}
int Comp1(void *a, void *b) {
    return *(int*)a - *(int*)b;
}
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize){
    int i = 0;
    int j = 0;
    int sum = 0;
    struct Work *work = (struct Work*)malloc(difficultySize * sizeof(struct Work));
    if (work == NULL) {
        return 0;
    }
    for (int k = 0; k < difficultySize; k++) {
        work[k].dif = difficulty[k];
        work[k].pro = profit[k];
    }
    qsort(work, difficultySize, sizeof(work[0]), Comp);
    qsort(worker, workerSize, sizeof(int), Comp1);

    for (int k = 1; k < difficultySize; k++) {
        if (work[k].pro < work[k - 1].pro) {
            work[k].pro = work[k - 1].pro;
        }
    }
    while (j < workerSize) {
        if (work[i].dif <= worker[j]) {
            if (i == difficultySize - 1) {
                sum += work[i].pro;
                j++;
            } else {
                i++;
            }
        } else {
            if (i != 0) {
                sum += work[i - 1].pro;
            }
            j++;
        }
    }
    return sum;
}
```
