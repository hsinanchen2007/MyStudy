### 解题思路
递归法、迭代法

### 代码

```cpp
class Solution {
public:

    //1、递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder_traversal(root, v);
        return v;
    }

    void preorder_traversal(TreeNode* root, vector<int>& v) {
        if(root == nullptr)
            return;
        
        v.push_back(root->val);
        preorder_traversal(root->left, v);
        preorder_traversal(root->right, v);
    }


    //2、使用栈 出栈时打印
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        if(!root)
            return v;
       
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();

            v.push_back(node->val);
            
            //先右
            if(node->right)
                s.push(node->right);

            //后左
            if(node->left)
                s.push(node->left);
        }
        return v;
    }


    //3、使用栈 入栈时打印 （若改为出栈时打印 就是中序遍历）
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> v;

        if(!root)
            return v;
       
        stack<TreeNode*> s;
        
        TreeNode* cur = root;
        
        while(!s.empty() || cur)
        {
            if(cur) //cur非空，入栈，向左
            {
                s.push(cur); 

                v.push_back(cur->val);

                cur = cur->left;
            }
            else //cur空，出栈，向右
            {
                cur = s.top(); //栈肯定是非空的
                s.pop();
                
                cur = cur->right;
            }
        }
        
        return v;
    }


    //4、莫里斯遍历
};