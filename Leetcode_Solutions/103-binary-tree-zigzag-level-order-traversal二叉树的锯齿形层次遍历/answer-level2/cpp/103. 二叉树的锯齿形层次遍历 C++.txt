### 解题思路
1、层序遍历 + 逆序
2、双端队列

### 代码

```cpp

class Solution {
public:

    //1、层序遍历（第2、4、6....层逆序）
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (!root)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* last = root;
        TreeNode* nlast = nullptr;

        vector<int> v;

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            v.push_back(node->val);

            if (node->left)
            {
                q.push(node->left);
                nlast = node->left;
            }

            if (node->right)
            {
                q.push(node->right);
                nlast = node->right;
            }

            if (node == last)
            {
                last = nlast;
                if (res.size() % 2 == 0)
                {
                    res.push_back(v);
                }
                else
                {
                    reverse(v.begin(), v.end());
                    res.push_back(v);
                }
                v.clear();
            }
        }
        return res;
    }

    //2、使用一个双端队列 (deque或list均可)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (!root)
        {
            return res;
        }

        // deque<TreeNode*> dq;
        list<TreeNode*> dq;
        dq.push_front(root);

        bool lr = true;

        TreeNode* node = nullptr;
        TreeNode* last = root;
        TreeNode* nlast = nullptr;

        vector<int> v;

        while (!dq.empty())
        {
            if (lr)
            {
                node = dq.front();
                dq.pop_front();

                if (node->left)
                {
                    dq.push_back(node->left);
                    if (!nlast)
                    {
                        nlast = node->left;
                    }
                }
                if (node->right)
                {
                    dq.push_back(node->right);
                    if (!nlast)
                    {
                        nlast = node->right;
                    }
                }
            }
            else
            {
                node = dq.back();
                dq.pop_back();

                if (node->right)
                {
                    dq.push_front(node->right);
                    if (!nlast)
                    {
                        nlast = node->right;
                    }
                }
                if (node->left)
                {
                    dq.push_front(node->left);
                    if (!nlast)
                    {
                        nlast = node->left;
                    }
                }
            }

            v.push_back(node->val);

            if (node == last)
            {
                lr = !lr;
                last = nlast;
                nlast = nullptr; //
                res.push_back(v);
                v.clear();
            }
        }
        return res;
    }
};
```