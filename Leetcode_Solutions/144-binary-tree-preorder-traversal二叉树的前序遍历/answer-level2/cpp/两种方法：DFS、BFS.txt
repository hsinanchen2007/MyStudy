递归：
```
class Solution
{
public:
    void Path(TreeNode *node, vector<int> &result)
    {
        if (!node)
        {
            return;
        }
        result.push_back(node->val);
        Path(node->left, result);
        Path(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        Path(root, result);
        return result;
    }
};
```

基于栈的BFS：
```
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> result;

        stack<TreeNode *> st;

        while (root || !st.empty())
        {
            while (root)
            {
                result.push_back(root->val);
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            root = root->right;
        }

        return result;
    }
};
```


