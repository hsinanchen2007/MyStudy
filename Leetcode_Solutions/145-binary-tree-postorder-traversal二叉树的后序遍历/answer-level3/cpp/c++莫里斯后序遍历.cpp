### 解题思路
莫里斯后序遍历和先序遍历几乎一样，不同处见注释，我同时也写了莫里斯中序和先序遍历的题解，有兴趣的可以看看

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        while(cur){
            ans.insert(ans.begin(),cur->val);//先序遍历中此句为ans.push_back(cur->val);
            if(!cur->right){
                cur=cur->left;
            }
            else{
                TreeNode* temp=cur->right;
                while(temp->left)
                    temp=temp->left;
                temp->left=cur->left;
                TreeNode* p=cur;
                cur=cur->right;
                p->right=NULL;
            }
        }
        return ans;
    }
};
```