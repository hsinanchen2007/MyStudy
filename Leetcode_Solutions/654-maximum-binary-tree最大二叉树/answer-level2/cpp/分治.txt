### 解题思路
先找出数组最大元素max,下角标为max_i,再把问题分解为构造max_i左边数组的最大二叉树和构造max_i右边数组的最大二叉树。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
int minm = -pow(2, 31)+1;
void build(TreeNode*ptr,int start,int end,vector<int>&nodes)
{
	int max = minm;
	int max_i = 0;
	for (int i = start; i <= end; i++)
	{
		if (nodes[i] > max)
		{
			max = nodes[i];
			max_i = i;
		}
	}
	ptr->val = max;
	if(start<max_i)
	ptr->left = new TreeNode(0);
	else ptr->left = NULL;
	if(end>max_i)
	ptr->right = new TreeNode(0);
	else ptr->right = NULL;
	if (start < max_i)
	build(ptr->left, start, max_i-1, nodes);
	if (end > max_i)
	build(ptr->right, max_i + 1, end, nodes);
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int size=nums.size();
        TreeNode*root=new TreeNode(0);
        build(root,0,size-1,nums);
        return root;
    }
};
```