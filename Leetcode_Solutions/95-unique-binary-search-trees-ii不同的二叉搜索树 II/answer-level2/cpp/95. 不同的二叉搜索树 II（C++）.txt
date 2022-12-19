# 95. 不同的二叉搜索树 II

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
public:
	vector<TreeNode*> recurtion(int begin,int end){
		vector<TreeNode*> rst;
		if( begin > end ) {
			rst.push_back(NULL);
			return rst;
		}
		
		for( int i = begin; i <= end; ++i ) {
			vector<TreeNode*> left_tree  = recurtion(begin,i-1);
			vector<TreeNode*> right_tree = recurtion(i+1,end);
			
			for(TreeNode* left : left_tree) {
				for(TreeNode* right : right_tree) {
					TreeNode *temp = new TreeNode(i);
					temp->left  = left;
					temp->right = right;
					rst.push_back(temp);
				}
			}
		}
		return rst;
	}
	
    vector<TreeNode*> generateTrees(int n) {
        if( n <= 0) {
			vector<TreeNode*> rst;
			return rst;
		}
		
		return recurtion(1,n);
    }
};
```
