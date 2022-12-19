```
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode *t= new TreeNode(0);
		if (preorder.empty()) {
			return NULL;
		}
		mk_tree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), t);
		return t;
	}
	int mk_tree(vector<int>::iterator pre1, vector<int>::iterator pre2, vector<int>::iterator in1, vector<int>::iterator in2, TreeNode *cur) {
		int tmp = *pre1;
		cur->val = tmp;
		if ((pre1+1)!=pre2) {
			vector<int>::iterator new_in2 = in1, new_pre1 = pre1 + 1;
			while ((*new_in2) != tmp) {
				++new_in2;
			}
			vector<int>::iterator new_pre2 = new_pre1 + (new_in2 - in1), new_in1 = in1;
			if (new_in2!=in1) {
				cur->left = new TreeNode(0);
				mk_tree(new_pre1, new_pre2, new_in1, new_in2, cur->left);
			}
			if ((new_in2+1)!= in2) {
				cur->right = new TreeNode(0);
				mk_tree(new_pre2++, pre2, new_in2+1, in2, cur->right);
			}
		}
		return 1;
	}
};
```
