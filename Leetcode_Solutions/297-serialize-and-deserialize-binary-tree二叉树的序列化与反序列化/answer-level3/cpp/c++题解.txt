先序遍历生成序列化结构，然后一次遍历字符串实现发序列化
题目中的例子序列化后是：1[2[,],3[4[,],5[,]]]
```
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        return to_string(root->val) + "[" + serialize(root->left) + "," + serialize(root->right) + "]";
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode*> s;
        TreeNode* root = NULL;
        string val;
        for (int i = 0; i < data.size(); ++i) {
            char t = data[i];
            if ((t >= '0' && t <= '9') || t == '-') {
                val += t;
            } else {
                if (i >= 1 && data[i - 1] != ']') {
                    TreeNode* node = NULL;
                    if (!val.empty())
                        node = new TreeNode(stoi(val));
                    if (root == NULL) 
                        root = node;
                    val.clear();
                    s.push(node);
                }
                if (t == ']' || t == ',') {
                    TreeNode* node = s.top();
                    s.pop();
                    if (!s.empty()) {
                        TreeNode* prev_node = s.top();
                        if (data[i] == ',')
                            prev_node->left = node;
                        else
                            prev_node->right = node;
                    }
                }
            }
        }
        return root;
    }
};
```
