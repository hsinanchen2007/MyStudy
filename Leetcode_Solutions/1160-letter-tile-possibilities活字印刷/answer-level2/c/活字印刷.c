### 解题思路
回溯算法

### 代码

```c
int numTilePossibilities(char * tiles){
    int result = 0;
    int *box = (int *)calloc(sizeof(int), 26);
    for (int i = 0; tiles[i]; i++) {
        box[tiles[i]-'A']++;
    }
    getResult(box, &result);
    free(box);
    return result;
 }
 void getResult(int *box, int *result) {
     for (int i = 0; i < 26; i++) {
        if (box[i] <= 0) {
            continue;
        }
        box[i]--;
        (*result)++;
        getResult(box, result);
        box[i]++;
     }
 }
```