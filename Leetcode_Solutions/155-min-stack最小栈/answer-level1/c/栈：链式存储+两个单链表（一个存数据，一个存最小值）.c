```
typedef struct Stack{
    int data;
    struct Stack* next;
} MyStack;
typedef struct {
    MyStack* dataStack;
    MyStack* miniStack;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    MyStack* dataStack = (MyStack*)malloc(sizeof(MyStack));
    MyStack* miniStack = (MyStack*)malloc(sizeof(MyStack));
    dataStack -> next = NULL;
    miniStack -> next = NULL;
    obj -> dataStack = dataStack;
    obj -> miniStack = miniStack;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    MyStack* node = (MyStack*)malloc(sizeof(MyStack));
    MyStack* miniNode = (MyStack*)malloc(sizeof(MyStack));
    node -> data = x;
    node -> next = obj -> dataStack -> next;
    obj -> dataStack -> next = node;
    if(obj -> miniStack -> next == NULL){
        miniNode -> data = x;
    }else{
        int min = obj -> miniStack ->next ->data;
        if(x >= min){
            miniNode -> data = min;
        }else{
            miniNode -> data = x;
        }
    }
    miniNode -> next = obj -> miniStack -> next;
    obj -> miniStack -> next = miniNode;
}

void minStackPop(MinStack* obj) {
    MyStack* tmpDataNode = obj -> dataStack ->next;
    MyStack* tmpMiniNode = obj -> miniStack ->next;
    obj -> dataStack ->next = obj -> dataStack ->next -> next;
    obj -> miniStack ->next = obj -> miniStack ->next -> next;
    free(tmpDataNode);
    free(tmpMiniNode);
}

int minStackTop(MinStack* obj) {
    return obj -> dataStack ->next -> data;
}

int minStackGetMin(MinStack* obj) {
    return obj -> miniStack ->next -> data;
}

void minStackFree(MinStack* obj) {
    while(obj -> dataStack -> next != NULL){
        MyStack* tmpDataNode = obj -> dataStack ->next;
        MyStack* tmpMiniNode = obj -> miniStack ->next;
        obj -> dataStack ->next = obj -> dataStack ->next -> next;
        obj -> miniStack ->next = obj -> miniStack ->next -> next;
        free(tmpDataNode);
        free(tmpMiniNode);
    }
}
```
