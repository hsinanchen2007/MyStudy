### 解题思路
利用getline,实现item的获取，
采用层次打印和层次创建node的方法。

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
        if(root==nullptr) return "[]";
        string result = "";
        queue<TreeNode*> mQueue;
        mQueue.push(root);
        while(!mQueue.empty()){
            TreeNode* node = mQueue.front();
            mQueue.pop();
            if(node==nullptr){
                result += "null,";
            }
            else{
                result += to_string(node->val) + ",";
                mQueue.push(node->left);
                mQueue.push(node->right);
            }
        }
        result = "["+result.substr(0, result.size()-1)+"]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size()-2);
        if(data.empty()) return nullptr;
        string item;
        stringstream ss;
        ss.str(data);

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> mQueue;
        mQueue.push(root);

        while(true){
            TreeNode* node = mQueue.front();
            mQueue.pop();

            if(!getline(ss, item, ','))
                break;
            if(item!="null"){
                TreeNode* left = new TreeNode(stoi(item));
                node->left = left;
                mQueue.push(left);
            }

            if(!getline(ss, item, ','))
                break;
            if(item!="null"){
                TreeNode* right = new TreeNode(stoi(item));
                node->right = right;
                mQueue.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```