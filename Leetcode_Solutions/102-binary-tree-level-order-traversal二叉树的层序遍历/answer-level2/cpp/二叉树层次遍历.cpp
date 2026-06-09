思路主要是通过栈保存当前层的结点用于下一层遍历,通过广度优先排序遍历整个二叉树.

代码如下:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> record;
        vector<int> re;
        TreeNode* temp;
        stack<TreeNode*> st;
        stack<TreeNode*> st1;
        st.push(root);
        if(root==nullptr)
        {
            return record;
        }
        while(!st.empty())
        {
            vector <int>().swap(re);//清空vector
            while(!st.empty())
            {
                temp = st.top();
                if(temp!=nullptr)
                    re.push_back(temp->val);
                else
                {
                    re.push_back(0);
                }
                if(temp->left)
                {
                    st1.push(temp->left);
                }
                if(temp->right)
                {
                    st1.push(temp->right);
                }
                st.pop();
            }
            record.push_back(re);
            while(!st1.empty())
            {
                temp = st1.top();
                st.push(temp);
                st1.pop();  //交换栈内容
            }
            
        }
        return record;
    }
};
