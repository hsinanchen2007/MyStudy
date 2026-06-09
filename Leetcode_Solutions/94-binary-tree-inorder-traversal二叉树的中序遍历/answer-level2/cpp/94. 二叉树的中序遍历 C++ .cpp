### 解题思路
递归、迭代

### 代码

```cpp

class Solution {
public:

    //1、递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder_traversal(root, v);
        return v;
    }

    void inorder_traversal(TreeNode* root, vector<int>& v) {
        if(root == nullptr)
            return;
        
        inorder_traversal(root->left, v);
        v.push_back(root->val);
        inorder_traversal(root->right, v);
    }


    //2、使用栈 出栈时打印 （注意：这个函数与先序遍历入栈时打印 仅打印的时机不同）
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;

        if (root == nullptr)
            return v;

        stack<TreeNode*> s;

        TreeNode* cur = root;

        while (!s.empty() || cur) // 1、初始时 栈空 cur非空  2、中间过程有栈空，cur非空 和 栈非空，cur空 两种情况  3、最后两个都为空，退出循环
        {
            if (cur) //非空 入栈 向左
            {
                s.push(cur);
                cur = cur->left;
            }
            else //空 出栈 向右
            {
                cur = s.top(); //栈肯定是非空的
                s.pop();

                v.push_back(cur->val);

                cur = cur->right;
            }
        }

        return v;
    }
};
```