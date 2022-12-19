# 递归
```
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q)
        return 1;
    if(!p)
        return 0;
    if(!q)
        return 0;
    if(p->val == q->val) 
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else
        return 0;
}
```
# 非递归（层次遍历）
```
#define QUEUESIZE 100 

/*判断两个节点值是否相同，这里不包括都为空的情况*/
bool same(struct TreeNode* p, struct TreeNode* q)
{
    if(!p || !q)
        return 0;
    if(p->val == q->val)
        return 1;
    else
        return 0;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(!p && !q)
        return 1;
    if(!same(p, q))
        return 0;

    /*init queue*/
    struct TreeNode* q1[QUEUESIZE];
    struct TreeNode* q2[QUEUESIZE];
    int front1, rear1, front2, rear2;
    front1 = rear1 = front2 = rear2 = -1;
    q1[++rear1] = p;
    q2[++rear2] = q;

    struct TreeNode *a, *b;
    while(front1 < rear1){
        a = q1[++front1];
        b = q2[++front2];
        if(!same(a, b))
            return 0;
        if(a->left || b->left){
            q1[++rear1] = a->left;
            q2[++rear2] = b->left;
        }
        if(a->right || b->right){
            q1[++rear1] = a->right;
            q2[++rear2] = b->right;
        }
    }
    return 1;
}
```

