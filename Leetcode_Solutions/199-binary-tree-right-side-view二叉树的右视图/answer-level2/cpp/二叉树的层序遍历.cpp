二叉树层序遍历，将每一层最右侧的结点放入结果即可。
在将队列中某一结点的孩子放入队列时，我们可以先压右孩子，再压左孩子，这样每一层的队头元素就是我们要的结果。
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
public:
    vector<int> rightSideView(TreeNode* root) {
        //层序遍历，每一层从右往左数第一个结点放入vector即可
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        // res.push_back(root->val);
        while(!q.empty()){
            int n = q.size();
            res.push_back(q.front()->val);
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
        }
        return res;
    }
};
```
