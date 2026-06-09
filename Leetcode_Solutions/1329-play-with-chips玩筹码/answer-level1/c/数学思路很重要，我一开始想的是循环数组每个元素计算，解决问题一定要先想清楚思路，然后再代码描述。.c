### 解题思路
此处撰写解题思路

### 代码

```c
int minCostToMoveChips(int* chips, int chipsSize){
    int i = 0;
    int a1,a2;
    a1 = a2 = 0;

    for (i = 0; i < chipsSize; i++) {
        if (chips[i] % 2) {
            a1++;
        }
        else {
            a2++;
        }
    }

    return a1 < a2 ? a1 : a2;
}
```