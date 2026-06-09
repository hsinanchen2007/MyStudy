### 解题思路
设置一个全局变量vector<int> k，通过先序遍历把两个数的节点的值全部读入，然后用algorithm中的sort进行排序

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
    vector<int> k;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        Pre(root1);
        Pre(root2);
        sort(k.begin(), k.end());
        return k;
    }
    private: void Pre(TreeNode* root){
        if (root==NULL) return;
        else k.push_back(root->val);
        Pre(root->left);
        Pre(root->right);
    }
};
```