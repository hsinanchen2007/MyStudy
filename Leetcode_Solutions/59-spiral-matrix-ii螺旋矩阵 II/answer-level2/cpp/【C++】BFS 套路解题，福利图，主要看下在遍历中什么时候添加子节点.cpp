图1中10的子节点有两个，11和12，其中12有子节点
![20191011-210624(eSpace).JPG](https://pic.leetcode-cn.com/943bd0f54e4e849ea6342a80412c516fa0b2bc7684b3982243aec6ac00cbdb00-20191011-210624\(eSpace\).JPG)
图2中16有4个子节点，17、18、19、20，其中只有20有子节点
![20191011-210630(eSpace).JPG](https://pic.leetcode-cn.com/12b46b1f57f9d0ca06ee7e8bf0770304dcf3650dc1f1238e16e6f39913f922ec-20191011-210630\(eSpace\).JPG)
```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/11
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        data = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        spiralOrder(matrix);
        return matrix;
    }

private:
    void spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        if (matrix.empty()) {
            return;
        }
        if (matrix.at(0).empty()) {
            return;
        }

        int m = matrix.size();
        int n = matrix.at(0).size();

        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<pair<int, int>> pathQueue;
        pathQueue.push({ 0, 0 });
        visited[0][0] = true;
        while (!pathQueue.empty()) {
            pair<int, int> current;
            while (!pathQueue.empty()) {
                current = pathQueue.front();
                pathQueue.pop();
                matrix[current.first][current.second] = data++;
            }

            int col = current.second;
            int row = current.first;
            if (col + 1 < n && !visited[row][col + 1]) {
                pathQueue.push({ row, col + 1 });
                visited[row][col + 1] = true;
                continue;
            }

            if (row + 1 < m && !visited[row + 1][col]) {
                pathQueue.push({ row + 1, col });
                visited[row + 1][col] = true;
                continue;
            }

            if (col - 1 >= 0 && !visited[row][col - 1]) {
                pathQueue.push({ row, col - 1 });
                visited[row][col - 1] = true;
                continue;
            }

            while ((row - 1 >= 0) && !visited[row - 1][col]) {
                pathQueue.push({ row - 1, col });
                visited[row - 1][col] = true;
                row -= 1;
            }
        }
        return;
    }
private:
    int data;
};
```
