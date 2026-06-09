对比发现层次遍历实现效率明显更高。。

### 1. 层次遍历实现

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();

            if (node) {
                res += to_string(node->val) + ' ';
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null ";
            }
            q.pop();
        }

        // cout << res;
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> list;
        for (int l = 0, r = 0; l < data.size(); ) {
            r = l;
            while (data[r] != ' ') r ++ ;
            if (data[l] == 'n') {
                l = r + 1;
                list.push_back(NULL);
                continue;
            }
            int val = 0, sign = 1;
            if (l < r && data[l] == '-') sign = -1, l ++ ;
            for (int i = l; i < r; i ++ ) val = val * 10 + data[i] - '0';
            val *= sign;
            l = r + 1;
            auto newNode = new TreeNode(val);
            list.push_back(newNode);
        }
        
        auto newList = list[0];
        auto curNode = newList;
        
        // j表示当前的根节点，遇到null就递进
        // i表示当前的孩子节点，相邻两个构成一个父节点的孩子节点
        for (int i = 1, j = 1; j < list.size() && i < list.size(); j ++ ) {
            if (!curNode) {
                curNode = list[j];
                continue;
            }
            curNode->left = list[i];
            curNode->right = list[i + 1];
            curNode = list[j];
            i += 2;
        }

        return newList;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```

---

### 2. 前序遍历实现


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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
        return res;
    }

    // 前序遍历序列转化为字符串
    void dfs_s(TreeNode* root, string& res) {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode* dfs_d(string data, int& u) {
        if (u == data.size()) return NULL;
        int k = u;
        while (data[k] != ' ') k ++ ;
        if (data[u] == 'n') {
            u = k + 1;
            return NULL;
        }
        int val = 0, sign = 1;
        if (u < k && data[u] == '-') sign = -1, u ++ ;
        for (int i = u; i < k; i ++ ) val = val * 10 + data[i] - '0';
        val *= sign;
        u = k + 1;

        auto root = new TreeNode(val);
        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```