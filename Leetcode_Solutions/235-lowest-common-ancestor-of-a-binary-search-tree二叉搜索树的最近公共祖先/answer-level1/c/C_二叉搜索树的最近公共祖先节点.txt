### 解题思路
更新（新建）二叉树，每一个节点都能找到其父节点。
由一个节点回溯到根节点的路径可以看成一个链表，于是问题就转化成了“找出p、q到root的两条路径链表的交点”
找两条单链表的交点问题就是“我走我的路，你走你的路，我们总路程一样、速度一样，如果我们的路有交点，我们一定会在交点相遇”

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//树的节点
typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* left;
    struct Node* right;
}Node;

//存一下老树中 p q 在新树中对应节点的地址
Node* P,*Q;

//更新树
Node* updataTree(struct TreeNode* Root,struct TreeNode* p,struct TreeNode* q,Node* Pre)
{
    if(Root==0)return 0;
    Node* n=(Node*)malloc(sizeof(Node));
    if(Root==p)P=n;
    if(Root==q)Q=n;
    n->data=Root->val;
    n->pre=Pre;
    n->left=updataTree(Root->left,p,q,n);
    n->right=updataTree(Root->right,p,q,n);
    return n;
}
//释放树内存
void freeTree(Node* Root)
{
    if(Root!=0)
    {
        freeTree(Root->left);
        freeTree(Root->right);
        free(Root);
    }
}
//根据值在旧树种查找对应节点的地址
struct TreeNode* address(struct TreeNode* Root,int Val)
{
    while(Root->val!=Val)
        Root=Root->val>Val?Root->left:Root->right;
    return Root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    Node* newRoot=updataTree(root,p,q,0);

    Node* iterP=P;
    Node* iterQ=Q;
    while(iterP!=iterQ)
    {
        iterP=iterP==newRoot?Q:iterP->pre;
        iterQ=iterQ==newRoot?P:iterQ->pre;
    }

    int val=iterP->data;
    freeTree(newRoot);
    return address(root,val);
}
```