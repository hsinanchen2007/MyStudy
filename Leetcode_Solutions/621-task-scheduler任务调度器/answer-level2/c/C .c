### 解题思路
此处撰写解题思路

### 代码

```c
int leastInterval(char *tasks, int tasksSize, int n)
{
    int hash[26];
    int cntMax = 0;
    int sameCnt = 0;
    int i;
    int res;
    memset(hash, 0, sizeof(hash));

    for (i=0; i < tasksSize; i++) {
        hash[tasks[i] - 'A']++;
    }

    for (i = 0; i < 26; i++) {
        cntMax = cntMax > hash[i] ? cntMax : hash[i];
    }

    for (i = 0; i < 26 ; i++) {
        if (cntMax == hash[i]) {
            sameCnt++;
        }
    }

    res = (cntMax - 1) * n + cntMax + sameCnt - 1;
    res = res > tasksSize ? res : tasksSize;
    return res;
}

```