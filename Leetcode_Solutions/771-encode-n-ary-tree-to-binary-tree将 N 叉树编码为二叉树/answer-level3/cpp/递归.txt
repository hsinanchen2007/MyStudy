### 解题思路
递归

### 代码

```cpp
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        function<TreeNode*(Node*, Node*, int)> dfs = [&dfs](Node* node, Node* parent, int i)->TreeNode*{
            TreeNode* cur = nullptr;
            if (node) {
                cur = new TreeNode(node->val);
                if (node->children.size()) {
                    cur->left = dfs(node->children[0], node, 1);
                }
            }
            if (parent && i < parent->children.size()) {
                if (cur) {
                    cur->right = dfs(parent->children[i], parent, i + 1);
                } else {
                    cur = dfs(parent->children[i], parent, i + 1);
                }
            }
            return cur;
        };
        return dfs(root, nullptr, 0);
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        function<Node*(TreeNode*, Node*)> dfs = [&dfs](TreeNode* node, Node* parent)->Node*{
            Node* cur = nullptr;
            if (node) {
                cur = new Node(node->val);
                dfs(node->left, cur);
                if (parent) {
                    parent->children.push_back(cur);
                    dfs(node->right, parent);
                }
            }
            return cur;
        };
        return dfs(root, nullptr);
    }
};

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```