```
class Solution {
public:
    int maxDepth(TreeNode* root)
	 {
        queue<TreeNode*> lay;
		int depth=0;
		TreeNode* p=NULL;
		lay.push(root);
		lay.push(p);
		while (!lay.empty()&&lay.front()!=p)
		{
			TreeNode* parent=lay.front();
			lay.pop();
			if(parent->left!=NULL)
				lay.push(parent->left);
			if(parent->right!=NULL)
				lay.push(parent->right);
			if(lay.front()==p)
			{
				lay.pop();
				depth++;
				lay.push(p);
			}
					
		}
		return depth;	


    }
};
```
