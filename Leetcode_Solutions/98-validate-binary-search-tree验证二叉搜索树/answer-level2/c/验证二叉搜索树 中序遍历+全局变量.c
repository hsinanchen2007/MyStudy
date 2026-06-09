### 解题思路
二叉搜索树性质之一：中序遍历时，依次从小到大输出

所以把以前写的中序遍历输出二叉树的代码稍稍做了一些修改（print语句改为判断条件）

判断条件：
【当前输出数】大于【前一个输出数】时，满足二叉搜索树
【当前输出数】小于【前一个输出数】时，不满足二叉搜索树

引入了全局变量
temp 前一个输出数
flag 是否满足二叉搜索树的标识
因为leetcode里c语言的全局变量会有一些小问题，所以另写了一个函数作为递归函数，并且在isValidBST函数每次结束时还原全局变量的初始值。


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


long int temp=-2147483649;
int flag=1;

bool isValidBST(struct TreeNode*root) {
	valid(root);
    temp=-2147483649;
    if (flag==1)
    return true;
    else
    {
        flag=1;
        return false;
    }
    

}

int valid(struct TreeNode* root)
{
	if (root == NULL)
	{
		return flag;
	}
	else {
		valid(root->left);
		if (root->val <= temp)
		{
			flag = 0;
		}
        temp=root->val;		
		valid(root->right);
	}
	return flag;
}
```