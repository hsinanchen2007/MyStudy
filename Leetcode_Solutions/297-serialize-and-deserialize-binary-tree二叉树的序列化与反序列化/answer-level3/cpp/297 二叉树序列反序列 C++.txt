### 解题思路
思路1，按照先左子树，后右子树的序列方式进行序列化和反序列化，这样建叔的时候会比较方便
思路2，按照leetcode给的方式构建树
### 代码

```cpp
#include <stdlib.h>
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
        if (!root) return "";
        stack<TreeNode*> ss;
        ss.push(root);
        while(!ss.empty()) {
            TreeNode* tmp = ss.top();
            ss.pop();
            if (tmp) {
                res += to_string(tmp->val) + ",";
                ss.push(tmp->right);
                ss.push(tmp->left);
            } else {
                res += "n,";
            }
        }
        //res.erase(res.end()-1);
        //cout << res << endl;
        return res;
    }
    TreeNode* make_tree(vector<string> &str_list, int &l) {
        //cout << l << endl;
        if (str_list[l] == "n") {
            l++;
            return NULL;
        }
        TreeNode * node = new TreeNode(atoi(str_list[l].c_str()));
        l++;
        node->left = make_tree(str_list, l);
        node->right = make_tree(str_list, l);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> str_list;
        string tmp;
        for (auto i : data) {
            if (i == ',') {
                TreeNode* node = NULL;
                str_list.push_back(tmp);     
                tmp = "";
            } else tmp += i;
        }
        int l = 0;
        return make_tree(str_list, l);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
方法2：

```cpp
#include <stdlib.h>
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
        if (!root) return "[]";
        res = "[";
        queue<TreeNode*> ss;
        queue<TreeNode*> ss2;
        vector<string> vv;
        ss.push(root);
        while(!ss.empty()) {
            bool has_next = false;
            while(!ss.empty()) {
                TreeNode* tmp = ss.front();
                ss.pop();
                if (tmp) {
                    res = res + to_string(tmp->val);
                    if (tmp->left || tmp->right) has_next = true;
                    ss2.push(tmp->left);
                    ss2.push(tmp->right);
                } else {
                    res = res + "null";
                }
                if (!ss.empty()) res = res + ",";
            }
            while (has_next && !ss2.empty()) {
                ss.push(ss2.front());
                ss2.pop();
            }
            if (!ss.empty()) res = res + ",";
        }
        res = res + "]";
        //cout << "res: " << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> qs;
        queue<TreeNode*> ss2;
        string tmp;
        for (auto i : data) {
            if (i == '[' || i == ']') continue;
            if (i == ',') {
                TreeNode* node = NULL;
                if (tmp != "null") {
                    node = new TreeNode(atoi(tmp.c_str()));
                }
                qs.push(node);      
                tmp="";
                continue;
            }
            tmp += i;
        }
        if (!tmp.empty()) {
            TreeNode* node = NULL;
            if (tmp != "null") {
                node = new TreeNode(atoi(tmp.c_str()));
            }      
            qs.push(node);      
        }
        if (qs.empty()) return NULL;
        TreeNode* head = qs.front();
        ss2.push(qs.front());
        qs.pop();
        while (!ss2.empty()) {
            TreeNode* tmp = ss2.front();
            ss2.pop();
            if (!qs.empty()) {
                tmp->left = qs.front();
                if (qs.front()) ss2.push(qs.front());
                qs.pop();
            } else tmp->left = NULL;
            if (!qs.empty()) {
                tmp->right = qs.front();
                if (qs.front()) ss2.push(qs.front());
                qs.pop();
            } else tmp->right = NULL;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```