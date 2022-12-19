```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASH_SIZE (260)
#define MAX_CELL_SIZE (8)

int g_hash[HASH_SIZE];

int GetHashKey(int* cells)
{
    int i;
    int key = 0;
    for (i = 0; i <= MAX_CELL_SIZE - 1; i++) {
        key += (cells[i] * pow(2, i));
    }
    return key;
}

void UptCell(int* cells)
{
    int i;
    int nextCells[MAX_CELL_SIZE];    
    for (i = 1; i <= 6; i++) {
        if (((cells[i - 1] == 0) && (cells[i + 1] == 0)) || ((cells[i - 1] == 1) && (cells[i + 1] == 1))) {
            nextCells[i] = 1;
        } else {
            nextCells[i] = 0;
        }
    }
    cells[0] = cells[7] = 0;
    for (i = 1; i <= 6; i++) {
        cells[i] = nextCells[i];
    }    
}

int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize)
{
    int i;
    int key;
    int day = 0;
    int cycle;
    int nonCycle;
    int nth;
    int retVal;
    int retKey;    
    int *ret = (int*)malloc(sizeof(int) * MAX_CELL_SIZE);
    *returnSize = MAX_CELL_SIZE;
    if (N == 0) {
        for (i = 0; i < MAX_CELL_SIZE; i++) {
            ret[i] = cells[i];
        }
        return ret;
    }
    for (i = 0; i < HASH_SIZE; i++) {
        g_hash[i] = -1;
    }
    while (1) {
        key = GetHashKey(cells);        
        if (g_hash[key] != -1) {
            break;
        } else {
            g_hash[key] = day;
        }              
        day++;
        UptCell(cells);
    }
    nonCycle = g_hash[key];
    cycle = day - g_hash[key];   
    if (cycle == 1) {
        /* 周期为1 如[0,0,1,0,0,1,0,0]*/
        for (i = 0; i < MAX_CELL_SIZE; i++) {
            ret[i] = cells[i];
        }
        return ret;
    }    
    nth = N + 1 - nonCycle;
    if (nth % cycle == 0) {
        retVal = cycle + g_hash[key] - 1;
    } else {
        retVal = nth % cycle + g_hash[key] - 1;
    }    
    for (i = 0; i < HASH_SIZE; i++) {
        if (g_hash[i] == retVal) {
            retKey = i;
            break;
        }
    }    
    for (i = 0; i < MAX_CELL_SIZE; i++) {
        ret[i] = 0;
    }
    i = 0;
    while (retKey != 0) {
        ret[i] = retKey % 2;
        retKey /= 2;        
        i++;        
    }
    return ret;
}
```
