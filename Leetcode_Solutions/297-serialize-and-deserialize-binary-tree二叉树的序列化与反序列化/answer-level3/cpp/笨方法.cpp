没有使用'#'分隔，就是基础的dfs搜索，加上几个字符串转int和int转字符串的函数，效率比较低，时间就超过50%左右，不过方法很基础。
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
using pti = pair<TreeNode *, int>;
class Codec {
private:
    string its(int a) {
        string res; res.clear();
        if (a < 0) res += '-', a = -a;
        while (a) {
            char t = a % 10 + '0';
            res = t + res;
            a /= 10;
        }
        return res;
    }
    
    string dfs(TreeNode *p) {
        if (!p) return "N";
        string res; res.clear();
        res += its(p->val);
        res += '{';
        res += dfs(p->left);
        res += ',';
        res += dfs(p->right);
        res += '}';
        return res;
    }
    
    int getVal(const string &s, int &i) {
        int val = 0;
        int flag = 1;
        for (; s[i] == '-' || (s[i] >= '0' && s[i] <= '9'); ++i) {
            if (s[i] == '-') { flag = -1; continue; }
            val = val * 10 + s[i] - '0';
        }
        return val * flag;
    }
    
    pti dfs(const string &d, int i) {
        if (d[i] == 'N') return {nullptr, i + 1};
        TreeNode *root = new TreeNode(getVal(d, i));
        pti a = dfs(d, i + 1);
        root->left = a.first;
        pti b = dfs(d, a.second + 1);
        root->right = b.first;
        return {root, b.second + 1};
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // cout << dfs(root);
        return dfs(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs(data, 0).first;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
