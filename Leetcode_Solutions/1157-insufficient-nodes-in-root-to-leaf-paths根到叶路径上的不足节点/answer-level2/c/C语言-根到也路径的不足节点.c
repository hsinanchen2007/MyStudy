### 解题思路
难点就是当某个叶子节点需要被删掉，如何防止把和不需要删除节点的公共父节点删除掉。
当父节点不确定是否要删除，那么看两个子节点是否需要删除，
    1、当两个子节点都需要删除，那么父节点也就要删除
    2、当两个子节点有一个不需要删除，那么父节点就不能被删除。
很显然这是一个或的运算关系。
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

bool dfs(struct TreeNode* root, int limit, int curSum);
struct TreeNode* sufficientSubset(struct TreeNode* root, int limit){
    return dfs(root, limit, 0) ? root : NULL ;

}
bool dfs(struct TreeNode* root, int limit, int curSum){
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        if (curSum + root->val >= limit) {
            return true;
        } else {
            false;
        }
    }
    bool leftGood = dfs(root->left, limit, curSum+root->val);
    if (!leftGood) {
        root->left = NULL;
    }
    bool rightGood = dfs(root->right, limit, curSum+root->val);
    if (!rightGood) {
        root->right = NULL;
    }
    return leftGood || rightGood;
}
```