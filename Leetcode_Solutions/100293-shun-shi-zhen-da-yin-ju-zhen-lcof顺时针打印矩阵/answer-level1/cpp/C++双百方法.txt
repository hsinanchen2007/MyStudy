### 执行结果
![image.png](https://pic.leetcode-cn.com/f2f230eb4fe62268608c4eb3469c66eb784f86e9700c1d942fde70b14db8c460-image.png)

### 解题思路
**一个很好理解但是不漂亮的方法，望评论交流指正！**
<br>
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int size = matrix.size() * matrix[0].size(); // 矩阵中元素总数

        int row = 0; // 当前行号
        int col = 0; // 当前列号
        int d = 0; // 当前方向
        
        int rowUpLimit = 0; // 行最大限制
        int colUpLimit = 0; // 列最大限制
        int rowDownLimit = matrix.size() - 1; // 行最小限制
        int colDownLimit = matrix[0].size() - 1; // 列最小限制
        
        bool change = false; // 是否改变过方向
        int changeTime = 0; // 改变方向的次数
        
        res.push_back(matrix[row][col]);
        for (int i = 0; i < size; i++) {
            row = row + dir[d].first;
            col = col + dir[d].second;
            while (row < rowUpLimit || row > rowDownLimit || col < colUpLimit || col > colDownLimit) {
                row = row - dir[d].first;
                col = col - dir[d].second;
                d = (d + 1) % 4;
                row = row + dir[d].first;
                col = col + dir[d].second;
                
                change = true;
                changeTime++;
                if (changeTime > 1) { // 方向更替一定是右->下->左->上->右的循环，每次只可能改变一个方向，因此当改变一次方向不够的时候，所有的数字都已经遍历过
                    return res;
                }
            }
            changeTime = 0;
            if (change == true) {
                if (d == 1) {
                    rowUpLimit++;
                } else if (d == 2) {
                    colDownLimit--;
                } else if (d == 3) {
                    rowDownLimit--;
                } else {
                    colUpLimit++;
                }
                
                change = false;
            }
            
            res.push_back(matrix[row][col]);
        }
        return res;
    }
};