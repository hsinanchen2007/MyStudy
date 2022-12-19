### 解题思路
求出最大高度，然后层序遍历时到了最底层就返回队列第一个。
然而效率极低。。。

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
    //最大高度即最大层数
    int height(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            if(count == h) return q.front()->val;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            count++;
        }
        return 0;
    }
};
```