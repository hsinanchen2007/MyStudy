 `c++`  分治递归
```c++
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if(!grid.size()) return nullptr;
        return dfs(grid,0,grid.size() - 1,0,grid.size()- 1);;
    }
    Node* dfs(vector<vector<int>>& grid,int row1,int row2,int col1,int col2){
        if(row1 == row2 || col1 == col2) return new Node(grid[row1][col1] == 1 ? true : false,true,nullptr,nullptr,nullptr,nullptr);
        Node* root = new Node();
        root -> isLeaf = false;
        root -> topLeft = dfs(grid,row1,(row2 + row1) / 2,col1,(col1 + col2)/2);
        root -> topRight = dfs(grid,row1,(row2 + row1) / 2,(col1 + col2)/2+1,col2);
        root -> bottomLeft = dfs(grid,(row2 + row1) / 2 +1,row2,col1,(col1 + col2)/2);
        root -> bottomRight = dfs(grid,(row2 + row1) / 2 +1,row2,(col1 + col2)/2+1,col2);
        bool f = false;
        if(root -> topLeft -> val == root -> topRight -> val && root -> topLeft->val == root -> bottomLeft -> val && root -> bottomRight -> val == root -> topLeft -> val){
            if(root -> topLeft -> isLeaf && root -> topRight-> isLeaf && root -> bottomLeft -> isLeaf && root -> bottomRight -> isLeaf) f = true;
            root -> val = root -> topLeft -> val;
        }else root -> val = false;
        if(f){
            root -> topLeft = nullptr;
            root -> topRight = nullptr;
            root -> bottomLeft = nullptr;
            root -> bottomRight = nullptr;
            root -> isLeaf = true;
        }
        return root;
    }
};
```
 