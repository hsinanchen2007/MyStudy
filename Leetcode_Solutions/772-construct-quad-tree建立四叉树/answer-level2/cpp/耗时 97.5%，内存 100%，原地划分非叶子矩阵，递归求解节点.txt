![IMG_3165.PNG](https://pic.leetcode-cn.com/db651d4e960af7ce95c54ca96a82111280f7f485b9de0a792262331fa4cc10c7-IMG_3165.PNG)

```
class Solution {
public:
    /*
     核心思路：
     当前矩阵由三个参数确定：左上角元素的行号 row 列号 col，以及矩阵规模 N
     判断当前矩阵是否为叶子节点，方法为比较左上角元素和其他元素的关系，
     若出现不等则为非叶节点，需要继续划分，每个划分后的矩阵规模为 N/2 * N/2，
     这 4 个矩阵递归地生成当前节点的 4 个子节点。
     若元素全相等则返回一个叶子节点 (true, grid[row][col])。
     **/
    Node* helper(vector<vector<int>>& grid, int row, int col, int N) {
        int first = grid[row][col];
        Node *result = new Node();
        bool isLeaf = true;
        int m, n;
        m = row+N;
        n = col+N;
        
        // 遍历比较每个元素与左上角元素的值
        for (int i = row; i < m; ++i) {
            for (int j = col; j < n; ++j)
                if (grid[i][j] != first) {
                    isLeaf = false;
                    break;
                }
            if (!isLeaf) break;
        }
        
        if (isLeaf) {
            result->val = first;
            result->isLeaf = isLeaf;
        } else {
            // 存在不一样的元素，递归计算子节点，每个子矩阵的行列数减半
            N /= 2;
            result->isLeaf = isLeaf;
            result->topLeft = helper(grid, row, col, N);
            result->topRight = helper(grid, row, col+N, N);
            result->bottomLeft = helper(grid, row+N, col, N);
            result->bottomRight = helper(grid, row+N, col+N, N);
        }
        return result;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int N = (int)grid.size();
        if (N == 0) return NULL;
        return helper(grid, 0, 0, N);
    }
};
```

