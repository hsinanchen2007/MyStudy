### 解题思路

中序遍历压栈，弹栈过程中更新累加和

### 代码

```cpp
class Solution {
private:
    stack<TreeNode *> st;
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        InOrder(root);
        while(!st.empty()) {
            TreeNode *p = st.top();
            int temp = p->val;
            p->val += sum;
            sum += temp;
            st.pop();
        }
        return root;
    }
    
    void InOrder(TreeNode *root) {
        if(!root)
            return;
        InOrder(root->left);
        st.push(root);
        InOrder(root->right);
    }
};
```