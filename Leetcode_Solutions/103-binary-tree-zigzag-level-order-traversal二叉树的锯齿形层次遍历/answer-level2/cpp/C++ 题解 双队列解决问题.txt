双队列遍历元素，轮换插入元素。
```c++
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<queue<TreeNode*>> myQueueVec(2, queue<TreeNode*>());
        myQueueVec[0].push(root);
        int i = 0;
        while(!myQueueVec[i].empty()){
            vector<int> tmp;
            tmp.reserve(myQueueVec[i].size());
            while(!myQueueVec[i].empty()){
                TreeNode* node = myQueueVec[i].front();
                if(node->left) myQueueVec[1-i].push(node->left);
                if(node->right) myQueueVec[1-i].push(node->right);
                myQueueVec[i].pop();
                if(i==0) tmp.insert(tmp.end(), node->val);
                else tmp.insert(tmp.begin(), node->val);
            }
            ans.push_back(tmp);
            i = 1-i; 
        }
        return ans;
    }
};
```