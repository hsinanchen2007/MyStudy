使用广度优先搜索时，从右往左向队列中添加新节点。每层队列首的节点即为右视图看到的节点。
```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> view;
        while(!q.empty()){
            int size = q.size();
            // 将每层最右边的节点添加到返回vector中
            view.push_back(q.front()->val);
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->right)
                    q.push(cur->right);
                if(cur->left)
                    q.push(cur->left);
            }
        }
        return view;
    }
};
```