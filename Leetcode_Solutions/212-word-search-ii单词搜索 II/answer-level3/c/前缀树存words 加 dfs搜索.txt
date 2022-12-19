### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct node{
    bool isEnd;
    struct node *map[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *obj = (Trie *)malloc(sizeof(Trie));
    memset(obj, 0, sizeof(Trie));
    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    while (*word != '\0') {
        if (obj->map[*word - 'a'] == NULL) {
            obj->map[*word - 'a'] = trieCreate();
        }
        obj = obj->map[*word - 'a'];
        word++;
    }
    obj->isEnd = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    while (*word != '\0') {
        if (obj->map[*word - 'a'] == NULL) {
            return false;
        }
        obj = obj->map[*word - 'a'];
        word++;
    }
    if (obj->isEnd == true) {
        obj->isEnd = false;
        return true;
    }
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    while (*prefix != '\0') {
        if (obj->map[*prefix - 'a'] == NULL) {
            return false;
        }
        
        obj = obj->map[*prefix - 'a'];
        prefix++;
    }
    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->map[i] != NULL) {
            trieFree(obj->map[i]);
        }
    }
    free(obj);
}

以上全部都是前缀树的内容。把words中的单词都放在前缀树里。
在board里面游走的时候，判断当前的字符串是否在前缀树里，是的话继续走。如果碰到了isEnd 输出一个结果。


void dfs(char **board, int row, int col, int i, int j, Trie *trie, char *prefix, int idx, char **res, int *returnSize, int **visited)
{
    if (trieSearch(trie, prefix)) {
        res[*returnSize] = malloc(sizeof(char) * (strlen(prefix) + 1));
        strcpy(res[(*returnSize)++], prefix);
        //return;  //这里不能返回，因为eat 和 eata 都满足的情况下，返回就会丢失一个
    }

    
    int d[4][2] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
    //记录当前位置被访问
    visited[i][j] = 1;
    
    for (int di = 0; di < 4; di++){
        int x = i + d[di][0];
        int y = j + d[di][1];
        if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) //在board里匹配一个单词时board里每个字母只能用一次
            continue;
        prefix[idx] = board[x][y];
        if (trieStartsWith(trie, prefix)) {
            dfs(board, row, col, x, y, trie, prefix, idx + 1, res, returnSize, visited);
        }
    }
    //恢复
    prefix[idx] = '\0';
    visited[i][j] = 0;

}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    
    // 正如提示：如果在board里的单词不存在words里所有单词了，立即停止回溯。
    // 创建前缀树，将words里的单词插入到前缀树中,用于查询当前得到的单词前缀是否在words里
    Trie *trie = trieCreate();
    for (int i = 0; i < wordsSize; i++) {
        trieInsert(trie, words[i]);
    }
    
    char **res = (char **)malloc(wordsSize * sizeof(char *));
    *returnSize = 0;
    
    int row = boardSize;
    int col = boardColSize[0];
    
    //用来存当前位置匹配到的单词前缀
    char *prefix = (char *)calloc(row * col + 1, sizeof(char));
    
    //在board里面游走的时候，同一个单元格的字母只能访问一次
    int **visited = (int **)malloc(row *sizeof(int *));
    for (int i = 0; i < row; i++) {
        visited[i] = (int *)calloc(col, sizeof(int));
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            prefix[0] = board[i][j];
            
            if (trieStartsWith(trie, prefix) == false)
                continue;
            dfs(board, row, col, i, j, trie, prefix, 1, res, returnSize, visited);
        }
    }
    trieFree(trie);
    return res;
}
```