求左右子树的高度

### 代码

```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	bool ans = true;
    	check(root, ans);
    	return ans;
    }

    int check(TreeNode* root, bool& bal)
    {
    	if(!root || !bal)
    		return 0;
    	int l = check(root->left, bal);
    	int r = check(root->right, bal);
    	if(abs(l-r)>1)
    		bal = false;
    	return max(l,r)+1;
    }
};
```