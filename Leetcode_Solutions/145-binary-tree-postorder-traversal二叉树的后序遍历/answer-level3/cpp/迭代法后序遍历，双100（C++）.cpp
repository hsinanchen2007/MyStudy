![image.png](https://pic.leetcode-cn.com/4f88a4c5cbba9f1bbbb03c8079aad2d0c5b6bef335e26d830a5aa399e91c7a5b-image.png)

首先需要写一个函数，用以确定遍历的第一个节点，并将沿途的节点加入栈中：

```
void probing(TreeNode* root, stack<TreeNode*> &nodes)
    {
        while (root)
        {
            if (root->left)
            {
                if (root->right) nodes.push(root->right);
                nodes.push(root->left);
                root = root->left;
            }
            else if (root->right)
            {
                nodes.push(root->right);
                root = root->right;
            }
            else
            {
                break;
            }
        }
    }
```
在处理栈中元素的时候，有一种情况需要注意：
当栈顶元素是当前元素的右兄弟时（即当前元素不是栈顶元素的孩子），则需要遍历右兄弟所在的子树！

```
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> solver;
        stack<TreeNode*> nodes;

        if (root == NULL)
        {
            return{};
        }

        nodes.push(root);
        probing(root, nodes);
        while (nodes.size() > 1)
        {
            TreeNode *p = nodes.top();
            nodes.pop();
            solver.push_back(p->val);
            if (nodes.top()->right != p && nodes.top()->left != p) // 非常关键！
            {
                probing(nodes.top(), nodes);
            }
        }
        solver.push_back(nodes.top()->val);

        return solver;
    }
```


总体代码如下：
```
class Solution {
    void probing(TreeNode* root, stack<TreeNode*> &nodes)
    {
        while (root)
        {
            if (root->left)
            {
                if (root->right) nodes.push(root->right);
                nodes.push(root->left);
                root = root->left;
            }
            else if (root->right)
            {
                nodes.push(root->right);
                root = root->right;
            }
            else
            {
                break;
            }
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> solver;
        stack<TreeNode*> nodes;

        if (root == NULL)
        {
            return{};
        }

        nodes.push(root);
        probing(root, nodes);
        while (nodes.size() > 1)
        {
            TreeNode *p = nodes.top();
            nodes.pop();
            solver.push_back(p->val);
            if (nodes.top()->right != p && nodes.top()->left != p)
            {
                probing(nodes.top(), nodes);
            }
        }
        solver.push_back(nodes.top()->val);

        return solver;
    }
};
```

最后，可以将代码改的更加紧凑：
```
class Solution {
    void probing(TreeNode* root, stack<TreeNode*> &nodes)
    {
        while (root)
        {
            if (root->left)
            {
                if (root->right) nodes.push(root->right);
                nodes.push(root->left);
                root = root->left;
            }
            else if (root->right)
            {
                nodes.push(root->right);
                root = root->right;
            }
            else
            {
                break;
            }
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> solver;
        stack<TreeNode*> nodes;

        if (root == NULL)
        {
            return{};
        }

        nodes.push(root);
        while (nodes.size() > 0)
        {
            if (nodes.top()->right != root && nodes.top()->left != root)
            {
                probing(nodes.top(), nodes);
            }
            root = nodes.top();
            nodes.pop();
            solver.push_back(root->val);
        }

        return solver;
    }
};
```

