### 解题思路
此处撰写解题思路

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
    void temp(set<int>& hash,TreeNode* root){
        if(root == NULL){
            return;
        }
        hash.insert(root->val);
        temp(hash,root->left);
        temp(hash,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        set<int> hash;
        temp(hash,root);
        int res = 0;
        int times = 0;
        for(auto it = hash.begin();it != hash.end();it++){
            res = *it;
            times++;
            if(times == k){
                break;
            }
        }
        return res;
    }
};
```