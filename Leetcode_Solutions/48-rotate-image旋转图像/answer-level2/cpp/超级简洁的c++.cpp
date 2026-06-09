// ```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        unsigned long n_size = matrix.size();
        //求出矩阵的转置
        for (int i = 0; i < n_size; i++) {
            for (int j = i; j < n_size; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //将每一行反转
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// ```
// 有什么疑问的话欢迎留言😁😁😁👍,方便的话动动小手指点个赞噢😊😊。