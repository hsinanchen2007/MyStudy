# 124. 二叉树中的最大路径和
```
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
private:
	int max;
public:
	//计算四数中最大数
	int findForeMax(int num1,int num2,int num3,int num4)
	{
		return (num4>num3?num4:num3)>(num1>num2?num1:num2)?(num4>num3?num4:num3):(num1>num2?num1:num2);
	}
	//计算三数中最大数
	int findTriMax(int num1,int num2,int num3)
	{
		return num3>(num1>num2?num1:num2)?num3:(num1>num2?num1:num2);
	}

    int recursion(TreeNode* root) 
	{
		if( root != NULL )
		{
			int left_max  = recursion(root->left);
			int right_max = recursion(root->right);
			int tempMax = findForeMax(left_max+root->val,right_max+root->val,left_max+root->val+right_max,root->val);
			
			if(tempMax > max)
				max = tempMax;
			
			return findTriMax(left_max+root->val,right_max+root->val,root->val);
		}
		else
		{
			return 0;
		}
    }
	
	int maxPathSum(TreeNode* root) 
	{
		if(root != NULL)
		{
			max = root->val;
			recursion(root);
		}
		return max;
	}
};
```
