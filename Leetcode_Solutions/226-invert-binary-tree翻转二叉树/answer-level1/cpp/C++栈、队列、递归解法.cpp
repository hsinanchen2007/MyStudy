给出C++语言栈、队列、递归的解法
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
//这是栈的解法
        if(root==NULL) return NULL;//判断root是不是空，空直接返回；
        stack<TreeNode *> s;//创建一个TreeNode*类型的栈；
        s.push(root);
        while(!s.empty())//如果栈不空就一直执行；
        {
            TreeNode* current=s.top();//创建一个变量储存栈顶元素；
            TreeNode* temp=current->right;
            current->right=current->left;
            current->left=temp;
            s.pop();//将栈顶元素出栈；
            if(current->left!=NULL) s.push(current->left);
            if(current->right!=NULL) s.push(current->right);
        }
        return root;
        
        
        
/*这里开始是队列方法，和用栈的方法基本一致
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current=q.front();
            TreeNode* temp=NULL;
            temp=current->left;
            current->left=current->right;
            current->right=temp;
            q.pop();
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
        }
        return root;
*/      
            
        
/*这里开始是用递归的方法
        if(root==NULL)return NULL;
        TreeNode* right=invertTree(root->right);//创建一个right变量储存右子树翻转的结果；
        TreeNode* left=invertTree(root->left);//创建一个left变量储存左子树的翻转结果；
        root->left=right;//将翻转好的右子树赋值给根节点的左子树
        root->right=left;//将翻转好的左子树赋值给根节点的右子树
        return root;
*/      
    }
};
```