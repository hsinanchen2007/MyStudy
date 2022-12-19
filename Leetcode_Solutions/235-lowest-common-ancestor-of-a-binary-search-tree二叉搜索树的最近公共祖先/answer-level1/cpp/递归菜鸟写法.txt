执行用时 :44 ms, 在所有 C++ 提交中击败了50.38%的用户
内存消耗 :26.1 MB, 在所有 C++ 提交中击败了5.20%的用户
### 代码

```cpp
class Solution {
private:
	TreeNode* res;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		int min = p->val < q->val ? p->val : q->val;
		int max = p->val > q->val ? p->val : q->val;
		if (min <= root->val && max >= root->val)
		{
			res = root;
			return root;
	    }
		else
			if (min > root->val)
				lowestCommonAncestor(root->right,p,q);
			else
				lowestCommonAncestor(root->left, p, q);
        return res;
	}
 };
```