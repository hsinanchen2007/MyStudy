直接看注释吧
```
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);       // 首先根节点入队
        while (!q.empty())  // 首先按照普通的层序遍历的流程来
        {
            TreeNode* p = q.front();
            q.pop();
            if (!p->right) {    // 但是要注意终止遍历的条件
                if (p->left) q.push(p->left);
                break;          // 只要右为空，终止遍历
            }
            if (!p->left) return false;     // 左空右不空，直接false
            q.push(p->left);    // 通过上面的条件，保证了两个子节点都是非空的
            q.push(p->right);      
        }
        while (!q.empty())  // 此时队列内剩下的节点都必须绝后，否则false
        {
            TreeNode* p = q.front();
            q.pop();
            if (p->left || p->right) return false;
        }
        return true;
    }
```
