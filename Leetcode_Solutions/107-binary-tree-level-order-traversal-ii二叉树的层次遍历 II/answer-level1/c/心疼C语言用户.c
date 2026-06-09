### 解题思路
层序遍历，广度优先搜索，需要队列容器，
可惜C语言没有STL, 只能自己写个简化版

### 代码

```c
typedef struct TreeNode * ElemType;
typedef struct {
    ElemType *data;
    int capacity;
    int front, rear;
    int size;
 } Queue;

 void init(Queue * q, int capacity)
 {
     q->data = (ElemType *)malloc(sizeof(ElemType)*capacity);
     q->capacity = capacity;
     q->front = 0;
     q->rear = 0;
     q->size = 0;
 }

 void push(Queue * q, const ElemType e)
 {
     q->data[q->rear] = e;
     q->rear = (q->rear + 1) % q->capacity;
     q->size++;
 }

 void pop(Queue * q, ElemType * e)
 {
     *e = q->data[q->front];
     q->front = (q->front + 1) % q->capacity;
     q->size--;
 }

 int empty(Queue * q)
 {
     return q->size == 0 ? 1 : 0;
 }

 int maxdepth(struct TreeNode * root)
 {
     if(root == NULL) return 0;
     return fmax(maxdepth(root->left) + 1, maxdepth(root->right) + 1);
 }

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL) {
        *returnSize = 0;
        return res;
    }
    int level =  maxdepth(root); // 获得层数，不然不好申请内存空间，ps.也可以开个1000的空间
    *returnSize = level;
    int ** res = malloc(sizeof(int *) * level);
    (*returnColumnSizes) = malloc(sizeof(int) * level);
    Queue q; init(&q, 1000);

    push(&q, root);
    ElemType e;

    int j = level - 1; // 变态的地方，非要倒着来
    while(!empty(&q)){
        int len = q.size; // 每一层节点数
        (*returnColumnSizes)[j] = len; // 返回列数，不理解非要二重指针，一重指针不就行了，太不友好了
        res[j] = (int *)malloc(sizeof(int) * len); // 申请空间
       
        int k = 0;
        for(int i = 0; i < len; i++){
            pop(&q, &e);
            res[j][k++] = e->val; // 保存节点
            if(e->left) push(&q, e->left);
            if(e->right) push(&q, e->right);
        }
        j--; // 这里不能丢
    }

    return res;
}
```