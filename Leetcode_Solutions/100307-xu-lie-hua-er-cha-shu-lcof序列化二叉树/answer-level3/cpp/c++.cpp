```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string str;
        dfs(root, str);  
        return str;
    }
    void dfs(TreeNode* root, string& res) {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + " ";
        dfs(root->left, res);
        dfs(root->right, res);
    }
    // Decodes your encoded data to tree.
    TreeNode* dfs1(string data, int& u) {
        if (u == data.size()) return nullptr;
        int k = u;
        while(data[k] != ' ')k++;
        if (data[u] == 'n') {
            u = k+1;
            return nullptr;
        }
        int sum = 0, f = 0;
        if (data[u] == '-'){
            u++;
            f = 1;
        }
        for (int i = u; i < k; i ++) {
            sum = sum*10 + data[i] - '0';
        }
        u = k + 1;
        if (f) {
            sum *= -1;
        }
        auto root = new TreeNode(sum);
        root->left = dfs1(data, u);
        root->right = dfs1(data, u);
        return root;
    }
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs1(data, u);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```