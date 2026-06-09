![微信图片编辑_20200323104125.jpg](https://pic.leetcode-cn.com/0709446d2f98d491e5795436484e3dc72873c98de19b4d42ac71518386a55b00-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87%E7%BC%96%E8%BE%91_20200323104125.jpg)

```
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
private:
    int sum = 0;
public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return sum;
    }
    void dfs(TreeNode* root){
        if(!root){
            return ;
        }
        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left){
                    sum += root->left->left->val;
                }
                if(root->left->right){
                    sum += root->left->right->val;
                }
            }
            if(root->right){
                if(root->right->left){
                    sum += root->right->left->val;
                }
                if(root->right->right){
                    sum += root->right->right->val;
                }
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
};
```
