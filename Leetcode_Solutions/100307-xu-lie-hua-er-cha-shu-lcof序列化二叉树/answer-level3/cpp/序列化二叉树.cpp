### 解题思路
这道题不需要在意自己序列化结果格式，只需要能在反序列化后得到原来的树结构即可，主要注意stringstream以及getline函数的使用。
另外就是队列在避免递归中的使用。

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "null";
        }
        string ser_ans;
        queue<TreeNode*> node_list;
        node_list.push(root);
        while (!node_list.empty()) {
            TreeNode* node = node_list.front();
            node_list.pop();
            if (node) {
                ser_ans += to_string(node->val) + ',';
                node_list.push(node->left);
                node_list.push(node->right);
            } else {
                ser_ans += "null,";
            }
        }
        if (ser_ans[ser_ans.length() - 1] == ',') {
            ser_ans.pop_back();
        }
        return ser_ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") {
            return NULL;
        }
        //stringstream的使用代替字符串分割
        stringstream ss(data);
        string val_str;
        getline(ss, val_str, ',');

        TreeNode* root = new TreeNode(stoi(val_str));
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            TreeNode* tmp = node_queue.front();
            node_queue.pop();

            if (getline(ss, val_str, ',') && val_str != "null") {
                tmp->left = new TreeNode(stoi(val_str));
                node_queue.push(tmp->left);
            }
            if (getline(ss, val_str, ',') && val_str != "null") {
                tmp->right = new TreeNode(stoi(val_str));
                node_queue.push(tmp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```