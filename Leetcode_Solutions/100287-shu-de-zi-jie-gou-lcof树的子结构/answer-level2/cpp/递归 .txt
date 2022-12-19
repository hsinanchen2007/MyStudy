```
class Solution {
public:
	bool update;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        update=false;
        if(!B) return update;
        DFS(A,B);
		return update;
    }
    void DFS(TreeNode* A,TreeNode* B)
    {
        if(!A) return ;
    	if(A->val==B->val)             //如果这个节点与B的根节点一样，则开始检查
    	 update=cmp(A,B);
    	else                           //否则，递归检查A的左子树和右子树
    	{
    		DFS(A->left,B);         
    		DFS(A->right,B);
	}
     }
    bool cmp(TreeNode* A,TreeNode* B)
    {
    	if(!B) return true;            //如果B为空则说明B为A的子树
    	if(!A) return false;           //如果B不为空而A为空则说明不是
    	if(A->val!=B->val) return false;  //如果节点的值不一样也说明不是
    	return cmp(A->left,B->left)&&cmp(A->right,B->right); //对比A和B的左右子树
	}
};
```
