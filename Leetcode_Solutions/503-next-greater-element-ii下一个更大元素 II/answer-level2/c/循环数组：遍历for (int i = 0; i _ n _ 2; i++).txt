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

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int* returnArray = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    memset(returnArray, -1, sizeof(int) * numsSize);
    MyStack* obj = myStackCreate();
    for(int i = 0; i < numsSize * 2; i++){
        while(!myStackIsEmpty(obj) &&  nums[i % numsSize] > nums[myStackTop(obj)]){
            int pre = myStackPop(obj);
            returnArray[pre] = nums[i % numsSize];
        }
        if(i < numsSize){
            myStackPush(obj, i);
        }
    }
    myStackFree(obj);
    return returnArray;
}
```
