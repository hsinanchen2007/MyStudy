### 解题思路
计算每个节点的所属节点数（包括自己的一个和左右子树的所属节点数），深度优先搜索计算每个节点的值
如果遍历到被染红的节点，就需要判断这个节点的所属节点值是否大于 n / 2,如果小于等于n / 2,说明只要
占据其父节点就能超过它，如果大于n / 2，就要看其两个子节点中的是否有任何一个的所属节点大于n / 2，
如果有，占据这个子节点就可以了

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
int DFS(struct TreeNode* root, int n, int x, bool *ret)
{
    int leftNum = 0;
    int rightNum = 0;
    int belongNum = 0;
    // 如果为空返回0
    if (root == NULL) {
        return belongNum;
    }
    // 计算左右子树的所属节点数
    leftNum = DFS(root->left, n, x, ret);
    rightNum = DFS(root->right, n, x, ret);
    // 加上自身的一个
    belongNum = leftNum + rightNum + 1;
    // 如果这个节点是被红色染色的节点
    if (root->val == x) {
        // 如果这个节点所属节点小于等于n / 2, 堵住它的父节点就可以比它多，为true
        if (belongNum <= n / 2) {
            *ret = true;
        } else {
            // 如果节点所属节点数量大于 n / 2, 就要考察它的左右子树，如果有一个比n / 2大，为true
            if (leftNum > n / 2 || rightNum > n / 2) {
                *ret = true;
            }
        }
    } 
    return belongNum;
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
    bool ret = false;
    DFS(root, n, x, &ret);
    return ret;
}
```