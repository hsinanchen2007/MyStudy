### 解题思路
此树父节点比子节点大，所以不用遍历所有节点。



给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

示例 1:

输入: 
    2
   / \
  2   5
     / \
    5   7

输出: 5
说明: 最小的值是 2 ，第二小的值是 5 。


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

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int dfs(struct TreeNode* root, int val) {
    if(root == NULL)
        return val;
    if(root->val > val)
        return root->val;
    
    int l, r;
    l = dfs(root->left, val);
    r = dfs(root->right, val);
    //printf("l=%d r=%d val=%d\n",l, r, val);
    if(l > val && r > val)
        return MIN(l, r);
    else
        return MAX(l, r);
}

int findSecondMinimumValue(struct TreeNode* root){
    int l,r;

    if(root == NULL || root->left == NULL)
        return -1;

    l = dfs(root->left, root->val);
    r = dfs(root->right, root->val);

    //printf("l=%d r=%d rootval=%d\n",l, r, root->val);
    if(l == r && l == root->val)    
        return -1;
    if(MIN(l,r) == root->val)   
        return MAX(l,r);
    else  
        return MIN(l,r);
}
```