官方题解实在有点取巧，贴一下我自己的后续遍历 C++ 代码，跟官方的前序和中序遍历的迭代风格一致：
```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // 用一个bool型变量来区分某个节点两次出栈的情况，一次是在其左子树遍历完（false），另一次在其右子树遍历完（true）
        stack<pair<TreeNode*, bool>> st;
        TreeNode* cur = root;
        while (!st.empty() || cur != NULL) {
            while (cur != NULL) {
                st.push({cur, false});
                cur = cur->left;
            }
            auto top = st.top();
            st.pop();
            // 一个节点出栈时，说明它的左子树已经遍历完
            if (top.first->right == NULL ||  // 没有右子树，该打印它了
                top.second) {   // top.second == true 说明它已经是第二次出栈，直接打印
                ans.push_back(top.first->val);
                cur = NULL; // 下一个要处理的是其父节点（下次循环从栈顶弹出）
            } else {
                // 有右子树，且第一次出栈，需要再把它压回去，并将标记置为true，下一次出栈就是第二次出栈了
                st.push({top.first, true});
                cur = top.first->right; // 下一个要处理的是它的右子节点
            }
        }
        return ans;
    }
};
```

顺便贴一下迭代进行前序和中序遍历的代码，与后序遍历写法都是一致的：
```cpp
class Solution {
public:
    // 前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur != NULL) {
            while (cur != NULL) {
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            auto top = st.top();
            st.pop();
            cur = top->right;
        }
        return ans;
    }
};
```
```cpp
class Solution {
public:
    // 中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root; 
        while (cur != NULL || !st.empty()) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            auto top = st.top();
            st.pop();
            ans.push_back(top->val);
            cur = top->right;
        } 
        return ans;
    }
};
```