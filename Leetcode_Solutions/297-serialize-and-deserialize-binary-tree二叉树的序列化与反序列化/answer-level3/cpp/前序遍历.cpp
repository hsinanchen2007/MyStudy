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
private:
    int i;
    vector<string> split(string src, string delimeter) {
        if (src.empty()) return {};
        vector<string> ans;
        int pos1 = 0, pos2 = src.find(delimeter);
        while (pos2 != string::npos) {
            ans.push_back(src.substr(pos1, pos2 - pos1));
            pos1 = pos2 + delimeter.size();
            pos2 = src.find(delimeter, pos1);
        }
        if (pos1 != src.size())
            ans.push_back(src.substr(pos1));
        return ans;
    }

    TreeNode* deserialize(vector<string>& nums) {
        if (i == nums.size() || nums[i] == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(nums[i]));
        i ++;
        root->left = deserialize(nums);
        i ++;
        root->right = deserialize(nums);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        else
            return to_string(root->val) + ","  + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        i = 0;
        vector<string> nums = split(data, ",");
        TreeNode* res = deserialize(nums);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```