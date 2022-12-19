### 解题思路
一开始没有在数字前面加“#”，用例没过，加了之后就可以了
主要思路是将两棵树分别序列化为字符串，然后用查找子串的方式判断是否为子树

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
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string source = treeSeriallize(s);
        string dest = treeSeriallize(t);

        if (source.find(dest) == std::string::npos) {
            return false;
        } else {
            return true;
        }
    }
private:
    string treeSeriallize(TreeNode* root) {
        if (root == NULL) {
            return "#_";
        }
        string result = "#" + to_string(root->val) + "_";
        
        result += treeSeriallize(root->left);
        result += treeSeriallize(root->right);
        
        return result;
    }
};
```