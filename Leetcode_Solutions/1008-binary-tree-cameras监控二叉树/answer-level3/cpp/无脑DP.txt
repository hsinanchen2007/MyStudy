### 解题思路
把问题看成是求状态(up,ptr,must)的解，up为bool类型，表示父节点是否有监视器，ptr表示指向当前节点的指针，must表示是否必须有监控器，并将求出的解存入名为dp的map<bool,map<bool,int>>>中，以备下次使用。状态转移分多种情况，在代码中可以看出来。每个状态对于不同的must和up会有不同的求解方式。
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
int maxm=static_cast<int>(pow(2,31)-1);
int minCamera(bool up, TreeNode*ptr,bool must,map<TreeNode*,map<bool,map<bool,int>>>&dp)
{
	if (dp.count(ptr) != 0)
		if (dp[ptr].count(up) != 0)
			if (dp[ptr][up].count(must) != 0)
				return dp[ptr][up][must];
	if (up)
	{
		int lm = maxm;
		int rm = maxm;
		int min = maxm;
		int lv = 0;
		int rv = 0;
		if (ptr->left != NULL)
			lv = minCamera(!up, ptr->left,false,dp);
		else lv = 0;
		if (ptr->right != NULL)
			rv = minCamera(!up, ptr->right, false,dp);
		else rv = 0;
		if (min > rv + lv)
			min = rv + lv;
		if (ptr->left != NULL)
			lv = minCamera(up, ptr->left,false,dp);
		else lv = 0;
		if (ptr->right != NULL)
			rv = minCamera(up, ptr->right,false,dp);
		else rv = 0;
		if (min > rv + lv+1)
			min = rv + lv+1;
		dp[ptr][up][must] = min;
		return min;
	}
	else
	{
		int lm = maxm;
		int rm = maxm;
		int min = maxm;
		int lv = 0;
		int rv = 0;
		if (must)
		{
			if (ptr->left != NULL)
				lv = minCamera(true, ptr->left, false,dp);
			else lv = 0;
			if (ptr->right != NULL)
				rv = minCamera(true, ptr->right, false,dp);
			else rv = 0;
			if (min > rv + lv + 1)
				min = rv + lv + 1;
		}
		else
		{
			if (ptr->left != NULL)
				lv = minCamera(true, ptr->left, false,dp);
			else lv = 0;
			if (ptr->right != NULL)
				rv = minCamera(true, ptr->right, false,dp);
			else rv = 0;
			if (min > rv + lv + 1)
				min = rv + lv + 1;
			if (ptr->left == NULL && ptr->right == NULL)
				min = 1;
			if (ptr->left != NULL && ptr->right == NULL)
			{
				rv = 0;
				lv = minCamera(false, ptr->left, true,dp);
				if (rv + lv < min)
					min = rv + lv;
			}
			if (ptr->left == NULL && ptr->right != NULL)
			{
				lv = 0;
				rv = minCamera(false, ptr->right, true,dp);
				if (rv + lv < min)
					min = rv + lv;
			}
			if (ptr->left != NULL && ptr->right != NULL)
			{
				int lv1 = minCamera(false, ptr->left, true,dp);
				int rv1 = minCamera(false, ptr->right, true,dp);
				int lv2 = minCamera(false, ptr->left, false,dp);
				int rv2 = minCamera(false, ptr->right, false,dp);
				if (rv1 + lv1 < min)
					min = rv1 + lv1;
				if (lv1 + rv2 < min)
					min = lv1 + rv2;
				if (rv1 + lv2 < min)
					min = rv1 + lv2;
			}
		}
		dp[ptr][up][must] = min;
		return min;
	}
}
    int minCameraCover(TreeNode* root) {
    if(root==NULL)return 0;
    map<TreeNode*, map<bool, map<bool, int>>>dp;
	int res = minCamera(false, root, false, dp);
	return res;
    }
};
```