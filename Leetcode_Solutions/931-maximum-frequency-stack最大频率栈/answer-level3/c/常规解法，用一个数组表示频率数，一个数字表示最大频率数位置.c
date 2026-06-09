### 解题思路

### 代码

```c
typedef struct {
    int* top;
    int* button;
    int* freqNum;
    int maxIndex;
    int len;
} FreqStack;

FreqStack* freqStackCreate() {
    FreqStack *FS = (FreqStack *)malloc(sizeof(FreqStack));
    FS->button = (int *)malloc(4*10000);
    memset(FS->button, 0, 4*10000);
    FS->freqNum = (int *)malloc(4*10000);
    memset(FS->freqNum, 0, 4*10000);
    FS->top = FS->button;
    FS->maxIndex = 0;
    FS->len = 0;
    return FS;
}

void freqStackPush(FreqStack* obj, int x) {
    if (obj->len > 0) {
        obj->top++;
    } 
    *obj->top = x;
    obj->len++;

    if (obj->len ==1) {
        obj->freqNum[0] = 1;
        obj->maxIndex =0;
        //printf("PUSH maxIndex: %d\n", obj->maxIndex);
        return;
    } 
    
    obj->freqNum[obj->len - 1] = 1;
    int len = obj->len;
    for (int i = len - 2; i >= 0; i--) {
        if (*(obj->button + i) == x) {
            obj->freqNum[len - 1] = obj->freqNum[i] + 1;
            //printf("freqNum[len - 1]: %d ", obj->freqNum[len - 1]);
            break;
        }
    }

    if (obj->freqNum[len - 1] >= obj->freqNum[obj->maxIndex])
        obj->maxIndex = len - 1;    
    
    //printf("PUSH maxIndex: %d\n", obj->maxIndex);
}

int freqStackPop(FreqStack* obj) {
    if (obj->len == 1) {
        obj->len = 0;
        return *obj->button;
    }
    int oldMaxFrqNum = obj->freqNum[obj->maxIndex];
    int num = 0;
    int maxNum = obj->button[obj->maxIndex];

    //printf("maxNum: %d\n", maxNum);
    int *tmp = obj->button + obj->maxIndex;
    int *idxTmp = obj->freqNum + obj->maxIndex;
    //printf("maxIndex: %d, maxNum: %d\n", maxIndex, maxNum);
    if (tmp == obj->top) {
        obj->top--;
        obj->freqNum[obj->len-1] = 0;
        obj->len--;
    } else {
        memmove(tmp, tmp + 1, 4*(obj->len - obj->maxIndex -1));
        memmove(idxTmp, idxTmp + 1, 4*(obj->len - obj->maxIndex -1));
        obj->top--;
        obj->len--;
    }

    int len = obj->len - 1;
    for(int j = len; j >= 0; j--) {
        if (obj->freqNum[j] > num) {
            obj->maxIndex = j;
            num = obj->freqNum[j];
            if (num == oldMaxFrqNum)
                break;
        }
    }

    //printf("POP maxIndex: %d\n", obj->maxIndex);
    return maxNum;
}

void freqStackFree(FreqStack* obj) {
    free(obj->button);
    free(obj->freqNum);
    obj->button = NULL;
    obj->top = NULL;
    obj->len = 0;
}

/**
 * Your FreqStack struct will be instantiated and called as such:
 * FreqStack* obj = freqStackCreate();
 * freqStackPush(obj, x);
 
 * int param_2 = freqStackPop(obj);
 
 * freqStackFree(obj);
*/
```