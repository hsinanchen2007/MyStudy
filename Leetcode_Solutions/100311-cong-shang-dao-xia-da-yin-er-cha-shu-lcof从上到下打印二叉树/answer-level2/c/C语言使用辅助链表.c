### 解题思路
辅助链表

### 代码

```c
/* BFS */
#define MAX_LEN 10000

typedef struct TreeNode TreeNode;

typedef struct {
    int front;
    int rear;
    int size;
    TreeNode *arr[MAX_LEN];
} List;

List *newList()
{
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }

    list->front = -1;
    list->rear = -1;
    list->size = 0;
    memset(list->arr, 0x0, sizeof(TreeNode *) * MAX_LEN);
    return list;
}

void listPush(List *list, TreeNode *node)
{
    if ((list == NULL) || (list->rear >= MAX_LEN)) {
        return;
    }

    list->rear++;
    list->size++;
    list->arr[list->rear] = node;
    return;
}

TreeNode *listPop(List *list)
{
    if ((list == NULL) || (list->size == 0)) {
        return NULL;
    }

    list->front++;
    list->size--;
    return list->arr[list->front];
}

int isEmpty(List *list)
{
    if ((list == NULL) || (list->size == 0)) {
        return 1;
    }

    return 0;
}

int* levelOrder(struct TreeNode* root, int* returnSize)
{
    if (root == NULL) {
        *returnSize = 0;
        return;
    }

    List *list = newList();
    TreeNode *tmp = NULL;
    int index = 0;
    int *arr = (int *)malloc(sizeof(int) * MAX_LEN);
    if (arr == NULL) {
        return NULL;
    }

    memset(arr, 0x0, sizeof(int) * MAX_LEN);
    arr[index++] = root->val;
    listPush(list, root);

    while (isEmpty(list) != 1) {
        tmp = listPop(list);
        if (tmp->left != NULL) {
            listPush(list, tmp->left);
            arr[index++] = tmp->left->val;
        }

        if (tmp->right != NULL) {
            listPush(list, tmp->right);
            arr[index++] = tmp->right->val;
        }

    }

    *returnSize = index;
    return arr;
}
```