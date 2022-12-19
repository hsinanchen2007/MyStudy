![54. 螺旋矩阵.png](https://pic.leetcode-cn.com/d868aac217dc942b0a95ace42a0c339857eba6ada466e76ccb60575b40e5b582-54.%20%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5.png)

```
vector<int> spiralOrder(vector<vector<int>>& matrix){
    unsigned short row = matrix.size(), col = matrix[0].size();
    unsigned short top_thresh = 0, down_thresh = row, left_thresh = 0, right_thresh = col;
    vector<int> res;
    while (true){
        //向右遍历
        for (unsigned short i = left_thresh; i != right_thresh; i++) res.push_back(matrix[top_thresh][i]);
        top_thresh++;
        if (res.size() == row * col) break;
        //向下遍历
        for (unsigned short i = top_thresh; i != down_thresh; i++) res.push_back(matrix[i][right_thresh - 1]);
        right_thresh--;
        if (res.size() == row * col) break;
        //向左遍历
        for (short i = right_thresh - 1; i != left_thresh - 1; i--) res.push_back(matrix[down_thresh - 1][i]);
        down_thresh--;
        if (res.size() == row * col) break;
        //向上遍历
        for (short i = down_thresh - 1; i != top_thresh - 1; i--) res.push_back(matrix[i][left_thresh]);
        left_thresh++;
        if (res.size() == row * col) break;
    }
    return res;
}

