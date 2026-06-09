第一想法向下遍历，不过此时需要考虑越界问题，较麻烦

此处参考他人思路，非左上边界元素与其相邻的左上方比较，此时就不需要考虑边界了，更方便

代码：
```
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for(int i = 1 ; i < row ; i++) {
            for(int j = 1 ; j < col ; j++) {
                if(matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }
        return true;
	}
};
```
