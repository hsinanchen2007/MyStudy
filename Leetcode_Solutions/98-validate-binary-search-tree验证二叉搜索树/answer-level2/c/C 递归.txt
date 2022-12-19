### 解题思路
整体思路还是中序遍历整棵树。
首先判断根节点的左右孩子是否满足大小条件；
然后分别以左右孩子为根节点，递归考察 root 的左右子树；
具体见注释：

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
/*
执行用时 :12 ms, 在所有 C 提交中击败了63.58% 的用户
内存消耗 :9.9 MB, 在所有 C 提交中击败了92.37%的用户
*/
bool traverse(struct TreeNode* root, struct TreeNode* smaller, struct TreeNode* bigger){
    if (!root) return true;
    //考察根节点和左右孩子的大小关系
    if(smaller != NULL && (smaller->val > root->val || smaller->val == root->val)) return false;
    if(bigger != NULL && (bigger->val < root->val || bigger->val == root->val)) return false;

    //考虑右子树 -- root 比 root->right 小，所以 smaller == root
    if(!traverse(root->right,root,bigger)) return false;
    //考虑左子树 -- root 比 root->left 大，所以新的 bigger == root
    if(!traverse(root->left,smaller,root)) return false;
    return true;
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL)
        return true;
    return traverse(root,NULL,NULL);
}
```