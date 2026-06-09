### 解题思路
情况1：重新以当前root为跟节点，作为最大值。---》newPath = root->val + leftgain + rightgain;
情况2：以root之前的节点，作为最大值。----》maxVal；
最后，加入当前的节点以供自己作为左子树或者右子树时，获得leftgain或者rightgain。

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
int maxVal = INT_MIN;
public:
    int maxgain(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftgain = max(maxgain(root->left), 0);
        int rightgain = max(maxgain(root->right), 0);
        int newPath = root->val + leftgain + rightgain;
        maxVal = max(newPath, maxVal); 
        return root->val + max(leftgain, rightgain);
    }
    int maxPathSum(TreeNode* root){
        maxgain(root);
        return maxVal;
    }
};
```