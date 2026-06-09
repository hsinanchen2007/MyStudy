思路跟[102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)一样
```
class Solution {
    void reverse_vector(vector<int>& v){
        int n = v.size();
        int tmp=0;
        for(int i=0; i<n/2; i++){
            tmp = v[i];
            v[i] = v[n-i-1];
            v[n-i-1] = tmp;
        }
        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        vector<int> sub_res;
        bool level = false;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            while(q.front()!=NULL){
                TreeNode* tmp = q.front();
                q.pop();

                sub_res.push_back(tmp->val);

                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
                
            q.pop();
            
            if(!sub_res.empty()){
                if(level)
                    reverse_vector(sub_res);
                res.push_back(sub_res);
                sub_res.clear();
                level = !level;
            }
            if(q.empty()) break;
            q.push(NULL);
        }
        return res;
    }
};
```
