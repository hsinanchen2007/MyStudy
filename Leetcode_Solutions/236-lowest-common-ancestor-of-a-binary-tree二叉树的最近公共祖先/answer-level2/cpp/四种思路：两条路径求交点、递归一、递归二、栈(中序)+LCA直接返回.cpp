- 思路一：递归，先序遍历，DFS找到两条路径，求公共交点。

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_a, path_b;
        if (!get_path(root, p, path_a) || !get_path(root, q, path_b)) return nullptr;
        int i = 1;
        for (; i < path_a.size() && i < path_b.size(); i++) {
            if (path_a[i] != path_b[i]) return path_a[i-1];
        }
        return path_a[i-1];
    }
    bool get_path(TreeNode* root, TreeNode* a, vector<TreeNode*>& path) {
        if (!root) return false;
        path.emplace_back(root);
        if (root == a) return true;
        if (get_path(root->left, a, path)) return true;
        if (get_path(root->right, a, path)) return true;
        path.pop_back();
        return false;
    }
};
```

- 思路二：递归，对每个节点对应的子树，若该子树不含有p或q，返回nullptr；否则，如果p和q分别位于当前子树根节点两侧，则返回当前节点，否则（p和q在同一侧，或者只有某一侧有p或q）返回来自左边或右边的LCA。

```c++
class Solution {
public:
    //这种思路要求p、q一定要在树里，因为有可能找到一个节点p或q就返回了
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
```

- 思路三：递归，中序遍历，对每个节点，计算其左子树和右子树包含的p或q个数，并返回。第一个包含2个目标值的子树对应的根节点就是最低公共祖先。

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int dummy = contain_counter(root, p, q);
        return ans;
    }
    int contain_counter(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int mid = 0;
        if (root == p || root == q) mid = 1;
        int left = contain_counter(root->left, p, q);
        if (mid + left == 2) {  //可能的话提前剪枝，避免无意义的遍历
            if (!ans) ans = root;
            return 2;
        }
        int right = contain_counter(root->right, p, q);
        if (left + right + mid == 2) if (!ans) ans = root;
        return left + right + mid;
    }
private:
    TreeNode* ans = nullptr;
};
```

- 思路四：使用栈进行中序遍历，用LCA指针避免（找到p和q后）回溯。LCA指针始终指向`当前节点`和`第一个找到的p或q`的最低公共祖先。

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int LCA_stack_index = 0;  //from 1 to stack.size()
        TreeNode *LCA = nullptr, *cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                if (st.size() < LCA_stack_index) {
                    LCA_stack_index = st.size();
                    LCA = cur;
                }
                if (cur == q || cur == p) {
                    if (!LCA) {
                        LCA = cur;
                        LCA_stack_index = st.size();
                    } else return LCA;
                }
                st.pop();
                cur = cur->right;
            }
        }
        return nullptr;
    }
};
```
