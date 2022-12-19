### 解题思路
划分三个区间，分别求count

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
struct TreeNode * g_node;
void find(struct TreeNode * node, int x) 
{
    if(node == 0) {
        return 0;
    }
    if(node->val == x) {
        g_node = node;
        return;
    }
    if(node->left != 0) {
       find(node->left,x);
    }
    if(node->right != 0) {
      find(node->right,x);
    }
}
int getLeft(struct TreeNode * node)
{
    if(node == 0) {
        return 0;
    }
    return 1+ getLeft(node->left)+getLeft(node->right);
}

int getRight(struct TreeNode * node)
{
    if(node == 0) {
        return 0;
    }
    return 1+ getRight(node->left)+getRight(node->right);

}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x){

    int cnt = 0;
    int cnt1 = 0;
    g_node = 0;
    find(root, x);
    if(g_node ==0)
    {
        return false;
    }
    cnt = getLeft(g_node->left);

    cnt1 = getRight(g_node->right);


    int otherCount = n - cnt - cnt1 - 1;


    // 以一号玩家选择的节点为中心，划分了三个区域，二号玩家从中选择一个区域，
    // 只要有一个区域大于一半以上的节点数，就判断二号玩家可以获胜
    if (cnt > n/2 || cnt1 > n/2 || otherCount > n/2) {
        return true;
    }
    return false;


}
```