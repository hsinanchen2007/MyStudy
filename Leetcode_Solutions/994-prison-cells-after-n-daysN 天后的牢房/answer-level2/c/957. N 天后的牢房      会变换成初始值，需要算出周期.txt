### 解题思路
8 间牢房排成一排，每间牢房不是有人住就是空着。

每天，无论牢房是被占用或空置，都会根据以下规则进行更改：

如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。
否则，它就会被空置。
（请注意，由于监狱中的牢房排成一行，所以行中的第一个和最后一个房间无法有两个相邻的房间。）

我们用以下方式描述监狱的当前状态：如果第 i 间牢房被占用，则 cell[i]==1，否则 cell[i]==0。

根据监狱的初始状态，在 N 天后返回监狱的状况（和上述 N 种变化）。

 

示例 1：

输入：cells = [0,1,0,1,1,0,0,1], N = 7
输出：[0,0,1,1,0,0,0,0]
解释：
下表概述了监狱每天的状况：
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    int tempnew, tempold, i ,j, k;
    int backup[8] = {0};
    bool init = false;

    for (i = 0; i < N; i++) {
        tempold = 1 - cells[0]^cells[2];
     
        for (j = 2; j < cellsSize - 1; j++) {
            tempnew = 1 - cells[j + 1]^cells[j - 1];
            cells[j-1] = tempold;
            tempold = tempnew;
        }
        cells[j-1] = tempnew;

        if(i == 0) {
            cells[0] = cells[cellsSize - 1] = 0;
            memcpy(backup, cells, 8*sizeof(int));
            continue;
        }
        
        if (!init && !memcmp(cells, backup, 8 * sizeof(int))) {
            //这里相当于第二次才是循环的第一项，周期１４，第１５天才出现相同
            //这ｆｏｒ循环，ｉ下一循环直接＋＋变成１了，不是从０开始
            N = (N-1)%i + 1;
            i = 0;
            init = true;
        }
    }
    *returnSize = cellsSize;

    return cells;
}
```