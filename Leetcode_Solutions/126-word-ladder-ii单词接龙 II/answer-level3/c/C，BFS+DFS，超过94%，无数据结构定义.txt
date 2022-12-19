127是纯BFS, DFS会导致超时。
126则在BFS过程中记录回溯数据，确保每个单词能记录回beginword，一旦找到endword，继续完成本层BFS。最后利用DFS回溯数据构建返回值。

C代码如下 (改了N个版本，写了一天。。。)

 ```
char** list;
int** back;
int* backSize;

// DFS uses backtrack information to construct results
void dfs(char*** res, int* rSize, int** rCSizes, int* ans, int last, int retlevel) {
    int i = ans[last];
    if (i == 0) {
        res[*rSize] = (char**)malloc(sizeof(char*) * retlevel);
        (*rCSizes)[*rSize] = retlevel;
        for (int j = 0; j < retlevel; ++j) {
            res[*rSize][j] = list[ans[j]];
        }
        ++(*rSize);
    }
    if (last == 0) return;
    for (int j = 0; j < backSize[i]; ++j) {
        int k = back[i][j];
        ans[last - 1] = k;
        dfs(res, rSize, rCSizes, ans, last - 1, retlevel);
    }
}

char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int size = wordListSize + 1;  // new size
    int wlen = strlen(beginWord);
    list = (char**)malloc(sizeof(char*) * size);  // new wordlist
    back = (int**)malloc(sizeof(int*) * size);    // data to backtrack indexes while BFS
    backSize = (int*)malloc(sizeof(int) * size);
    int* visited = (int*)malloc(sizeof(int) * size);  // visited flag in BFS
    int** diff = (int**)malloc(sizeof(int*) * size);  // list diff[i] are indexes which can connect to word[i]
    int* diffSize = (int*)malloc(sizeof(int) * size);
    int endidx = 0;
    // Intialization 1
    for (int i = 0; i < size; ++i) {
        list[i] = i == 0 ? beginWord : wordList[i - 1];
        visited[i] = 0;
        diff[i] = (int*)malloc(sizeof(int) * size);
        diffSize[i] = 0;
        back[i] = (int*)malloc(sizeof(int) * size);
        backSize[i] = 0;
        if (strcmp(endWord, list[i]) == 0) {
            endidx = i;
        }
    }
    if (endidx == 0) return 0;  // endword is not in the list
    // collect diff data
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int tmp = 0;  // tmp is the difference between word[i] & word[j]
            for (int k = 0; k < wlen; ++k) {
                tmp += list[i][k] != list[j][k];
                if (tmp > 1) break;
            }
            if (tmp == 1) {
                diff[i][diffSize[i]++] = j;
                diff[j][diffSize[j]++] = i;
            }
        }
    }
    // BFS
    int* curr = (int*)malloc(sizeof(int) * size);  // curr level in BFS
    int* prev = (int*)malloc(sizeof(int) * size);  // prev level in BFS
    int prevSize, currSize = 1;
    int* currvisited = (int*)malloc(sizeof(int) * size);  // to make sure curr members are unique
    int level = 1;                                        // level of ladder
    curr[0] = 0;
    visited[0] = 1;
    int retlevel = 0;  // ladder size, marks the end of BFS
    while (retlevel == 0 && currSize > 0) {
        ++level;
        // switch prev and curr
        int* tmp = prev;
        prev = curr;
        curr = tmp;
        prevSize = currSize;
        currSize = 0;
        // reset currvisited for each level curr
        for (int i = 0; i < size; ++i) {
            currvisited[i] = 0;
        }
        for (int i = 0; i < prevSize; ++i) {
            for (int j = 0; j < diffSize[prev[i]]; ++j) {
                int k = diff[prev[i]][j];  // k is the candidate of curr (next level of BFS)
                if (visited[k]) continue;
                back[k][backSize[k]++] = prev[i];   // backtrack
                if (k == endidx) retlevel = level;  // find the lowest ladder level, finish current BFS
                if (currvisited[k]) continue;       // no duplicates in curr list
                curr[currSize++] = k;
                currvisited[k] = 1;
            }
        }
        // set visited after search through one level, different from Q127
        for (int i = 0; i < currSize; ++i) {
            visited[curr[i]] = 1;
        }
    }
    if (retlevel == 0) return 0;  // no ladder found
    // DFS to construct result
    char*** res = (char***)malloc(sizeof(char**) * size);
    int* ans = (int*)malloc(sizeof(int) * retlevel);
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    ans[retlevel - 1] = endidx;
    dfs(res, returnSize, returnColumnSizes, ans, retlevel - 1, retlevel);
    return res;
}
```
