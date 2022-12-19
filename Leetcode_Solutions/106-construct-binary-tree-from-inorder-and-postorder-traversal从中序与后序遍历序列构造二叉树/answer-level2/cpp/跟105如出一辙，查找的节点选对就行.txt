### 解题思路


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(!inorder.size()) return NULL;

		int root_ind = -1;
		for(size_t i=0; i<inorder.size(); ++i)
		{
			if(inorder[i] == postorder[postorder.size()-1]){
				//for debug
//				cout << "found " << inorder[i] << " root_ind = " << i << endl;
				root_ind = i;
				break;
			}
		}
		if(root_ind == -1) return NULL;
		TreeNode* root = new TreeNode(inorder[root_ind]);

		vector<int> in_right(inorder.begin()+root_ind+1, inorder.end());
		vector<int> post_right(postorder.begin()+root_ind, postorder.end()-1);

		vector<int> in_left(inorder.begin(), inorder.begin()+root_ind);
		vector<int> post_left(postorder.begin(), postorder.begin()+root_ind);
//		//for debug
//		cout << "in_right = ";
//		buildTreeFromInPostHelper(in_right);
//		cout << "post_right = ";
//		buildTreeFromInPostHelper(post_right);
//		cout << endl;
//		cout << "in_left = ";
//		buildTreeFromInPostHelper(in_left);
//		cout << "post_left = ";
//		buildTreeFromInPostHelper(post_left);

		root->right = buildTree(in_right, post_right);
		root->left = buildTree(in_left, post_left);

		return root;
    }
};
```