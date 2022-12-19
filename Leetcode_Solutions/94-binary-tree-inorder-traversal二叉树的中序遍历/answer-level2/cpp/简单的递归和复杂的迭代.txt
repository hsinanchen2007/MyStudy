### 解题思路
递归：根着题目设置为递归函数就好了。

迭代：先将左孩子用栈存起来，直到没有左孩子了就将此时的节点输出，接着判断该节点的右孩子是否存在，存在的话则将右孩子压入栈内，在这个过程中还要保存上一个节点，此时则将上一个节点的左孩子设置为NULL，防止死循环。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return v;
        digui(root);
        return v;
    }
private:
    void digui(TreeNode* x) {
        if (x->left != NULL) {
            digui(x->left);
        }
        v.push_back(x->val);
        if (x->right != NULL) {
            digui(x->right);
        }
    }
};

// 迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            TreeNode* pretemp = NULL;
            if (!st.empty()) {
                pretemp = st.top();
            }
            while (temp->left != NULL) {
                st.push(temp);
                pretemp = temp;
                temp = temp->left;
            }
            v.push_back(temp->val);
            if (pretemp != NULL) {
                pretemp->left = NULL;
            }
            if (temp->right != NULL) {
                st.push(temp->right);
            }
        }
        return v;
    }
};
```