### 解题思路

    1、拿钥匙进入对应房间，把房间里的钥匙串拿起来，放到（队列or栈）中。
    2、从队列中拿走一把钥匙，插到对应房间的门上打开房门，把该房间的钥匙串，也放到（队列or栈）中。
    就这样，依次用（队列 or 栈）中的钥匙，打开对应的门，拿走钥匙放到（栈or队列）中。
    如果到最后，（队列 or 栈）中钥匙用完后，检查房门是否全部被打开即可。

    如何判断房门是否已经被打开？
    建立一个数组，对应位置为1，表示房间被打开过。

    用队列还是栈？我认为都可以。以下用队列解。


### 代码

```c

/**************************通用队列实现：以下**************************/
typedef struct tagQUEUE_NODE_S{
    struct tagQUEUE_NODE_S *priv;
    struct tagQUEUE_NODE_S *next;
    void *data;   
}QUEUE_NODE_S;

/* 
    使用循环双向链表实现队列
    retval: 返回一个节点的地址，其中它的next为队列头，priv为队列尾
*/
QUEUE_NODE_S *queue_init(void) {
    QUEUE_NODE_S *node = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_NODE_S));
    if (node == NULL) {
        return NULL;
    }

    node->next = node;
    node->priv = node;
    node->data = NULL;
    return node;
}

/*
    description： 首尾相等，则队列为空。
    param：
        node：队列指针
    attention： 调用者保证指针不为空
*/
bool queue_is_empty(QUEUE_NODE_S *node) {
    if (node->next == node->priv && node->next == node) {
        return true;
    }

    return false;
}

/*
    description： 数据从队列尾入队
    param：
        node：队列指针
        data：需要入队的数据
    attention： 调用者保证指针不为空
*/
void queue_in(QUEUE_NODE_S *node, void *data) {
    QUEUE_NODE_S *newNode = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_NODE_S));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = node;
    newNode->priv = node->priv;
    node->priv->next = newNode;
    node->priv = newNode;

    return;
}
/*
    description： 数据从队列首出队
    param：
        node：队列指针
    retval：出队的数据,
    attention： 调用者释放返回的data
*/
void *queue_out(QUEUE_NODE_S *node)
{
    QUEUE_NODE_S *outNode = node->next;
    outNode->next->priv = node;
    node->next = outNode->next;

    void *data = outNode->data;
    free(outNode);
    outNode = NULL;

    return data;
}

/* 销毁队列 */
void queue_destroy(QUEUE_NODE_S *node)
{
    QUEUE_NODE_S *curNode = node;
    QUEUE_NODE_S *nextNode = node->next;

    while (curNode != NULL) {
        if (curNode->data != NULL) {
            free(curNode->data);
            curNode->data = NULL;
        }
        /* 先摘链，再释放 */
        if (curNode->next == curNode->priv && curNode->next == curNode) {
            free(curNode);
            curNode = NULL;
        } else {
            nextNode = curNode->next;
            curNode->next->priv = curNode->priv;
            curNode->priv->next = curNode->next;
            free(curNode);
            curNode = nextNode;
        }
    }
    return;
}

void PutKeysToQueue(QUEUE_NODE_S *keyQueue, int *keys, int num) 
{
    int i;
    //printf("[D] PutKeysToQueue input %d \n", num);
    for (i = 0; i < num; i++) {
        if (keys[i] == 0) {
            continue;
        }
        int *key = (int *)malloc(sizeof(int));
        if (key != NULL) {
            *key = keys[i];
            //printf("[D] key in %d \n", *key);
            keys[i] = 0;
            queue_in(keyQueue, key);
        }
    }
    return;
}

bool IsAllHouseOpen(int *houses, int num)
{
    int i;
    for (i = 0; i < num; i++) {
        //printf("[D] house %d: %d \n", i, houses[i]);
        if (houses[i] == 0) {
            return false;
        }
    }
    return true;
}
#define HOUSE_OPEN 1

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    if (rooms == NULL || roomsColSize == NULL) {
        return false;
    }
    //printf("[D] canVisitAllRooms input %d %d\n", roomsSize, *roomsColSize);
    int *houses = (int *)malloc(sizeof(int) * roomsSize);
    if (houses == NULL) {
        return false;
    }
    int ret = memset(houses, 0, sizeof(int) * roomsSize);
    houses[0] = HOUSE_OPEN;

    QUEUE_NODE_S *keyQueue = queue_init(); 
    PutKeysToQueue(keyQueue, rooms[0], roomsColSize[0]);

    while(!queue_is_empty(keyQueue)) {
        int *key = queue_out(keyQueue);
        if (key == NULL) {
            continue;
        }
        //printf("[D] key out %d roomsSize: %d\n", *key, roomsSize);
        if (*key < roomsSize) {
            houses[*key] = 1;
            PutKeysToQueue(keyQueue, rooms[*key], roomsColSize[*key]);
        }
    }
    bool result = IsAllHouseOpen(houses, roomsSize);
    //printf("[D] result %d \n", result);
    queue_destroy(keyQueue);
    free(houses);
    
    return result;
}
```