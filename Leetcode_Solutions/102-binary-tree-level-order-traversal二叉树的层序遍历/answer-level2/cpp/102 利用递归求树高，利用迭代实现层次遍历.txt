
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        int h = heightOfTree(root);
        TreeNode *current;
        queue<TreeNode*> unprocessedList;
        unprocessedList.push(root);
        res.resize(h);
        int flag = 0;
        while (!unprocessedList.empty()) {
            int len = unprocessedList.size();
            for (int i=0; i<len; i++) {
                current = unprocessedList.front();
                unprocessedList.pop();
                res[flag].push_back(current->val);
                if (current->left)
                    unprocessedList.push(current->left);
                if (current->right)
                    unprocessedList.push(current->right);
            }
            flag++;
        }
        return res;
    }

private:
    int heightOfTree(TreeNode* t) {
        if (t == nullptr)
            return 0;
        else {
            return max(heightOfTree(t->left), heightOfTree(t->right)) + 1;
        }
    }
};
```