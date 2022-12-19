### 解题思路
这题我用到了做208题时候写的前缀树函数，如果没有完成208题的建议先去做208题，或者直接看我这个也可以。
详细思路主要在注释中了

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TrieNode{
    bool isEnd;
    struct TrieNode* map[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *obj = (Trie *)malloc(sizeof(Trie));
    obj->isEnd = false;
    
    for (int i = 0; i < 26; i++)
        obj->map[i] = NULL;
    
    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        if (obj->map[word[i] - 'a'] == NULL)
            obj->map[word[i] - 'a'] = trieCreate();
        
        obj = obj->map[word[i] - 'a'];
    }
    
    obj->isEnd = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    for (int i = 0; word[i]; i++) {
        if (obj->map[word[i] - 'a'] == NULL)
            return false;
        
        obj = obj->map[word[i] - 'a'];
    }
    
    if (obj->isEnd) {           /* 这个地方有个*小改动*，每次搜索到一个单词，就把这个单词从 */
        obj->isEnd = false;     /* 前缀树中删除（把结束结点的结束标志取消），这样做可以避免重复 */
        return true;
    }
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    for (int i = 0; prefix[i]; i++) {
        if (obj->map[prefix[i] - 'a'] == NULL)
            return false;

        obj = obj->map[prefix[i] - 'a'];
    }

    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++)
        if (obj->map[i] != NULL)
            trieFree(obj->map[i]);
    
    free(obj);
}
/* 以上我都直接套用了208题的代码（个别部分进行了改动） */

/* 定义一些全局变量，不然函数的入口参数会很多 */
bool seen[500][500];
int R, C;
char *prefix;
Trie* trieTree;

/* 入口参数“pos”是用来更新prefix的 */
void traceBack(int r, int c, int pos, char **board, int* returnSize, char **res) {
/* 该前缀构成的单词是字典树中的单词，将prefix添加到res中 */
    if (trieSearch(trieTree, prefix)) {
        res[*returnSize] = malloc(sizeof(char) * (strlen(prefix) + 1));
        strcpy(res[(*returnSize)++], prefix);
    }
    
    int dr[] = {1, 0, -1, 0};       /* dr,dc数组共同完成点的向下、向右、向上、向左 */
    int dc[] = {0, 1, 0, -1};
    int di = 0;                     /* di为方向控制器 */
    seen[r][c] = true;              /* 现在在（r，c）这个点，将seen[r][c]置为true */

    for (int di = 0; di < 4; di++) {
        int rr = r + dr[di];
        int cc = c + dc[di]; 
        if (rr >= 0 && rr < R && cc >= 0 && cc < C && !seen[rr][cc]) {
            prefix[pos] = board[rr][cc];
            if (trieStartsWith(trieTree, prefix))
                traceBack(rr, cc, pos + 1, board, returnSize, res);
        }
            
    }

/* 回溯法非常重要的一步，退一步就将状态还原为原来的样子 */
    prefix[pos] = '\0';
    seen[r][c] = false; 
    return;
}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    R = boardSize, C = *boardColSize;

/* 同一个单元格内的字母在一个单词中不允许被重复使用，搜索一个单词时用seen标记该字母是否被使用 */
    memset(seen, 0, sizeof(seen));
    char **res = (char **)malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    
    trieTree = (Trie *)malloc(sizeof(Trie));
    trieTree->isEnd = false;
    
            /* 初始化前缀树 */
    for (int i = 0; i < 26; i++)
        trieTree->map[i] = NULL;
    for (int i = 0; i < wordsSize; i++)
        trieInsert(trieTree, words[i]);         /* 将words插入前缀树 */
 
/*   
* prefix为搜索过程中构成的前缀，每搜索一步，prefix更新一下
* 引入prefix可以方便的利用前缀树的相关函数进行剪枝
*/
    prefix = (char *)calloc(sizeof(char), R * C + 1);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            prefix[0] = board[i][j];

            if (trieStartsWith(trieTree, prefix) == false)
                continue;
            traceBack(i, j, 1, board, returnSize, res);
        }
 
    trieFree(trieTree);         /* 释放内存 */

    return res;
}
```