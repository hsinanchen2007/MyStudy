### 解题思路
思路比较清晰，数据结构使用字典树进行存储，算法使用DFS进行搜索。
树结构使用索引比使用指针更快，同时占用内存更少；bits可以继续位操作优化，有兴趣可以试试~

### 代码

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NODE_NUM 65534
#define MAX_WORD_LEN 50
#define MAX_BOARD_COL 40
#define MAX_BOARD_ROW 40

typedef unsigned short ushort;
typedef struct g_Node
{
    char isEnd;  // 标识是否为单词的结尾
    ushort next[26];  // 子节点的索引值
} Node;

Node g_Tree[MAX_NODE_NUM];
int g_pos;
int g_matchNum;

char bits[MAX_BOARD_ROW][MAX_BOARD_COL];

void BuildTree(char **words, int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        Node *par = &g_Tree[0];
        char *ch = words[i];
        while (*ch != '\0') {
            Node *child;
            if (par->next[*ch - 'a'] == 0) {
                child = &g_Tree[g_pos];
                par->next[*ch - 'a'] = g_pos++;
            } else {
                ushort index = par->next[*ch - 'a'];
                child = &g_Tree[index];
            }
            par = child;
            ch++;
        }
        par->isEnd = 1;
    }
    return;
}

void CheckMatch(Node *node, char **board, int row, int *col, int ipos, int jpos, char **match, int pos)
{
    if (node == NULL) {
        return;
    }

    if (bits[ipos][jpos] != 0) {
        return;
    }
    bits[ipos][jpos] = 1;  
    
    char ch = board[ipos][jpos];  // node 与 [i,j] 相对应
    match[g_matchNum][pos] = ch;
    if (node->isEnd == 1) {
        // 检查去重
        match[g_matchNum][pos + 1] = '\0';
        int i;
        int over = 0;
        for (i = 0; i < g_matchNum; i++) {
            if (strcmp(match[g_matchNum], match[i]) == 0) {
                over = 1;
                break;
            }
        }
        if (over == 0) {  // 没有重复的
            memcpy(match[g_matchNum + 1], match[g_matchNum], sizeof(char) * (pos+1)); 
            g_matchNum++;
        }
    }

    ushort index;
    if (ipos + 1 < row) {
        index = node->next[board[ipos + 1][jpos] - 'a'];
        if (index != 0) {
        CheckMatch(&g_Tree[index], board, row, col, ipos + 1, jpos, match, pos + 1);
        }
    }
    if (ipos - 1 >= 0) {
        index = node->next[board[ipos - 1][jpos] - 'a'];
        if (index != 0) {
        CheckMatch(&g_Tree[index], board, row, col, ipos - 1, jpos, match, pos + 1);
        }
    }
    if (jpos + 1 < col[ipos]) {
        index = node->next[board[ipos][jpos + 1] - 'a'];
        if (index != 0) {
        CheckMatch(&g_Tree[index], board, row, col, ipos, jpos + 1, match, pos + 1);
        }
    }
    if (jpos - 1 >= 0) {
        index = node->next[board[ipos][jpos - 1] - 'a'];
        if (index != 0) {
        CheckMatch(&g_Tree[index], board, row, col, ipos, jpos - 1, match, pos + 1);
        }
    }
    bits[ipos][jpos] = 0;
    return;
}

void MatchWords(char **board, int row, int *col, char **match)
{
    Node *root = &g_Tree[0];
    int i, j, k;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col[i]; ++j) {
            char ch = board[i][j];
            if (root->next[ch - 'a'] != 0) {
                memset(bits, 0, sizeof(char) * MAX_BOARD_ROW * MAX_BOARD_COL);
                ushort index = root->next[ch - 'a'];
                CheckMatch(&g_Tree[index], board, row, col, i, j, match, 0);
            }
        }
    }
    return;
}

char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize)
{
    *returnSize = 0;
    if (board == NULL || boardSize <= 0 || boardColSize == NULL || words == NULL || wordsSize <= 0 || returnSize == NULL) {
        return NULL;
    }
    g_pos = 1;
    memset(g_Tree, 0, sizeof(Node) * MAX_NODE_NUM);
    BuildTree(words, wordsSize);
    char **match = (char **)malloc(sizeof(char *) * (wordsSize + 2));
    if (match == NULL) {
        return NULL;
    }
    // 最多全部单词都匹配
    int i;
    for (i = 0; i < wordsSize + 2; ++i) {
        match[i] = (char *)malloc(sizeof(char) * MAX_WORD_LEN);
        if (match[i] == NULL) {
            return NULL;
        }
    }
    g_matchNum = 0;
    MatchWords(board, boardSize, boardColSize, match);

    *returnSize = g_matchNum;
    return match;
}

```