```

#define LEN 12800

typedef struct HashNode {
    int id;   // we'll use this id as key
    UT_hash_handle hh; // make this structure hashable
} HashNode;

typedef HashNode* HashHead;

int count_user(HashHead head);

HashNode* find_user(HashHead head, int id) {
    HashNode *s;
    HASH_FIND_INT(head, &id, s); // s: output pointer
    return s;
}

void add_user(HashHead* head, HashNode* users) {
    if (!find_user(*head, users->id)) {
        HASH_ADD_INT(*head, id, users);
    }
}

int count_user(HashHead head) {
    return HASH_COUNT(head);
}

void print_user(HashHead head) {
    HashNode *s;
    printf("size is %d\n", count_user(head));
    for (s = head; s != NULL; s = s->hh.next) {
        printf("user id %d\n", s->id);
    }
}

// 队列
typedef struct Node
{
    int id;
} Node;

typedef struct QNode {
    Node data;
    struct QNode* next;
}QNode;


typedef struct {
    QNode* front; // 指向对头节点
    QNode* rear; // 指向队尾节点
}Queue;


Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        // printf("空间不足\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void AddQ(Queue* q, Node item) {
    QNode* qNode = (QNode*)malloc(sizeof(QNode));
    // 这个很重要，next要置空
    qNode->next = NULL;
    if (!qNode) {
        return;
    }
    // 赋值
    qNode->data.id = item.id;
    if (q->front == NULL) {
        q->front = qNode;
    }
    if (q->rear == NULL) {
        q->rear = qNode;
    }
    else {
        // 原来最后节点之后再加节点
        q->rear->next = qNode;
        // 将这个节点设为最后节点
        q->rear = qNode;
    }
}

int IsEmptyQ(Queue* q) {
    return (q->front == NULL);
}

Node DeleteQ(Queue* q) {
    if (IsEmptyQ(q)) {
        // printf("空队列\n");
        // return ERROR;
    }
    QNode* temp = q->front;
    Node item;
    if (q->front == q->rear) { //若队列只有一个元素
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }
    item.id = temp->data.id;
    //free(temp);
    return item;
}

void PrintQueue(Queue* q) {
    if (IsEmptyQ(q)) {
        return;
    }
    printf("打印队列数据元素：\n");
    QNode* qNode = q->front;
    while (qNode != NULL) {
        printf("id = %d " , qNode->data.id);
        qNode = qNode->next;
    }
    printf("\n");
}

// 获取队列长度
int getListlength(Queue* q) { 
    int k = 0;
    QNode* qNode = q->front;
    while (qNode != NULL) {
        k++;
        qNode = qNode->next;
    }
    return k;
}




bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    // 节点的入度
    int nHash[LEN] = {0};
    int i = 0;
    for (i = 0; i < n; i++) {
        // 有以leftChild[i]作为子节点，所以leftChild[i]的入度加加
        if (leftChild[i] != -1) {   
            nHash[leftChild[i]]++;
        }
        if (rightChild[i] != -1) {
            nHash[rightChild[i]]++;
        }
    }

    int root = -1;
    for (i = 0; i < n; i++) {
        // 如果一个节点的入度为0，那么这个节点可以作为根节点
        if (nHash[i] == 0) {
            root = i;
            break;
        }
    }
 
    // 说明没有根节点
    if (root == -1) {
        return false;
    }

    HashHead seen = NULL;
    HashNode* node1 = malloc(sizeof(HashNode));
    node1->id = root;
    add_user(&seen, node1);
    // print_user(seen);

    
    Queue* q = CreateQueue();
    Node node2;
    node2.id = root;
    AddQ(q, node2);
    // PrintQueue(q);

    while (!IsEmptyQ(q)) {
        int u = q->front->data.id;
        DeleteQ(q);
        if (leftChild[u] != -1) {
            if (find_user(seen, leftChild[u])) {
               return false;
            }
            HashNode* temp1 = malloc(sizeof(HashNode));
            temp1->id = leftChild[u];
            add_user(&seen, temp1);
            // print_user(seen);

            node2.id = leftChild[u];
            AddQ(q, node2);
            // PrintQueue(q);
        }
        if (rightChild[u] != -1) {
            if (find_user(seen, rightChild[u])) {
                return false;
            }
            HashNode* temp2 = malloc(sizeof(HashNode));
            temp2->id = rightChild[u];
            add_user(&seen, temp2);

            node2.id = rightChild[u];
            AddQ(q, node2);
            // PrintQueue(q);
        }
    }
    
    return count_user(seen) == n;
}
```
