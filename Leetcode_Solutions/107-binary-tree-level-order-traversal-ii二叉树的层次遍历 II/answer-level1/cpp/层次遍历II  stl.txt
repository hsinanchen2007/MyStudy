### 解题思路
此处撰写解题思路

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
    vector<vector<int>> res;
    void levelOrder(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
        vector<int> temp;//临时
        int len=q.size();
        while(len--){//本层节点数
            TreeNode* p=q.front();
            temp.push_back(p->val);//处理此节点+剖出
            q.pop();
            if(p->left) q.push(p->left);//左右子节点亚茹队列
            if(p->right) q.push(p->right);
        }
        res.push_back(temp);//本层结果亚茹
        }
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root);
        reverse(res.begin(),res.end());//数组，那么是按组来翻转，一组内部原数顺序不变
        return res;
    }
};





```