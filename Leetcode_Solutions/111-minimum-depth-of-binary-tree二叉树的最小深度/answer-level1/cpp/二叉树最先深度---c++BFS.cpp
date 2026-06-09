使用BFS迭代，找到的第一个叶子节点，就可以返回
```
class Solution {
public:
    int depth=0;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            auto size = q.size();
            i++;
            while(size--){
                TreeNode* now = q.front();
                q.pop();
                if(now->left==nullptr&&now->right==nullptr){
                    depth=i;
                    return ;
                }
                if(now->left!=nullptr) q.push(now->left);
                if(now->right!=nullptr) q.push(now->right);
            }     
        }
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        bfs(root);
        return depth;
        
    }
};
```
