### 解题思路
递归
迭代（双栈、单栈）

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    //1、递归
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> v;

        postorder(root, v);

        return v;
    }

    void postorder(TreeNode* root, vector<int>& v) {
        if(root == nullptr)
            return;
        
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }

    //2、迭代  使用双栈
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;

        if (root == nullptr)
            return v;

        stack<TreeNode*> s1;
        s1.push(root);

        stack<TreeNode*> s2;

        while (!s1.empty())
        {
            TreeNode* node = s1.top();
            s1.pop();

            s2.push(node); //入辅助栈

            //子节点从左到右入栈
            if (node->left)
                s1.push(node->left);

            if (node->right)
                s1.push(node->right);
        }

        while (!s2.empty())
        {
            TreeNode* node = s2.top();
            s2.pop();
            v.push_back(node->val);
        }

        return v;
    }


    //3、迭代  使用一个栈  同方法2，但是不借助辅助栈，直接对数组逆序
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;
        if (root == nullptr)
            return v;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            v.push_back(node->val);

            //子节点从左到右入栈
            if(node->left)
                s.push(node->left);

            if(node->right)
                s.push(node->right);
        }

        reverse(v.begin(), v.end());

        return v;
    }


    //4、迭代  使用一个栈
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;
        if (root == nullptr)
            return v;

        stack<TreeNode*> s;
        s.push(root);

        TreeNode* cur = nullptr; //栈顶节点
        TreeNode* last = root; //最后一个打印的节点  不能初始化为nullptr  如果cur->left存在，但cur->right为空，last为空，则无法将左子树入栈了

        while (!s.empty())
        {
            cur = s.top(); //栈顶

            if (cur->left && last != cur->left && last != cur->right)
            {
                s.push(cur->left);
            }
            else if (cur->right && last != cur->right)
            {
                s.push(cur->right);
            }
            else
            {
                v.push_back(cur->val);
                last = cur;
                s.pop();
            }
        }

        return v;
    }

    
};
```