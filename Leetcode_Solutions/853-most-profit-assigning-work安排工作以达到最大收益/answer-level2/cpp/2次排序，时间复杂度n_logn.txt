
执行结果：通过 显示详情 
执行用时 : 344 ms, 在所有 c 提交中击败了43.97%的用户
内存消耗 : 9.8 MB, 在所有 c 提交中击败了100.00%的用户



```
struct node {
    int difficulty;
    int profit;
};
int CmpStruct(const void *a, const void *b)
{
    return (*(struct node *)a).difficulty - (*(struct node *)b).difficulty;
}
int CmpInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
{
    int total = 0;
    int tag = -1;
    int last = 0;
    int workerI = 0;
    int difficultyI = 0;

    struct node nodes[10 * 1024];
    memset(nodes, 0, sizeof(nodes));

    for (int i = 0; i < difficultySize; i++) {
        nodes[i].difficulty = difficulty[i];
        nodes[i].profit = profit[i];
    }
    qsort(nodes, difficultySize, sizeof(struct node), CmpStruct);
    for (int i = 0; i < difficultySize; i++) {
        difficulty[i] = nodes[i].difficulty;
        profit[i] = nodes[i].profit;
    }    
    qsort(worker, workerSize, sizeof(int), CmpInt);
    int nextI = -1;

    for (workerI = 0; workerI < workerSize; workerI++) {
        tag = -1;
        last = 0;
        if (nextI != -1) {
            difficultyI = nextI;
        } else {
            difficultyI = 0;
        }
        for (; difficultyI < difficultySize; difficultyI++) {
            if (difficulty[difficultyI] <= worker[workerI]) {
                if (tag == -1) {
                    last = profit[difficultyI];
                    tag = difficultyI;
                } else if (profit[difficultyI] > last) {
                    last = profit[difficultyI];
                    tag = difficultyI;
                }
            } else {
                break;
            }
        }
        if (tag == -1) {
            nextI = -1;
            total += 0;
        } else {
            total += profit[tag];
            nextI = tag;
        }
    }

    return total;
}
```
