### 解题思路
典型的字典树问题，与DFS相结合，这里给出C语言的解法。

注意，对于C而言，结果的返回比较麻烦，这里采用全局变量数组的方法。

一旦查到一个单词，则将结果单词生成，并将之前的单词路径拷贝到下一个结果中，继续查找。

1.构建字典树

2.将单词放入字典树

3.遍历矩阵，按照字典树进行遍历

4.如果遇到单词，则生成结果

![image.png](https://pic.leetcode-cn.com/1efea43eca359570295f209006da864646269e40690c88c93d5243a34b52e182-image.png)


### 代码

```c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define RET_LEN     500
#define MAX_LEN     100
#define WORD_LEN    100

typedef struct _trie_st {
    int val;
    struct _trie_st *nxt[26];
}trie_st;

int flag[MAX_LEN][MAX_LEN];
int row, col;

char ret_[RET_LEN][WORD_LEN];
char *ret[RET_LEN];
int rsize;
int rid;

void helper(char** board, int y, int x, trie_st *root) {
    //可以进入，表明当前字符可以匹配
    int id = board[y][x] - 'a';
    ret_[rsize][rid++] = id + 'a';

    //判断当前位置是否有完成的单词,注意word中不含重复单词
    if(root->val > 0) {
        root->val = 0;

        //生成结果
        ret_[rsize][rid] = '\0';
        ret[rsize] = ret_[rsize];
        rsize++;

        //将路径延续
        strncpy(ret_[rsize], ret_[rsize - 1], rid);
    }
    //printf("%s\n", ret_[rsize]);

    flag[y][x] = 1;
    //和root中的字符匹配上，开始进行4个方向的查找
    //上
    if(y > 0 && flag[y - 1][x] == 0) {
        int nid = board[y - 1][x] - 'a';

        if(root->nxt[nid] != NULL) {
            helper(board, y - 1, x, root->nxt[nid]);
        }
    }

    //下
    if(y < row - 1 && flag[y + 1][x] == 0) {
        int nid = board[y + 1][x] - 'a';

        if(root->nxt[nid] != NULL) {
            helper(board, y + 1, x, root->nxt[nid]);
        }
    }

    //左
    if(x > 0 && flag[y][x - 1] == 0) {
        int nid = board[y][x - 1] - 'a';

        if(root->nxt[nid] != NULL) {
            helper(board, y, x - 1, root->nxt[nid]);
        }
    }

    //右
    if(x < col - 1 && flag[y][x + 1] == 0) {
        int nid = board[y][x + 1] - 'a';

        if(root->nxt[nid] != NULL) {
            helper(board, y, x + 1, root->nxt[nid]);
        }
    }

    //注意，将本次的修改恢复
    flag[y][x] = 0;
    rid--;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//【算法思路】字典树+DFS。
char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    if(wordsSize == 0 || boardSize == 0 || boardColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    row = boardSize;
    col = boardColSize[0];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            flag[i][j] = 0;
        }
    }

    trie_st root = {0};
    //构建trie树
    for(int i = 0; i < wordsSize; i++) {
        trie_st *cur = &root;

        int wlen = strlen(words[i]);
        for(int j = 0; j < wlen; j++) {
            int id = words[i][j] - 'a';
            if(cur->nxt[id] == NULL) {
                cur->nxt[id] = (trie_st *)calloc(1, sizeof(trie_st));
            }

            cur = cur->nxt[id];
        }

        cur->val++;
    }

    //遍历表格
    rsize = 0;
    rid = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int id = board[i][j] - 'a';
            if(root.nxt[id] != NULL) {
                rid = 0;
                helper(board, i, j, root.nxt[id]);
            }
        }
    }

    *returnSize = rsize;
    return ret;
}
```