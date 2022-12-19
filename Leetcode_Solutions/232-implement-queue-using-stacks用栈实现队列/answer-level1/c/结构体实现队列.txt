

```c
typedef struct {
    int *val;
    int top;
    int back;

} MyQueue;
bool myQueueEmpty(MyQueue* obj);
/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *obj = (MyQueue*)calloc(1,sizeof(MyQueue));
    obj->val = (int*)calloc(100,sizeof(int));
    obj->top = obj->back = 0;
    return obj;

}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) 
{
    
   if(myQueueEmpty(obj))
   {
       obj->val[obj->back] = x;
       obj->top++;
       
   }
   else
   {
       
       for(int i = obj->top;i>0;i--)
       {
           obj->val[i] = obj->val[i-1];
       }
       obj->val[obj->back] = x;
       obj->top++;
   }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) 
{
    int a =  obj->val[obj->top-1];
    obj->top--;
    return a;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->val[obj->top-1];

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->back == obj->top)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void myQueueFree(MyQueue* obj)
{
    memset(obj->val,0x00,sizeof(obj->val));
    obj->top = obj->back = 0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
```