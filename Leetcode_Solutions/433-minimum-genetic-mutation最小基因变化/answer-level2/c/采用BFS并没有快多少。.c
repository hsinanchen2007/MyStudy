### 解题思路
此处撰写解题思路

### 代码

```c

#define MAX_NUMS 100001
typedef struct NODE_
{
    char *pstr;    
    int level;
}Node;
typedef struct Queue_ {
    Node arr[MAX_NUMS];
    int front;
    int rear;
}Queue;

void QueueInit(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int QueueCnt(Queue *queue)
{
    return abs(queue->rear - queue->front);
}
bool Full(Queue* queue)
{
    if ((queue->rear + 1) % MAX_NUMS == queue->front) {
        return true;
    }
    return false;
}
bool Empty(Queue* queue)
{
    return queue->front == queue->rear;
}
void QueuePush(Queue* queue, Node node)
{
    if (!Full(queue)) {
        queue->arr[queue->rear] = node;
        queue->rear = (queue->rear + 1) % MAX_NUMS;
    }
}
void QueuePop(Queue* queue)
{
    if (!Empty(queue)) {
        queue->front = (queue->front + 1) % MAX_NUMS;
    }
}
void QueueClear(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}
Node QueueTop(Queue* queue)
{
    return queue->arr[queue->front];
}

int isMatch(char *bank, char *tmpstr)
{
    int cnt = 0;
    char *p = bank;
    char *q = tmpstr;
    while(*bank != '\0') {
        if(*bank != *tmpstr) {
            cnt++;
        }
        bank++;
        tmpstr++;
    }
   
    if(cnt == 1) {
        return 1;
    }
    return 0;

}

int minMutation(char * start, char * end, char ** bank, int bankSize){
     /*start进入队列后，看下一个能扩展的*/
     Queue myQueue;
     if(bankSize == 0)
     {
         return -1;
     }
     int visit[bankSize];
     for(int i = 0; i < bankSize; i++) {
         visit[i] = 0;
     }
     QueueInit(&myQueue);
     Node myNode;
     myNode.pstr = start;
     myNode.level = 0;
     QueuePush(&myQueue, myNode);
     int level = -1;
     while(!Empty(&myQueue)) {

         for(int i = 0; i < QueueCnt(&myQueue); i++) {
            Node tmp = QueueTop(&myQueue);
            //printf("%s, output %s \r\n", tmp.pstr, end);
            if(strcmp(tmp.pstr,end) == 0)
            {
               level = tmp.level;
               return level;
               QueueClear(&myQueue);
            }
             QueuePop(&myQueue);
             for(int j = 0; j < bankSize; j++) {
                
                 if(isMatch(tmp.pstr, bank[j]) && visit[j] == 0)
                 {
                    // printf("%s, now %s \r\n", bank[j], tmp.pstr);
                     visit[j] = 1;
                     Node tmpNode;
                     tmpNode.pstr = bank[j];
                     tmpNode.level = tmp.level+1;
                     QueuePush(&myQueue, tmpNode);
                     
                 }
             }
         }
     }
     QueueClear(&myQueue);
     return level;
}


```