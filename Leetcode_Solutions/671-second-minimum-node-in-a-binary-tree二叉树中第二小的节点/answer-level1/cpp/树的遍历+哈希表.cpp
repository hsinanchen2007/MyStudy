### 解题思路
树的遍历，将结点存入set（res）中（自动去重）

若res的size 小于2，返回-1
否则返回*(res.begin()+1)

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
    set<int> res;
    void search(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left) search(root->left);
        res.insert(root->val);
        if(root->right) search(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        search(root);
       
        if(res.size() >=2){
            auto it = res.begin();
            it++;
            return *it;
        }

       return -1;
    }
};
```