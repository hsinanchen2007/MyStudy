### 代码思路
用数组vector和队列queue解决
队列牢牢地掌控了层次遍历的顺序
vector<int>为了vector<vector<int>>服务
本题和102题（单纯的层序遍历）不一样的地方在于，偶数层逆置，所以在把row推进ret之前，把row逆置，调用reverse算法

```
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<int> row;
        vector<vector<int>> ret;
        queue<TreeNode *> que;
        if (root == NULL)
            return ret;
        TreeNode *temp;
        que.push(root);
        int line=0;
        while (!que.empty())
        {
            int size = que.size();
            while (size--) //把同一层的放到一起
            {
                temp = que.front(); //先留个号码，好找
                que.pop();          //再出队
                row.push_back(temp->val);
                if (temp->left != NULL)
                {
                    que.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    que.push(temp->right);
                }
            }
            if(line%2)
            {
                reverse(row.begin(),row.end());
            }
            ret.push_back(row);
            ++line;
            row.clear();
        }
        return ret;
    }
```
