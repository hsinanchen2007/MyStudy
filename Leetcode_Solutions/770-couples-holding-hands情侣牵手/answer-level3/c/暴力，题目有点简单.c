### 解题思路
此处撰写解题思路

### 代码

```c

void Exchange(int* row, int src, int dst) 
{
    int tmp;

    tmp = row[src];
    row[src] = row[dst];
    row[dst] =  tmp;
}

int minSwapsCouples(int* row, int rowSize){
    int i ,j;
    int tmp, nei;
    int result = 0;

    for (i = 0; i < rowSize; i = i + 2) {
        tmp = row[i];
        if(tmp % 2 == 1) {
            nei = tmp - 1;
        } else {
            nei = tmp + 1;
        }
        if(row[i + 1] == nei) {
            continue;
        }
        for (j = i + 1; j < rowSize; j++) {
            if(row[j] == nei) {
                Exchange(row, i + 1, j);
                result++;
            }
        }
    }
    return result;
}
```