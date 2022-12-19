### 解题思路
此处撰写解题思路

### 代码

```cpp
/* 二叉树序列化和反序列化
 * 序列化 先序
 * 反序列化：
 *    在先序遍历时填入相应的值
 * */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int st = 0;
        return help(st, data);
    }

    TreeNode* help(int &i, const string &s){
        if(s[i] == '#'){
            i += 2; // 跳过# ,
            return nullptr;
        }
        int st = i;
        while(s[i] != ',') i++;
        auto *root = new TreeNode(stoi(s.substr(st, i - st)));
        i++; // 跳过 ,
        root->left = help(i, s);
        root->right = help(i, s);
        return root;
    }
};
```