```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)
            return res;
        queue<TreeNode *>Q;//队列是先进先出的操作  因此可以这么做
        TreeNode* p;
        Q.push(root);
        while(Q.empty()==0){
            vector<int>a;
            int width=Q.size();//width设置的比较巧妙  把前一个队列的中的所有元素排出去  再开始下一层
            for(int i=0;i<width;i++){
                p=Q.front();
                a.push_back(p->val);
                Q.pop();
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            res.push_back(a);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```
