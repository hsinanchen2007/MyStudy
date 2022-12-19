栈和递归的解法十分类似，就不写了。
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
//此处开始为栈解法
        if(root==NULL) return NULL;
        stack<TreeNode*> s;
        TreeNode* temp=NULL;
        s.push(root);
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->val==val)
                return temp;
            if(temp->left!=NULL&&temp->val>val)
                s.push(temp->left);
            if(temp->right!=NULL&&temp->val<val)
                s.push(temp->right);
        }
        return NULL;
        
        
/*//此处开始是递归解法
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        if(root->val>val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
        return NULL;
*/
    }
};
```
