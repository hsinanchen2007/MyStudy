### 解题思路
依次求取各树节点的左右子树深度之和，取其最大值。
当左右节点深度合小于总深度后，返回最大值。

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


int diameterOfBinaryTree(struct TreeNode* root){
    int dfs(struct TreeNode* root,int k){//求深度
            if(root==NULL) return k;
            int left=dfs(root->left,k+1);
            int right=dfs(root->right,k+1);
            return fmax(left,right);
        }
    int Depth=dfs(root,0);//总深度
    int dfsdiameter(struct TreeNode* root){//求左右子树最大值和
        if(root==NULL) return 0;
        int left_depth=dfs(root->left,0);
        int right_depth=dfs(root->right,0);
        int maxdiameter=left_depth+right_depth;
        if (left_depth+right_depth>=Depth){
            int left_diameter=diameterOfBinaryTree(root->left);
            maxdiameter=fmax(maxdiameter,left_diameter);
            int right_diameter=diameterOfBinaryTree(root->right);
            maxdiameter=fmax(maxdiameter,right_diameter);
        }    
        return maxdiameter;
    }
    return dfsdiameter(root);
}
```