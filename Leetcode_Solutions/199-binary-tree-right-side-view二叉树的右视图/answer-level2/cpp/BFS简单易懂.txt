### 解题思路
其实就是一层一层的装进队列，取每层队列尾处的那个就行了，取完后就从左到右pop出来，并且pop一个前便添加这个节点的左右节点进去。代码如下

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
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.back()->val);
            int size=q.size();//这个size是取当前队列里所有存在的节点
            //在这个循环从前到后pop出队列所有的节点，并依次添加新的节点
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
```