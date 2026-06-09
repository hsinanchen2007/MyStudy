### 解题思路
可能是搞复杂了：
1、先排序；
2、建立一个栈，每次压入一个数，并计数，判断栈内元素是否满足target，满足target则遍历输出，弹出栈顶元素；
![image.png](https://pic.leetcode-cn.com/4c0c9eddfdcfacc31eb825fdb7d3d9600738a2760edd4258b825ae1d29afa774-image.png)

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

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
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
        // 剪枝
        if (target < candidates[i]) {
            break;
        }
        Push(s, candidates[i]);
        dfs(candidates, candidatesSize, target - candidates[i] , returnSize, returnColumnSizes, s, ret, i);
        Pop(s);
    }
}

```