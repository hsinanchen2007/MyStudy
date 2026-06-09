## 思路一：递归
使用特殊符号（“#”）表示空树。

### 代码

```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {        
        if (!root) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return dfs(is);
    }

    TreeNode* dfs(istringstream &is) {
        string s;
        is >> s;
        if (s == "#") return nullptr;
        TreeNode *node = new TreeNode(stoi(s));
        node->left = dfs(is);
        node->right = dfs(is);
        return node;
    }
};
```