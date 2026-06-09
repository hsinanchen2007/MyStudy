### 思路
注意：迭代解法中每次循环的末尾令current为右节点，可以让已经读取到的左节点不被重新读取。
### 代码
```迭代 []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> unprocessedList;
        TreeNode *current = root;
        while (current || !unprocessedList.empty()) {
            while (current) {
                unprocessedList.push(current);
                current = current->left;
            }
            current = unprocessedList.top();
            unprocessedList.pop();
            res.push_back(current->val);
            current = current->right;
        }
        return res;
    }
};
```
```递归 []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        visit(root);
        return res;
    }

private:
    vector<int> res;
    void visit(TreeNode* t) {
        if (t) {
            visit (t->left);
            res.push_back(t->val);
            visit(t->right);
        }
    }
};
```
