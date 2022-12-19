1 递归实现（思路：有根节点先打印根节点，再递归访问根节点的左子树和右子树）

class Solution {
public:
    void helper(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)
        {
            return ;
        }
        result.push_back(root->val);
        helper(root->left,result);
        helper(root->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root,result);
        return result;
    }
};



2 辅助栈递归实现（这里万分感谢HEAVEN_DAVILE）
class Solution {
public:
    void helper(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)
        {
            return ;
        }
        else
        {
            stack<TreeNode*> sta;
            sta.push(root);
            while(!sta.empty())//只要栈不为空
            {
                TreeNode* temp=sta.top();
                result.push_back(temp->val);
                sta.pop();

                if(temp->right!=NULL)
                {
                    sta.push(temp->right);
                }
                if(temp->left!=NULL)
                {
                    sta.push(temp->left);
                }
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root,result);
        return result;
    }
};