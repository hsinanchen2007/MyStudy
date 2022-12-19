### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool dfs(TreeNode* root,vector<int> &res) {
		if (root==NULL) {
			return true;
		}
		if (res.size()==0||res.back()!=root->val) {
			res.push_back(root->val);
		}
		if (res.size()>=2) {
			return false;
		}
		bool b1=dfs(root->left, res);
		if (b1==false) {
			return false;
		}
		bool b2=dfs(root->right,res);
		if (b2 == false) {
			return false;
		}
        return true;
	}
	bool isUnivalTree(TreeNode* root) {
		vector<int> res;
		return dfs(root,res);
	}
};
```