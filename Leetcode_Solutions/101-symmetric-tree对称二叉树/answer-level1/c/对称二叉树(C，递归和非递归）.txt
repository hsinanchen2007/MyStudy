### 解题思路
1. 递归
2. 非递归（层次遍历）

# 递归
```
bool isMirror(struct TreeNode* p, struct TreeNode* q)
{
    if(!p && !q)
        return 1;
    if(!p || !q)
        return 0;
    if(p->val == q->val)
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    else
        return 0;
}

bool isSymmetric(struct TreeNode* root){
    return isMirror(root, root);
}
```

# 非递归
```c
#define QUEUESIZE 200

bool isSymmetric(struct TreeNode* root){
    if(!root)
        return 1;
    if(!root->left && !root->right)
        return 1;
    if(!root->left || !root->right)
        return 0;

    /*init queue*/
    struct TreeNode* q1[QUEUESIZE];
    struct TreeNode* q2[QUEUESIZE];
    int front1, rear1, front2, rear2;
    front1 = rear1 = front2 = rear2 = -1;
    q1[++rear1] = root->left;
    q2[++rear2] = root->right;

    struct TreeNode *a, *b;
    while(front1 < rear1){
        a = q1[++front1];
        b = q2[++front2];
        if(!a && !b)
            continue;
        if(!a || !b)
            return 0;
        if(a->val != b->val)
            return 0;
        q1[++rear1] = a->left;
        q2[++rear2] = b->right;
        q1[++rear1] = a->right;
        q2[++rear2] = b->left;
    }
    return 1;
}
