### 解题思路
此处撰写解题思路

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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> vals;
    	if(!root) return vals;
    	list<TreeNode*> nodes;
    	nodes.push_back(root);

    	while(nodes.size()){
    		vector<int> this_level_vals;
    		size_t level_size = nodes.size();//这里是关键，
    		//尽管下面for()中的nodes大小一直在变，但是level_size固定之后每一层的输出就有了保障
    		for(size_t i=0; i<level_size; ++i){
    			root = nodes.front();
    			cout << root->val << " "; //just for monitor
    			this_level_vals.push_back(root->val);
    			nodes.pop_front();
    			if(root->left){
    				nodes.push_back(root->left);
    			}
    			if(root->right){
    				nodes.push_back(root->right);
    			}
    		}
    		vals.push_back(this_level_vals);
    	}

    	return vals;
    }
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> vec = levelOrder(root);
		std::reverse(vec.begin(),vec.end());
		return vec;
	}
};
```