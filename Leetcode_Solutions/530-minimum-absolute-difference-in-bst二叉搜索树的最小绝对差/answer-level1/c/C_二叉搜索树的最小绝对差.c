### 解题思路
任意两个点，不是相邻两个点。二叉搜索树中序遍历得到的序列是递增的，所以可以通过中序遍历，把题目转换成相邻两个点的最小差

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
void minTree(struct TreeNode* Root,int* lastVal, int* Min)
{
    if(Root==0) return;

    minTree(Root->left,lastVal,Min);

    int i= *lastVal>Root->val? *lastVal-Root->val: Root->val-*lastVal;
    *Min=*Min<i?*Min:i;
    *lastVal=Root->val;

    minTree(Root->right,lastVal,Min);
}

int getMinimumDifference(struct TreeNode* root){
    int result=(~((unsigned)0))>>1,lastVal=(~((unsigned)0))>>1;
    minTree(root,&lastVal,&result);
    return result;
}
```