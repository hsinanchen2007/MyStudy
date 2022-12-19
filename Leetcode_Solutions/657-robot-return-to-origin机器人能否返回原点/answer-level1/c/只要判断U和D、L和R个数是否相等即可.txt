### 解题思路


### 代码

```c

bool judgeCircle(char * moves){
    int len = strlen(moves);
    int* table = (int*)malloc(sizeof(int) * 26);
    memset(table, 0, sizeof(int) * 26);
    for (int i = 0; i < len; i++) {
        table[moves[i] - 'A']++;
    }
    if (table[3] == table[20] && table[11] == table[17]) {
        return true;
    } else {
        return false;
    }
    return false;
}
```