### 解题思路
先搞清楚什么是层序遍历。中间的那些null，只针对上层有值的叶子节点添加的。如果上传已经是null了，那么这层是不用添加对应的null的。
理解后，借助队列就很好做了。

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
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2) {
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length()) {
            v.push_back(s.substr(pos1));
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr) {
            return "[]";
        }
        string res = "[";
        vector<string> array;
        que.push(root);
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            if (cur != nullptr) {
                array.emplace_back(to_string(cur->val));
                que.push(cur->left);
                que.push(cur->right);
            } else {
                array.emplace_back("null");
            }
        }
        while (array.size() > 0 && array.back() == "null") {
            array.erase(array.end()-1);
        }
        for (auto s: array) {
            res += s + ",";
        }
        res = res.substr(0, res.size()-1);
        return res+="]";
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() <= 2) {
            return nullptr;
        }
        auto str = data.substr(1, data.size()-2);
        vector<string> array;
        SplitString(str, array, ",");
        
        queue<TreeNode*> que;
        TreeNode *root = new TreeNode(stoi(array[0]));
        que.push(root);
        int index = 1;
        long size = array.size();
        while (index < size) {
            auto r = que.front();
            que.pop();
            if (array[index] != "null") {
                r->left = new TreeNode(stoi(array[index]));
                que.push(r->left);
            }
            index++;
            if (index < size && array[index] != "null") {
                r->right = new TreeNode(stoi(array[index]));
                que.push(r->right);
            }
            index++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```