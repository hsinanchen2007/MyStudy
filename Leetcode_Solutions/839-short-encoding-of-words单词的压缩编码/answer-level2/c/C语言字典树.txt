### 解题思路
单词分隔，转换的问题是：
1 倒序重复的部分合并，其他用#分隔
2 长度为非重复部分+1

这里倒序重复，倒序后用字典树来求解

### 代码

```c

#define WORDSSIZE 26
#define PRINTF // printf
typedef struct stNode{
    int count;
    int isLeaf; // 0:no end; 1: end
    int totLen;
    struct stNode *pNode[WORDSSIZE];
}STNODE;

void FreeLexiOrder(STNODE *pStWords)
{
    if ((pStWords == NULL) || (pStWords->pNode == NULL)) {
        return;
    }
    for (int i = 0; i < WORDSSIZE; i++){
        if (pStWords->pNode[i] != NULL) {
            FreeLexiOrder(pStWords->pNode[i]);
            free(pStWords->pNode[i]);
        }
    }
}
STNODE *NewNode()
{
    STNODE *pNode = (STNODE *)malloc(sizeof(STNODE));
    if (pNode == NULL) {
        goto ERR;
    }
    pNode->count = 0;
    pNode->isLeaf = 0;
    pNode->totLen = 0;
    for (int i = 0; i < WORDSSIZE; i++) {
        pNode->pNode[i] = NULL;
    }
ERR:
    return pNode;
}
int InitLexiOrder(char ** words, int wordsSize, STNODE* pStNode)
{
    int col = 0;
    int iRet = 0;
    for (int row = 0; row < wordsSize; row++) {
        col = 0;
        STNODE *pCurNode = pStNode;
        int len = strlen(&words[row][0]);
        for (int col = (len - 1); col >= 0; col--) {
            if ((words[row][col] > 'z') || (words[row][col] < 'a')) {
                iRet = 0;
                goto ERR;
            }
            int index = (words[row][col] - 'a');
            if(pCurNode->pNode[index] == NULL) {
                pCurNode->pNode[index] = NewNode();
                if(pCurNode->pNode[index] == NULL) {
                    iRet = 0;
                    goto ERR;
                }
                PRINTF("New:%p\n", pCurNode->pNode[index]);
            }
            (pCurNode->pNode[index]->count)++;
            if ( col > 0 ) { // Not finish or already the leaf
                if (pCurNode->pNode[index]->isLeaf == 1) {
                    pCurNode->pNode[index]->isLeaf = 0; // Clear the leaf flag
                    iRet -= (pCurNode->pNode[index]->totLen + 1);
                }
                pCurNode = pCurNode->pNode[index];
                continue;
            }
            if (((pCurNode->pNode[index]->count) > 1) || (pCurNode->pNode[index]->isLeaf == 1)){
                continue;
            }
            pCurNode->pNode[index]->isLeaf = 1;
            pCurNode->pNode[index]->totLen = len;
            iRet += (len + 1);
        }
    }
ERR:
    return iRet;
}
int minimumLengthEncoding(char ** words, int wordsSize)
{
    int iRet = 0;
    STNODE stWords = {0};
    if (words == NULL) {
        goto END;
    }
    iRet = InitLexiOrder(words, wordsSize, &stWords); // 倒序的字典树
END:
    FreeLexiOrder(&stWords);
    return iRet;
}
```