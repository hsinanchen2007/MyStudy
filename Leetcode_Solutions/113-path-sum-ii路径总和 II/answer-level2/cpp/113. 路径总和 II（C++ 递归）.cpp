# 113. 路径总和 II
利用递归的方式深度遍历二叉树，对于所有符合的结果保存至rst结果二维数组中。
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
	vector<vector<int>> rst;
	vector<int> rst_item;
public:
	void pathSumRecursion(TreeNode* &temp,int sum){
		if( temp == NULL )
			return;
			
		if(  sum-temp->val==0 && temp->left==NULL && temp->right==NULL ){
			rst_item.push_back(temp->val);
			rst.push_back(rst_item);
			rst_item.pop_back();
			return;
		}
		
		rst_item.push_back(temp->val);
		pathSumRecursion(temp->left,sum-temp->val);
		pathSumRecursion(temp->right,sum-temp->val);
		rst_item.pop_back();		
	}
	
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if( root != NULL )
			pathSumRecursion(root,sum);
		return rst;
    }
};
```
