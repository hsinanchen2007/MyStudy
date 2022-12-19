```
typedef struct {

    int *stackBuf;
    int *top[3];
    int stackSize;

} TripleInOne;

TripleInOne* tripleInOneCreate(int stackSize) {

    TripleInOne *one = malloc(sizeof(TripleInOne));
    one->stackBuf = malloc(sizeof(int) * stackSize * 3);
    one->stackSize = stackSize;
    
    for(int i = 0; i < 3; i++)
        (one->top)[i] = one->stackBuf + i * stackSize;
    
    return one;
}

bool tripleInOneIsFull(TripleInOne* obj, int stackNum) {

    return (obj->top)[stackNum] - (obj->stackBuf + stackNum * obj->stackSize) == obj->stackSize;

}

void tripleInOnePush(TripleInOne* obj, int stackNum, int value) {

    if(tripleInOneIsFull(obj, stackNum)) return;

    *((obj->top)[stackNum])++ = value;

}

bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum);

int tripleInOnePop(TripleInOne* obj, int stackNum) {

    if(tripleInOneIsEmpty(obj, stackNum)) return -1;

    return *(--((obj->top)[stackNum]));

}

int tripleInOnePeek(TripleInOne* obj, int stackNum) {

    if(tripleInOneIsEmpty(obj, stackNum)) return -1;

    return *(((obj->top)[stackNum]) - 1);

}

bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum) {

    return (obj->top)[stackNum] == obj->stackBuf + stackNum * obj->stackSize;

}

void tripleInOneFree(TripleInOne* obj) {

    free(obj->stackBuf);
    free(obj);
}

```
