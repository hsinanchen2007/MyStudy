执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :9.6 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    Node* construct(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        Node *node = new Node(true, false, NULL, NULL, NULL, NULL);
        if (judge(grid, 0, col, 0, row)) {
            node->val = grid[0][0];
            node->isLeaf = true;
            node->topLeft = NULL;
            node->topRight = NULL;
            node->bottomLeft = NULL;
            node->bottomRight = NULL;
            return node;
        }
        dfs(grid, node, 0, col, 0, row);
        return node;
    }
    
    int dfs(vector<vector<int>>& grid, Node* root, int tl, int tr, int bl, int br)
    {
        if (tl+1 == tr) {
            root->val = grid[bl][tl];
            root->isLeaf = true;
            root->topLeft = NULL;
            root->topRight = NULL;
            root->bottomLeft = NULL;
            root->bottomRight = NULL;
            return 0;
        }
        int tm = tl + (tr - tl) / 2;
        int bm = bl + (br - bl) / 2;
        if (judge(grid, tl, tm, bl, bm)) {  //左上
            root->topLeft = new Node(grid[bl][tl], true, NULL, NULL, NULL, NULL);

        }else{
            root->topLeft = new Node(true, false, NULL, NULL, NULL, NULL);
            dfs(grid, root->topLeft, tl, tm, bl, bm);
        }
        
        if (judge(grid, tm, tr, bl, bm)) {  //右上
            root->topRight = new Node(grid[bl][tm], true, NULL, NULL, NULL, NULL);
        }else{
            root->topRight = new Node(true, false, NULL, NULL, NULL, NULL);
            dfs(grid, root->topRight, tm, tr, bl, bm);
        }
        
        if (judge(grid, tl, tm, bm, br)) {  //左下
            root->bottomLeft = new Node(grid[bm][tl], true, NULL, NULL, NULL, NULL);
        }else{
            root->bottomLeft = new Node(true, false, NULL, NULL, NULL, NULL);
            dfs(grid, root->bottomLeft, tl, tm, bm, br);
        }
        
        if (judge(grid, tm, tr, bm, br)) {  //右下
            root->bottomRight = new Node(grid[bm][tm], true, NULL, NULL, NULL, NULL);
        }else{
            root->bottomRight = new Node(true, false, NULL, NULL, NULL, NULL);
            dfs(grid, root->bottomRight, tm, tr, bm, br);
        }
        return 0;
    }
        
        
    bool judge(vector<vector<int>>& grid, int tl, int tr, int bl, int br)
    {
        int tmp = grid[bl][tl];
        for (int i = bl; i < br; ++i) {
            for (int j = tl; j < tr; ++j) {
                if (tmp != grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```






