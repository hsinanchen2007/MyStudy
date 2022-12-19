### 解题思路
递归就是这么个神奇的方法，连我自己都还没想透是怎么做到的，但它就是能过。
其实可以从递归求二叉树深度的角度出发，添加节点和子节点的数值比较，以及路径长度的计算。

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
    int maxlen;
    int longestUnivaluePath(TreeNode* root) {
        maxlen = 0;
        samevallen(root);
        return maxlen;
    }

    int samevallen(TreeNode* node){
        if(node){
            int left_count = 0;
            if(node->left){
                if(node->val == node->left->val){
                    left_count += 1;
                    left_count += samevallen(node->left);
                } else {
                    samevallen(node->left);
                }
            }
            int right_count = 0;
            if(node->right){
                if(node->val == node->right->val){
                    right_count += 1;
                    right_count += samevallen(node->right);
                } else {
                    samevallen(node->right);
                }
            }
            maxlen = max(maxlen,left_count+right_count);
            return max(left_count,right_count);
        }
        return 0;
    }
};
```