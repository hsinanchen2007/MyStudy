方法一：
bfs，用vector替代queue方便遍历获取每层元素：
```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root){
            return res;
        }
        vector<TreeNode*>que;
        que.emplace_back(root);
        int count=0;
        while(!que.empty()){
            int len=que.size();
            vector<int>tmp;
            if(count%2==0){
                for(int i=0;i<len;i++){
                    tmp.emplace_back(que[i]->val);
                }
            }else{
                for(int i=len-1;i>=0;i--){
                    tmp.emplace_back(que[i]->val);
                }
            }
            count++;
            res.emplace_back(tmp);
            for(int i=0;i<len;i++){
                TreeNode* element=que.front();
                que.erase(que.begin());
                if(element->left){
                    que.emplace_back(element->left);
                }
                if(element->right){
                    que.emplace_back(element->right);
                }
            }
        }
        return res;
    }
};
```
方法二：
dfs，每次遍历元素的时候根据节点所在深度的奇偶性决定是在头部添加元素还是在尾部添加元素：
```
/**
class Solution {
public:
    vector<vector<int>>res;
    void dfs(TreeNode*root,int depth){
        if(!root){
            return;
        }
        if(depth==res.size()){
            res.emplace_back();
        }
        dfs(root->left,depth+1);
        if(depth%2==0){
            res[depth].push_back(root->val);
        }else{
            res[depth].insert(res[depth].begin(),root->val);
        }
        dfs(root->right,depth+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
        dfs(root,0);
        return res;
    }
};
```
