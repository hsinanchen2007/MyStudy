```
    //考虑前序 根左右 想要得到后序 左右根 应该怎么做呢
    //首先可以把前序调整一下 根右左 然后逆序即可得到 左右根 即为后序遍历结果
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode* > stk;
        auto p = root;//遍历点
        while(p||!stk.empty()){//根右左的前序遍历
            while(p){
                ans.push_back(p->val);
                stk.push(p->left);
                p = p->right;
            }
            p = stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());//结果逆序即可
        return ans;
    }
```
