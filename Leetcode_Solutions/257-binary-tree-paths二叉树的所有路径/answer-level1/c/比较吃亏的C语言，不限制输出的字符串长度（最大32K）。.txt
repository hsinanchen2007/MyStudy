1. 采用stack对二叉树进行操作，遇到叶子结点就生成返回的整数 List。
2. 最后根据List的个数，再分配内存，并生成返回格式的字符串。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct __stack_item {
    int val;
    struct __stack_item *next;
    struct __stack_item *prev;
}StackItem;

typedef struct __list{
    int len;
    char *val;
    struct __list *next;
}List;

StackItem *pHead;
StackItem *pTop;

List *pl;
List *pt;
int list_count;

void list_create()
{
    list_count = 0;
    pl = pt = NULL;
}
void list_append(int *p, int len)
{
    List *pn;
    
    pn = malloc(sizeof(List));
    pn->len = len;
    pn->val = malloc(sizeof(int) * len);
    memcpy(pn->val, p, sizeof(int) * len);
    pn->next = NULL;
    
    if(pl!=NULL) {
        pt->next = pn;
        pt = pn;
    }else {
        pl = pt = pn;
    }
    list_count++;
}
void list_free()
{
    List *p, *pn;
    p = pl;
    while(p){
        pn = p->next;
        free(p);
        p = pn;
    }
}
void stack_create()
{ 
    pHead = NULL;
    pTop = NULL;
}

int stack_push(int val)
{
    StackItem *pn;    
    pn = malloc(sizeof(StackItem));
    pn->next = NULL;
    pn->prev = NULL;
    pn->val = val;    
    if(pHead == NULL) {
        pHead = pTop = pn;
    } else {
        pn->prev = pTop;
        pTop->next = pn;
        pTop = pn;
    }
    return val;
}
int stack_pop()
{
    StackItem *p;
    int x;
    p = pTop;
    pTop = pTop->prev;
    if(pTop)
        pTop->next = NULL;
    else
        pHead = NULL;
    x = p->val;    
    free(p);
    return x;
}
void stack_free()
{
    StackItem *p, *p1;
    p = pHead;
    while(p){
        p1 = p->next;
        free(p);
        p = p1;
    }
}

int tmp;
StackItem *s;
int len;
int *y;

void ScanTree(struct TreeNode* t)
{
    tmp = stack_push(t->val);
    if(t->left == NULL && t->right == NULL){ //output tree
        s = pHead;
        len = 0;
        while(s) {
            len++;
            s = s->next;
        }
        y = malloc(sizeof(int)*len);
        s = pHead;
        len = 0;
        while(s) {
            y[len++] = s->val;
            s = s->next;
        }
        list_append(y, len);
    }
    if(t->left)
        ScanTree(t->left);
    if(t->right)
        ScanTree(t->right);
    tmp = stack_pop();
}

char line_buf[32*1024];
char *get_string_from_int_array(int *val, int len){
    int i;
    int idx;
    char *p;
    int str_len;
    if(len==0)
        return NULL;
    idx = sprintf(line_buf, "%d", val[0]);
    for(i=1;i<len;i++) {
        idx += sprintf(line_buf+idx, "->%d", val[i]);
    }
    str_len = strlen(line_buf) + 1;
    p = malloc(str_len);
    memcpy(p, line_buf, str_len);
    memset(line_buf, 0, str_len);
    return p;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    
    int i;
    char **ret;
    List *li;
    
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    list_create();
    stack_create();
    
    ScanTree(root);
    
    ret = malloc(sizeof(char *) * list_count);
    
    memset(line_buf,0,32*1024);
    li = pl;
    for(i=0; i<list_count;i++) {
        ret[i] = get_string_from_int_array(li->val, li->len);
        li = li->next;
    }    
    *returnSize = list_count;    
    stack_free();
    list_free();
    return ret;
}