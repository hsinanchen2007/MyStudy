- 在遍历数组时用栈把数组中的数存起来，如果当前遍历的数比栈顶元素来的大，说明栈顶元素的下一个比它大的数就是当前元素。
```
typedef struct Stack{
    int data;
    struct Stack* next;
}MyStack;

MyStack* myStackCreate(){
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj -> next = NULL;
    return obj;
}

void myStackPush(MyStack* obj, int x){
    MyStack* node = (MyStack*)malloc(sizeof(MyStack));
    node -> data = x;
    node -> next = obj -> next;
    obj -> next = node;
}

int myStackPop(MyStack* obj){
    int data;
    if(obj -> next == NULL){
        return 0;
    }else{
        MyStack* node = obj -> next;
        obj -> next = obj -> next -> next;
        data = node -> data;
        free(node);
    }
    return data;
}

bool myStackIsEmpty(MyStack* obj){
    if(obj -> next == NULL){
        return true;
    }
    return false;
}

int myStackTop(MyStack* obj){
    int data;
    if(obj -> next == NULL){
        return 0;
    }else{
        data = obj -> next -> data;
    }
    return data;
}

void myStackFree(MyStack* obj){
    while(!myStackIsEmpty(obj)){
        myStackPop(obj);
    }
    free(obj);
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int* returnArray = (int*)malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    memset(returnArray, 0, sizeof(int) * TSize);
    MyStack* obj = myStackCreate();
    for(int i = 0; i < TSize; i++){
        while(!myStackIsEmpty(obj) &&  T[i] > T[myStackTop(obj)]){
            int pre = myStackPop(obj);
            returnArray[pre] = i - pre;
        }
        myStackPush(obj, i);
    }
    myStackFree(obj);
    return returnArray;
}
```
