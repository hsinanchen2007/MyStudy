执行结果：通过 执行用时 :12 ms, 在所有 c 提交中击败了99.21%的用户 内存消耗 :11.5 MB, 在所有 c 提交中击败了100.00%的用户

题目解读：
首先，题目告诉我们是在一个有序的二叉搜索树中有两个节点被交换了，那么存在两种交换情况：
1. 相邻节点交换；
2. 不相邻节点交换。
第1种情况下，只有一对前后关系是错误的，第2种情况下，有两对前后关系是错误的，其中第一对错误的关系中，一定是前面那个数错了，第二对错误关系中，一定是后面那个数错了。（大数换到前面，肯定是比其后面的数大导致关系错，小数换到后面肯定是比它前面的数小导致关系错误。）

所以，两种情况交换原则：
1. 相邻节点直接交换。
2. 第一对错误关系的前面节点，与第二对错误关系的后面节点交换。

代码实现如下：
中序遍历一遍二叉树，记录关系不对的前后两个节点，
如果只有一对节点关系不对，交换之；
如果有两对节点关系不对，将第一对的前面那个和第二对的后面那个交换之。
```
int midOrder(struct TreeNode **pre, struct TreeNode **err1, struct TreeNode **err2, struct TreeNode *root)
{
    if (root == NULL) return 0;
    
    if (midOrder(pre, err1, err2, root->left) == -1) return -1;
    if (*pre != NULL && (*pre)->val > root->val) {
        if (*err1 == NULL) {
            *err1 = *pre;
            *err2 = root;
        } else {
            *err2 = root;
            return -1;
        }
    }
    *pre = root;
    if (midOrder(pre, err1, err2, root->right) == -1) return -1;
    return 0;
}

void recoverTree(struct TreeNode* root){
    struct TreeNode *pre = NULL;
    struct TreeNode * err1 = NULL;
    struct TreeNode * err2 = NULL;
    midOrder(&pre, &err1, &err2, root);
    
    int tmp;
    tmp = err1->val;
    err1->val = err2->val;
    err2->val = tmp;
    return;
}
```
