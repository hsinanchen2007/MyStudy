![1.png](https://pic.leetcode-cn.com/a6d1daf4f72bf270b422974e387deb49d5c4a21b2155c9dd815ee9f14e5e5f5b-1.png)


解题思路：
1、判断二叉树的高度；
2、根据高度申请返回数组的长度；
3、根据高度申请数组返回的标记；
4、二叉树遍历，按照根节点->右子树->左子树 顺序；
5、每一层有识别到需要返回值后直接标记，当所有高度的数组都标记成功后，直接返回；

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int depth(struct TreeNode* root,int m) {
    int n_l,n_r;
    if (root == NULL) return m;
    n_l = depth(root->left,m+1);
    n_r = depth(root->right,m+1);
    return (n_l > n_r ? n_l : n_r);

}

void dfs(struct TreeNode* root,int *ret,bool *f,int max_level,int level) {
    if (root == NULL) return;
    
    if (f[level] == false) {
        f[level] = true;
        ret[level] = root->val;
        if (level == max_level - 1) return;
    }
    if (root->right) {
        dfs(root->right,ret,f,max_level,level+1);
    }
    if (root->left) {
        dfs(root->left,ret,f,max_level,level+1);
    }
}
int* rightSideView(struct TreeNode* root, int* returnSize){
    int *ret;//返回的数组
    bool *f;//根据深度，标记是否作为返回值，初始值为false，作为返回值为true
    int level;//二叉树的高度（返回数组的长度）

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    level = depth(root ,0);
    //printf("max_level=%d\n",level);

    ret = (int*)malloc(sizeof(int)*level);
    //memset(ret,0,sizeof(int)*level);
    f = (bool*)malloc(sizeof(bool)*level);
    memset(f,false,sizeof(bool)*level);

    dfs(root,ret,f,level,0);

    *returnSize = level;
    return ret;

}
```







