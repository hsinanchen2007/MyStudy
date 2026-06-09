### 解题思路
采用Hash保存所有的值，注意每次获取最大值时，从Hash表中获取。

### 代码

```c




typedef struct _my_struct {
    int  id;   
    int count;                 
    UT_hash_handle hh;
}my_struct;

my_struct *g_hash = NULL;


#define MAX_NUMS 100001

typedef struct NODE_
{
   int val;
}Node;

typedef struct {
    Node arr[MAX_NUMS];
    int front;
    int rear;

} MaxQueue;

int cmp(my_struct *a, my_struct *b) {
    return (b->id - a->id);
}

MaxQueue* maxQueueCreate() {

    MaxQueue *myQueue;
    myQueue = malloc(sizeof(MaxQueue));
    myQueue->front = 0;
    myQueue->rear = 0;
    return myQueue;
}

int maxQueueMax_value(MaxQueue* obj) {
  HASH_SORT(g_hash,cmp);
  my_struct *current_user, *tmpuseless;
  HASH_ITER(hh, g_hash, current_user, tmpuseless) {
        return current_user->id;
    }     
  return -1;
}
bool Full(MaxQueue* queue)
{
    if ((queue->rear + 1) % MAX_NUMS == queue->front) {
        return true;
    }
    return false;
}


void maxQueuePush_back(MaxQueue* queue, int value) {
    if (!Full(queue)) {
        queue->arr[queue->rear].val = value;
        queue->rear = (queue->rear + 1) % MAX_NUMS;
        my_struct *find = 0;
        HASH_FIND_INT(g_hash,&value,find);
        if(find == 0) {
            find = malloc(sizeof(my_struct));
            find->id = value;
            find->count = 1;
            HASH_ADD_INT(g_hash,id,find);
        }
        else
        {
            find->count++;
        }
    }
}

bool Empty(MaxQueue* queue)
{
    return queue->front == queue->rear;
}
void maxQueueFree(MaxQueue* obj) {
    if(obj != 0)
       free(obj);
    my_struct *current_user, *tmpuseless;
    HASH_ITER(hh, g_hash, current_user, tmpuseless) {
        HASH_DEL(g_hash,current_user); 
        free(current_user); 
    }       
}


int maxQueuePop_front(MaxQueue* queue)
{
    int t = -1;
    if (!Empty(queue)) {
        t = queue->arr[queue->front].val;
        
        queue->front = (queue->front + 1) % MAX_NUMS;
        
        my_struct *find = 0;
        HASH_FIND_INT(g_hash,&t,find);

        if(find != 0) {
            if(find->count > 1) {
                find->count--;
            }
            else {
                HASH_DEL(g_hash,find); 
                free(find);                
            }
        }      
    }
   
    return t;
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/
```