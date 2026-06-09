### 解题思路
执行用时 :20 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :17.5 MB, 在所有 C++ 提交中击败了100.00%的用户

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
	int MaxDepth(TreeNode* root){
		return (!root)?0:max(MaxDepth(root->left), MaxDepth(root->right))+1;
	}
    bool isBalanced(TreeNode* root) {
    	if(!root) return true;//上传结果判断：空树判定为平衡
    	int depth_left = MaxDepth(root->left);
    	int depth_right = MaxDepth(root->right);
    	int dist = abs(depth_left - depth_right);
    	//for debug
//    	cout << "dist = " << dist << endl;
    	if(dist > 1) return false;

    	//return isBalanced(root->left);
    	//return isBalanced(root->right);
        return isBalanced(root->left) & isBalanced(root->right);

    	return true;
    }
};
```