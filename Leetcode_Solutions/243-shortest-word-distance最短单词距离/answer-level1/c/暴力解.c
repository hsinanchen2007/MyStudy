### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(x,y) (x < y ? x : y)

int shortestDistance(char ** words, int wordsSize, char * word1, char * word2){

    int ans = 10000;
    int pos1[wordsSize];
    int pos2[wordsSize];
    int pos1_id = 0;
    int pos2_id = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(word1, words[i]) == 0) {
            pos1[pos1_id++] = i;
        }
        if (strcmp(word2, words[i]) == 0) {
            pos2[pos2_id++] = i;
        }
    }

    for (int i = 0; i < pos1_id; i++) {
        for (int j = 0; j < pos2_id; j++) {
            ans = MIN(ans, abs(pos1[i] - pos2[j]));
        }
    }
    return ans;    
}
```