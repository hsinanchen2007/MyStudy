### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了88.78% 的用户
内存消耗 :12.3 MB, 在所有 C++ 提交中击败了16.44%的用户

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
	void binaryTreePathsDFS(bool is_1st_entered, TreeNode* root, string path, vector<string>& all_paths){
		if(!root) return;
        if(!is_1st_entered) path += "->";
		if(is_1st_entered) is_1st_entered = false;
		path += to_string(root->val);
		if(!root->left && !root->right){
			//cout << "path = " << path << endl;
			all_paths.push_back(path);
			return;
		}
		binaryTreePathsDFS(is_1st_entered, root->left, path, all_paths);
		binaryTreePathsDFS(is_1st_entered, root->right, path, all_paths);
	}
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> all_paths;
    	string path;
    	bool is_1st_entered = true;
    	binaryTreePathsDFS(is_1st_entered, root, path, all_paths);
    	return all_paths;
    }
};
```