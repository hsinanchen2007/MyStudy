递归算法：
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)
            return triangle[0][0];

        return getMinTotal(triangle, 0, 0);
    }

    int getMinTotal(const vector<vector<int>>& triangle, int posX, int posY){
        if(posX == triangle.size() - 1)
            return triangle[posX][posY];
        else{
            int leftMin = getMinTotal(triangle, posX + 1, posY);
            int rightMin = posY + 1 < triangle[posX + 1].size() ? getMinTotal(triangle, posX + 1, posY + 1) : INT_MAX;
            return min(leftMin, rightMin) + triangle[posX][posY];
        }
    }
};
```

毫无疑问是超时的，观察递归算法可看出重复子过程很多，所以可以使用记忆数组的方式：
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)
            return triangle[0][0];
        row = triangle.size();
        memo = vector<vector<int>>(row, vector<int>());
        for(int i = 0; i < row; i++) {
            if(i == row - 1) {
                memo[i] = vector<int>(triangle[i].size());
                for (int j = 0; j < triangle[i].size(); ++j) {
                    memo[i][j] = triangle[i][j];
                }

            } else {
                memo[i] = vector<int>(triangle[i].size(), INT_MAX);
            }
        }

        return getMinTotal(triangle, 0, 0);
    }

    int getMinTotal(const vector<vector<int>>& triangle, int posX, int posY){
        if(memo[posX][posY] != INT_MAX)
            return memo[posX][posY];
        else{

            int leftMin = INT_MAX;
            if(memo[posX + 1][posY] == INT_MAX) {
              leftMin = getMinTotal(triangle, posX + 1, posY);
              memo[posX + 1][posY] = leftMin;
            } else {
                leftMin = memo[posX + 1][posY];
            }

            int rightMin = INT_MAX;
            if(posY + 1 < row) {
                if(memo[posX + 1][posY + 1] == INT_MAX) {
                    rightMin = getMinTotal(triangle, posX + 1, posY + 1);
                    memo[posX + 1][posY + 1] = rightMin;
                } else {
                    rightMin = memo[posX + 1][posY + 1];
                }
            }

            return min(leftMin, rightMin) + triangle[posX][posY];
        }
    }

private:
    vector<vector<int>> memo;
    int row;
};
```

执行用时 :
24 ms, 在所有 C++ 提交中击败了5.71%的用户

内存消耗 :
8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

