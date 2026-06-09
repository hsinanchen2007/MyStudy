### 解题思路
依次找到两个单词的下标，生成两个数组，遍历找到两个数组的差值的最小值

### 代码

```c
int shortestDistance(char ** words, int wordsSize, char * word1, char * word2){
    int i;
    int j;
    int m = 0;
    int n = 0;
    int dis;
    int temp;
    int *idx1 = (int*)malloc(sizeof(int) * wordsSize);
    int *idx2 = (int*)malloc(sizeof(int) * wordsSize);

    for (i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], word1) == 0) {
            idx1[m++] = i;
        }
        if (strcmp(words[i], word2) == 0) {
            idx2[n++] = i;
        }
    }
    idx1[m] = '\n';
    idx2[n] = '\n';

    dis = abs(idx1[0] - idx2[0]);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            temp = abs(idx1[i] - idx2[j]);
            dis = (temp < dis) ? temp : dis;
            printf("%d\n%d\n", idx1[i], idx2[j]);
        }
    }
    return dis;
}
```