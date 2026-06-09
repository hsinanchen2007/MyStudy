中序遍历，栈实现
```
class BSTIterator {
private:
    TreeNode* curr;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
        while (!s.empty())
            s.pop();
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
        } else {
            return -1;
        }
        int res = curr->val;
        curr = curr->right;
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || curr != NULL;
    }
};
```
