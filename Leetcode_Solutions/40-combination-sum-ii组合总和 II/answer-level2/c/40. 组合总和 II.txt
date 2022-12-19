### 解题思路
比第39题，多了一个去重；
if (i > index && candidates[i] == candidates[i - 1]) {
    continue;
}
![image.png](https://pic.leetcode-cn.com/863cb2de8011ba0d4fe91569865ad6377215f83db957ffd5e390c37061307c7b-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXSIZE 500
typedef int DATATYPE;
typedef struct Node {
    DATATYPE val;
    int cnt;
    struct Node* next;
}Node;

typedef struct Stack {
    Node* bottom;
    Node* top;
}Stack;

int Check(const void* a, const void* b)
{
    int ta = *(const int *)a;
    int tb = *(const int *)b;
    return (ta > tb) - (ta < tb);
}

Stack *Init()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    memset(s, 0, sizeof(Stack));
    s->bottom = NULL;
    s->top = NULL;
    return s;
}

void Push(Stack* s, DATATYPE val)
{
    if (s == NULL) {
        return;
    }
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        return;
    }
    memset(n, 0, sizeof(Node));
    n->val = val;
    n->next = NULL;
    n->cnt = 1;
    if (s->bottom == NULL) {
        s->bottom = n;
        s->top = n;
    } else {
        n->cnt = s->top->cnt + 1;
        n->next = s->top;
        s->top = n;
    }
}

void Pop(Stack* s)
{
    if (s == NULL) {
        return;
    }
    Node* n = s->top;
    if (n == NULL) {
        return;
    }
    if (n->next == NULL) {
        s->bottom = NULL;
        s->top = NULL;
    } else {
        s->top = n->next;
    }
    free(n);
    n = NULL;
}

bool IsEmpty(Stack* s)
{
    if (s == NULL) {
        return true;
    }
    return s->bottom == NULL;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    if (candidates == NULL) {
        return NULL;
    }
    *returnSize = 0;
    *returnColumnSizes = (int *)calloc(sizeof(int), MAXSIZE);
    int** ret = (int **)calloc(sizeof(int), MAXSIZE);
    Stack* s = Init();
    qsort(candidates, candidatesSize, sizeof(int), Check);
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, s, ret, 0);
    return ret;
}

void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, Stack* s, int** ret, int index)
{       
    if (target == 0) {
        int retcnt = s->top->cnt;
        int* retEach = (int *)calloc(sizeof(int),  retcnt);
        Node* n = s->top;
        for (int k = retcnt - 1; k > -1; k--) {
            retEach[k] =  n->val;
            n = n->next;
        }
        ret[*returnSize] = retEach;
        (*returnColumnSizes)[*returnSize] = retcnt;
        *returnSize += 1;
        return;
    }
    for (int i = index; i < candidatesSize; i++) {
        if (target < candidates[i]) {
            break;
        }
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }
        Push(s, candidates[i]);
        dfs(candidates, candidatesSize, target - candidates[i] , returnSize, returnColumnSizes, s, ret, i + 1);
        Pop(s);
    }
}
```