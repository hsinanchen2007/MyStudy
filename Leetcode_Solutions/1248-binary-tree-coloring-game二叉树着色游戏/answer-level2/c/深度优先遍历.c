### 解题思路
要想取胜，答案的第一步就是选一号已选用的节点的左孩子，右孩子和父节点中的一个，
只要遍历找到这三个节点的各自联通的节点数，只要有一个超过总节点树的一半，就能赢。

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

int dfs(struct TreeNode *root, int x, int *leftCnt, int *rightCnt) {

    int count = 1;
    if (root->val == x) {
        if (root->left != NULL)
            *leftCnt = dfs(root->left,-1,leftCnt,rightCnt);
        else
            *leftCnt = 0;
        if (root->right != NULL)
            *rightCnt = dfs(root->right, -1, leftCnt,rightCnt);
        else
            *rightCnt = 0;
   //     printf("left is %d, right is %d\n",*leftCnt, *rightCnt);
        return 0;
    }
    if (root->left != NULL)
        count += dfs(root->left,x,leftCnt,rightCnt);
    if (root->right != NULL)
        count += dfs(root->right,x,leftCnt,rightCnt);
  //  printf("count is %d\n",count);    
    return count;
} 

bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
    
    if (n <= 0 || x > n || x < 0)
        return false;
    
    int leftCnt = 0;
    int rightCnt = 0;
    int fatherCnt = dfs(root,x, &leftCnt, &rightCnt);

    if (fatherCnt > n / 2 || leftCnt > n / 2 || rightCnt > n / 2)
        return true;
    return false;
 

}
```