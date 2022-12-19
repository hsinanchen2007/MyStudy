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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return NULL;
    	TreeNode* bst = new TreeNode(nums[nums.size()/2]);

    	vector<int> v_l_left(nums.begin(), nums.begin() + nums.size()/2);
    	vector<int> v_l_right(nums.begin() + nums.size()/2+1, nums.end());
    	if(v_l_left.size()){
    		bst->left = sortedArrayToBST(v_l_left);
    	}
    	if(v_l_right.size()){
    		bst->right = sortedArrayToBST(v_l_right);
    	}

    	return bst;
    }
};
```