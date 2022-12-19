思路：把树转化为无向图，并且直接在图上bfs最近的叶子结点

要考虑到的几点：
1、是无向图，因为图在构建的时候不知道以后到底要从哪个节点出发
2、用邻接表构建图，因为和每个结点相连的结点最多只有3个
3、要确认哪些结点是叶子结点，因为会无向图会丢失信息，即无法确定哪个点是另一个点的孩子
4、标记已经走过的结点，防止走回头路

```
class Solution {
public:    
    vector<vector<int>> conn;
    
    int findClosestLeaf(TreeNode* root, int k) {
        vector<bool> isLeaf(1001,false);
        vector<int> temp;
        for(int i = 0; i < 1001; ++i){
            conn.push_back(temp);
        }
        dfs(root, k, isLeaf);
        if(isLeaf[k]) return k;
        queue<int> q;
        set<int> visited;
        q.push(k);
        visited.insert(k);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                int curr = q.front();
                q.pop();
                if(conn[curr].size() == 1 && isLeaf[curr]) return curr;
                else{
                    for(int j = 0; j < conn[curr].size(); ++j){
                        if(visited.find(conn[curr][j]) == visited.end()){
                            int next = conn[curr][j];
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
        }
        
        return k;
    }
    
    void dfs(TreeNode* root, int k, vector<bool>& isLeaf){
        if(!root) return;
        if(!root->left && !root->right){
            isLeaf[root->val] = true;
        }
        if(root->left){
            dfs(root->left, k, isLeaf);
            conn[root->val].push_back(root->left->val);
            conn[root->left->val].push_back(root->val);
        }
        if(root->right){
            dfs(root->right, k, isLeaf);
            conn[root->val].push_back(root->right->val);
            conn[root->right->val].push_back(root->val);
        }
    }
    
};
```
