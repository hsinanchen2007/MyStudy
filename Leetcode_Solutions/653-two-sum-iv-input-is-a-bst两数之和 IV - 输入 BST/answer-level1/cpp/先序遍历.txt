![3.PNG](https://pic.leetcode-cn.com/4c7d568c013c2da53fcaca377e51817367cae81bc6160f7de1e35d236eaaaf67-3.PNG)

```
class Solution {
public:
	TreeNode* findV(TreeNode *r,int x){//查找x节点 
		if(r==NULL)
			return NULL;
		if(r->val==x)
			return r;
		else if(r->val>x)
			return findV(r->left,x);
		else
			return findV(r->right,x);
	}
    bool findTarget(TreeNode* root, int k) {
        return f(root,root,k);
    }
    bool f(TreeNode* v,TreeNode* root,int k){
	//v是遍历的节点，root是查找完整的树
    	if(v==NULL)
    		return 0;
    	TreeNode* t=findV(root,k-v->val);
		if(t!=NULL&&t!=v)
			return 1;
		return f(v->left,root,k)||f(v->right,root,k);
	}
};
```

