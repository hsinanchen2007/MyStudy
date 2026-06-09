
![image.png](https://pic.leetcode-cn.com/a6ece21008ed40162406e981dbb5a09c158471130febfea911286f6d3ebffba9-image.png)

# 代码：
```

#define MAX 100
typedef struct {
    int* data;
    int num;  
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* newstack = malloc(sizeof(MyStack));
    newstack->data = malloc(sizeof(int) * MAX);
    newstack->num = 0;
    return newstack;

}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(obj->num != 0){
        for(int i = obj->num; i >= 1;i--){
            obj->data[i] = obj->data[i - 1];
        }
    }
     obj->data[0] = x;
    (obj->num)++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ans = obj->data[0];
    for(int i = 1; i < obj->num;i++){
        obj->data[i - 1] = obj->data[i];
    }
    (obj->num)--;
  return ans;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
  return obj->data[0];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->num == 0);
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

```

