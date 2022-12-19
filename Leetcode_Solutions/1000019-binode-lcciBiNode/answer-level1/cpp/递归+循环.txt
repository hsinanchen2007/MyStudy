- 循环中序遍历
```cpp
class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *prev = NULL, *tp, *head = NULL;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	tp = stk.top();
        	stk.pop();
        	tp->left = NULL;
        	if(prev)
        		prev->right = tp;
    		if(!head)
    			head = tp;
    		prev = tp;
    		root = tp->right;
        }
        return head;
    }
};
```
![在这里插入图片描述](https://pic.leetcode-cn.com/481bf49f86c1cd0e23d899b57799530a615c3cdfd718c89e59c3031ad14a9acf.png)
- 递归解法

```cpp
class Solution {
	TreeNode* prev = NULL;
	TreeNode* head = NULL;
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root)
        	return NULL;
        convertBiNode(root->left);
        if(prev)
        	prev->right = root;
        prev = root;
        root->left = NULL;
        if(!head)
        {
        	head = root;
        	prev = root;
        }
        convertBiNode(root->right);
        return head;
    }
};
```
![在这里插入图片描述](https://pic.leetcode-cn.com/8d23424aeff95d25f2f6e80385444d25d00521155f000099a80a91c7ef0561cf.png)