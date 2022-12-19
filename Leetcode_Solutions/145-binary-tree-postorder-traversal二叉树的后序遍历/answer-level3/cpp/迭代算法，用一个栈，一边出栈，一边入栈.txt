    class Solution {
    private:
        vector<int> val;
        stack<TreeNode*> stk;
        //memo用来记录某节点的右子树是否已经入栈并输出了
        //memo为0表示没有入栈，为1表明已入栈，此时应直接输出该节点的val
        unordered_map<TreeNode*,int> memo;
        //入栈函数
        void pushin(TreeNode* root)
        {
            if(root == NULL)
                return;
            TreeNode* temp = root;
            while(temp->left != NULL || temp->right != NULL)
            {
                if(temp->left != NULL)//优先入栈左子树
                {
                    stk.push(temp);
                    temp = temp->left;
                }
                else//左子树不存在时，入栈右子树，注意此时的memo
                {
                    stk.push(temp);
                    memo[temp] = 1;
                    temp = temp->right;
                }  
            }
            stk.push(temp);//叶子节点也入栈
        }
        //出栈，边出栈边入栈，当某节点的右子树没有入过栈时，调用pushin函数入栈
        void popout(TreeNode* root)
        {
            TreeNode* temp;
            pushin(root);
            while(!stk.empty())
            {
                temp = stk.top();
                if(temp->left == NULL && temp->right == NULL)
                {
                    val.push_back(temp->val);
                    stk.pop();
                }
                else if(temp->right != NULL && memo[temp] == 0)
                {
                    pushin(temp->right);
                    memo[temp] = 1;
                }
                else
                {
                    val.push_back(temp->val);
                    stk.pop();
                }
            }
        }
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            val.clear();
            if(root == NULL)
                return val;
            
            if(root->left != NULL)
                popout(root->left);
            if(root->right != NULL)
                popout(root->right);
            val.push_back(root->val);
            
            return val;
        }
    };