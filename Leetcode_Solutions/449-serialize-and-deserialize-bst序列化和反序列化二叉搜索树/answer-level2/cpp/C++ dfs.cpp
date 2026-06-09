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
        if(root == NULL) return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return left + right + '(' + to_string(root->val) + ')';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        stack<TreeNode*>S;
        for(int i =0; i< n;i++) {
            if(data[i] == '#') {
                S.push(NULL);
            } 
            else if(data[i] == '(') {
                int j = i + 1;
                int x = 0;
                while(data[j] != ')') {
                    char c = data[j];
                    x = x* 10 + c - '0'; 
                    j++;
                }
                auto cur = new TreeNode(x);
                cur->right = S.top();
                 S.pop();
                cur->left =  S.top();
                S.pop();
                S.push(cur);
                i = j;
            }  
        }
        return S.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
