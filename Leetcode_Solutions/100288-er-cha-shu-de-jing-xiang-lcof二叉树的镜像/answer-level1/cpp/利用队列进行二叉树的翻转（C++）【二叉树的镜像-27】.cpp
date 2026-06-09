### 解题思路
- 利用队列进行层序遍历；
- 只是在每次取出那个节点的时候，先把它的左右孩子入队列，然后再进行交换。
- 这样相当于每个节点的左右孩子均翻转一遍，这样可以实现镜像翻转。

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL)  return root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode*temp=que.front();
            que.pop();
            if(temp->left){
                que.push(temp->left);
            }
            if(temp->right){
                que.push(temp->right);
            }
            TreeNode *swap=temp->left;
            temp->left=temp->right;
            temp->right=swap;
        }
    return root;
    }
};
```