### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int res = 0;

void print(int* stones, int stonesSize)
{
    for (int i = 0; i < stonesSize; i++) {
        printf("%d ", stones[i]);
    }
    printf("\n");
}

int lastStoneWeight(int* stones, int stonesSize){
    //print(stones, stonesSize);
    if (stonesSize == 1) {
        res = stones[0];
        return res;
    }
    if (stonesSize == 0) {
        res = 0;
        return 0;
    }
    else {
        qsort(stones, stonesSize, sizeof(int), cmp);
        int x = stones[stonesSize - 1];
        int y = stones[stonesSize - 2];
        if (x == y) {
            stonesSize -= 2;
        }
        else{
            stones[stonesSize - 2] = abs(x - y);
            stonesSize -= 1;
        }

        lastStoneWeight(stones, stonesSize);
    }

    return res;
}
```