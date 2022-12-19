### 解题思路
一开始想到使用深度优先搜索，但是每一层最后一个节点，不好在算法中描述这个特征，然后就使用了BFS.

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
    vector<int> rightSideView(TreeNode* root) {
        // BFS比较好想，dfs如何找他的所求点的满足条件，特征是每一层的最优，
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int num=1;
        TreeNode* now;
        while(!q.empty()){
            int cnt=0;
            for(int i=0;i<num;i++){
                   now = q.front();
                   q.pop();
                   // 对下一层进行处理
                   if(now->left){
                        q.push(now->left);
                        cnt++;
                   }
                   if(now->right){
                       q.push(now->right);
                       cnt++;
                   }
                   // 压入当前层的最右结点
                   if(i==num-1){
                       res.push_back(now->val);
                   }
            }
            num = cnt;
        }
        return res;
    }
};
```