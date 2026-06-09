## 思路
利用树深度优先搜索中先序遍历。

### 代码
```
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

### 另一种写法
```
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);        
        return deserialize(in);
    }
    
private:
    void serialize(TreeNode *root, ostringstream &out) {
        if (root == nullptr) {
            out << "# ";//必须有空格
            return;
        }
        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }
    
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
```

