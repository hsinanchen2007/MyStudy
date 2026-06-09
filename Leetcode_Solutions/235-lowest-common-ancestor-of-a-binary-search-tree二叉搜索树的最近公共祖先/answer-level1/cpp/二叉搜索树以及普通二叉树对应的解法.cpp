**对于二叉搜索树，使用其性质，同时进行节点查找，分岔点即为最近公共祖先**
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p_val = p->val;
        int q_val = q->val;
        
        // 同时进行搜索，找到第一个分岔点，即为最近公共祖先
        // 若先碰到某个节点，则直接 return 此节点
        TreeNode* cur = root;
        while (cur != p || cur != q) {
            if (p_val < cur->val && cur->val > q_val) {
                cur = cur->left;
            } else if (cur->val < p_val && q_val > cur->val) {
                cur = cur->right;
            } else {    // 分岔点
                return cur;
            }
        }
        
        if (cur = p) {
            return p;
        } else {
            return q;
        }
        
    }
};
```
**对于普通二叉树，则通过先序遍历先找到其中一个节点，此时公共祖先就在栈中（栈中保存了根节点到当前节点的路径）**
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 在先序遍历的过程中，我们会先遇到某一个节点，此时栈中的节点就是从根节点到本节点的路径
        // 此时，最近公共祖先就是路径上的某个节点
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                if (cur == p || cur == q) {
                    // 此时栈内就是从根节点到 cur 的路径，最近公共祖先也在栈中
                    st.push(cur);   // 公共祖先可能是 p 或 q 自身
                    while (!st.empty()) {
                        auto* pathNode = st.top(); st.pop(); // 按照路径的逆序，对其中的每个节点对应的子树进行查找
                        TreeNode* ret;
                        if (cur == p) ret = search(pathNode, q);
                        else ret = search(pathNode, p);
                        if (ret != nullptr) return pathNode;
                    }
                }
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                cur = cur->right;
            }
        }
        
        // 不会执行到这
        return nullptr;
    }
    
    TreeNode* search(TreeNode* root, TreeNode* target) {
        if (root == nullptr) return nullptr;
        
        if (root == target) return root;
        auto* l = search(root->left, target);
        auto* r = search(root->right, target);
        if (l) return l;
        if (r) return r;
        return nullptr;
    }
};
```
