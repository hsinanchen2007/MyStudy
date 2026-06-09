```
代码块
```
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct data {
    char *word;
    int index;
}dataStru;
#define MAXLIST 10000
typedef struct que {
    dataStru data[MAXLIST];
    int queHead;
    int queTail;
}queStru;

void initQue(queStru *queInst)
{
    memset(&queInst->data[0], 0 ,sizeof(dataStru)*MAXLIST);
    queInst->queHead = 0;
    queInst->queTail = 0;
}

int isEmpty(queStru *queInst)
{
    return queInst->queHead == queInst->queTail;
}
int isFull(queStru *queInst) {
    if ((queInst->queTail + 1) % MAXLIST == queInst->queHead) {
        return 1;
    } else {
        return 0;
    }
}

void insert(char *word, int idx, queStru *queInst)
{
    if (!isFull(queInst)) {
        queInst->data[queInst->queTail].word = word;
        queInst->data[queInst->queTail].index = idx;
        queInst->queTail = (queInst->queTail + 1) % MAXLIST;
    }
}
dataStru* pop(queStru *queInst)
{
    dataStru *data = NULL;
    if(!(isEmpty(queInst))) {        
        data = &queInst->data[queInst->queHead];
        queInst->queHead = (queInst->queHead + 1) % MAXLIST;
    } 
    return data;
}
int isCanChange(char *beginWord, char *endWord)
{
    int len = strlen(beginWord);
    int ret = 0;
    int len1 = strlen(endWord);
    if (len != len1) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (beginWord[i] != endWord[i]) {
            if (ret == 1) {
                return 0;
            } else {
                ret = 1;
            }
        }
    }
    return ret;
}
int listSize(queStru *queInst) {
    return (queInst->queTail - queInst->queHead + MAXLIST) % MAXLIST;
}
queStru queInst[2];
int ladderLength(char *beginWord, char *endWord, char wordList[][4], int wordListSize) 
{
    int tempIdx = -1;
    int tempIdx1;
    int que0Size;
    int que1Size;
    int searchFlag;
    int searchIdx;
    int step = 1;
    int searchSize;
    int isInList = 0;
    dataStru *dataTemp;
    int mark[MAXLIST] = {0};
    initQue(&queInst[0]);
    initQue(&queInst[1]);
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(beginWord, wordList[i]) == 0) {
            tempIdx = i;
        }
        if (strcmp(endWord, wordList[i]) == 0) {
            tempIdx1 = i;
            isInList = 1;
            break;
        }
    }
    if (isInList == 0) {
        return 0;
    }
    if (tempIdx > -1) {
        mark[tempIdx] =  1;
    }
    mark[tempIdx1] = 2; 

    insert(beginWord, tempIdx, &queInst[0]);
    insert(endWord, tempIdx1, &queInst[1]);
    for (; !isEmpty(&queInst[0]) && !isEmpty(&queInst[1]); step++) {
        que0Size = listSize(&queInst[0]);
        que1Size = listSize(&queInst[1]);
        if (que0Size < que0Size) {
            searchIdx = 1;
            searchSize = que1Size;
        } else {
            searchIdx = 0;
            searchSize = que0Size;
        }
        searchFlag = 1 << searchIdx;
        for (int j = 0; j < searchSize; j++) {
            dataTemp = pop(&queInst[searchIdx]);
            if (dataTemp->index > 0  && mark[dataTemp->index] == 3) {
                return step;
            }
            for (int i = 0; i < wordListSize; i++) {
                if (mark[i] != searchFlag && (isCanChange(dataTemp->word, &wordList[i][0])==1)) {
                    mark[i] |= searchFlag;
                    if (mark[i] == 3) {
                        return ++step;
                    }
                    insert(&wordList[i][0], i, &queInst[searchIdx]);
                }
            }
        }
    }
    return 0;
}


void main()
{
    char wordList[7][4] = {"hot","dot","dog","lot","log","cog"};
    char *beginWord = "hit";
    char *endWord = "cog";
    int ret;
    ret = ladderLength(beginWord,endWord,wordList, 6);
    printf("%d", ret);
}