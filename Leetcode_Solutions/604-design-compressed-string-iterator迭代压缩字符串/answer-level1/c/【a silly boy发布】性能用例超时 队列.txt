![51D14073-C4D7-4634-90D3-3D071CD7A0B1.jpeg](https://pic.leetcode-cn.com/9cd4c3ebd3b73c910bd79ba812d2120a346adb5b153680b138ae53f2cdd34d23-51D14073-C4D7-4634-90D3-3D071CD7A0B1.jpeg)

=======》搞定
![CB4D240F-E357-43E9-B006-8E37470A9C7B.jpeg](https://pic.leetcode-cn.com/73ba97e2d50255cfd5995cd0ef337b867a37a9f3cd2ab29f01fae919706994a0-CB4D240F-E357-43E9-B006-8E37470A9C7B.jpeg)

```
//数据结构: 队列，先入先出
typedef struct {
    char c;
    struct ListQueue *next;
} ListQueue;

ListQueue *g_listQueue = NULL;
int g_listQueueNum = 0;

void ListQueueInQueue(char c) {
    ListQueue *tmpListQueue = g_listQueue;
    if (g_listQueueNum == 0) {
        g_listQueue = (ListQueue *)malloc(sizeof(ListQueue));
        g_listQueue->c = c;
        g_listQueue->next = NULL;
        g_listQueueNum++;
    } else {
        while(tmpListQueue->next != NULL) {
            tmpListQueue = tmpListQueue->next;
        }
        tmpListQueue->next = (ListQueue *)malloc(sizeof(ListQueue));
        tmpListQueue = tmpListQueue->next;
        tmpListQueue->c = c;
        tmpListQueue->next = NULL;
        g_listQueueNum++;
    }
}

bool ListQueueOutQueue(char *c) {
    ListQueue *tmpListQueue = g_listQueue;
    if (g_listQueueNum == 0) {
        return false;
    } else {
        if (tmpListQueue->next == NULL) {
            g_listQueueNum = 0;
            *c = tmpListQueue->c;
            free(tmpListQueue);
        } else {
            *c = tmpListQueue->c;
            g_listQueue = g_listQueue->next;
            free(tmpListQueue);
            g_listQueueNum--;
        }
        //printf("g_listQueueNum: %d\n", g_listQueueNum);
        return true;
    }
}

typedef struct {
    
} StringIterator;

StringIterator* stringIteratorCreate(char * compressedString) {
    StringIterator *tmpStringIterator = (StringIterator *)malloc(sizeof(StringIterator));
    int lenStr = strlen(compressedString);
    int i;
    int j;
    int k;
    int num = 0;
    int numCnt = 0;
    for (i = 0; i < lenStr; i++) {
        num = 0;
        numCnt = 0;
        if ((compressedString[i] >= '0') && (compressedString[i] <= '9')) {
            j = i;
            while ((j < lenStr) && (compressedString[j] >= '0') && (compressedString[j] <= '9')) {
                num = num * 10 + compressedString[j] - '0';
                numCnt++;
                j++;
            }
            //printf("num: %d, compressedString[i - 1]: %c,numCnt: %d\n", num, compressedString[i - 1], numCnt);
            if (num >= 5000) {
                num = 5000;
            } 
            if (num != 1) {
                for (k = 0; k < num - 1; k++) {
                    ListQueueInQueue(compressedString[i - 1]);
                }
            }
            i = i + numCnt - 1;
            if (num == 5000) {
                return tmpStringIterator;
            }
        } else {
            ListQueueInQueue(compressedString[i]);
        }
    }
    return tmpStringIterator;
}

char stringIteratorNext(StringIterator* obj) {
    bool isTrue;
    char returnChar;
    isTrue = ListQueueOutQueue(&returnChar);
    if (isTrue == true) {
        return returnChar;
    }
    return ' ';
}

bool stringIteratorHasNext(StringIterator* obj) {
    if (g_listQueueNum != 0) {
        return true;
    }
    return false;
}

void stringIteratorFree(StringIterator* obj) {
    char returnChar;
    while(g_listQueueNum != 0) {
        ListQueueOutQueue(&returnChar);
    }
    free(obj);
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 
 * bool param_2 = stringIteratorHasNext(obj);
 
 * stringIteratorFree(obj);
*/
```


```
//数据结构: 队列，先入先出
typedef struct {
    char c;
    struct ListQueue *next;
} ListQueue;

ListQueue *g_listQueue = NULL;
int g_listQueueNum = 0;

void ListQueueInQueue(char c) {
    ListQueue *tmpListQueue = g_listQueue;
    if (g_listQueueNum == 0) {
        g_listQueue = (ListQueue *)malloc(sizeof(ListQueue));
        g_listQueue->c = c;
        g_listQueue->next = NULL;
        g_listQueueNum++;
    } else {
        while(tmpListQueue->next != NULL) {
            tmpListQueue = tmpListQueue->next;
        }
        tmpListQueue->next = (ListQueue *)malloc(sizeof(ListQueue));
        tmpListQueue = tmpListQueue->next;
        tmpListQueue->c = c;
        tmpListQueue->next = NULL;
        g_listQueueNum++;
    }
}

bool ListQueueOutQueue(char *c) {
    ListQueue *tmpListQueue = g_listQueue;
    if (g_listQueueNum == 0) {
        return false;
    } else {
        if (tmpListQueue->next == NULL) {
            g_listQueueNum = 0;
            *c = tmpListQueue->c;
            free(tmpListQueue);
        } else {
            *c = tmpListQueue->c;
            g_listQueue = g_listQueue->next;
            free(tmpListQueue);
            g_listQueueNum--;
        }
        //printf("g_listQueueNum: %d\n", g_listQueueNum);
        return true;
    }
}

typedef struct {
    
} StringIterator;

StringIterator* stringIteratorCreate(char * compressedString) {
    StringIterator *tmpStringIterator = (StringIterator *)malloc(sizeof(StringIterator));
    int lenStr = strlen(compressedString);
    int i;
    int j;
    int k;
    int num = 0;
    int numCnt = 0;
    for (i = 0; i < lenStr; i++) {
        num = 0;
        numCnt = 0;
        if ((compressedString[i] >= '0') && (compressedString[i] <= '9')) {
            j = i;
            while ((j < lenStr) && (compressedString[j] >= '0') && (compressedString[j] <= '9')) {
                num = num * 10 + compressedString[j] - '0';
                numCnt++;
                j++;
            }
            //printf("num: %d, compressedString[i - 1]: %c,numCnt: %d\n", num, compressedString[i - 1], numCnt);
            if (num != 1) {
                for (k = 0; k < num - 1; k++) {
                    ListQueueInQueue(compressedString[i - 1]);
                }
            }
            i = i + numCnt - 1;
        } else {
            ListQueueInQueue(compressedString[i]);
        }
    }
    return tmpStringIterator;
}

char stringIteratorNext(StringIterator* obj) {
    bool isTrue;
    char returnChar;
    isTrue = ListQueueOutQueue(&returnChar);
    if (isTrue == true) {
        return returnChar;
    }
    return ' ';
}

bool stringIteratorHasNext(StringIterator* obj) {
    if (g_listQueueNum != 0) {
        return true;
    }
    return false;
}

void stringIteratorFree(StringIterator* obj) {
    char returnChar;
    while(g_listQueueNum != 0) {
        ListQueueOutQueue(&returnChar);
    }
    free(obj);
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 
 * bool param_2 = stringIteratorHasNext(obj);
 
 * stringIteratorFree(obj);
*/
```
