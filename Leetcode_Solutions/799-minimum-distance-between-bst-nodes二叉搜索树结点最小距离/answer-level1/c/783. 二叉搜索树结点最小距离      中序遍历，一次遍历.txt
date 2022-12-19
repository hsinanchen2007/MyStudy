### 解题思路
给定一个二叉搜索树的根结点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。


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
void helper(struct TreeNode* root, int *arr, int *index){
    if(root == NULL)    return;

    helper(root->left, arr, index);
    arr[(*index)++] = root->val;
    helper(root->right, arr, index);
}

int minDiffInBST(struct TreeNode* root){
    int i, len = 0, arr[100] = {0}, min;

    helper(root, arr, &len);
    min = arr[1] - arr[0];
    for (i = 1; i < len; i ++)
        min = MIN(min, arr[i] - arr[i-1]);

    return min;
}
```