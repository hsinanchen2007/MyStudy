## 思路
在构造函数中遍历树，将遍历节点值依次存入一个队列。
### 代码
```c++
class BSTIterator {
    stack<TreeNode*> st;
    queue<int> que;
public:
    BSTIterator(TreeNode* root) {        
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            TreeNode *p = st.top();
            st.pop();
            que.push(p->val);
            root = p->right;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int val = que.front();
        que.pop();
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !que.empty();
    }
};
```
