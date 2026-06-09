  想一下觉得要我们不使用新的内存空间，那么一定是在原有的基础上向量上进行元素的交换。
  但是交换要有规律，所以首先想到先沿对角线对称交换下，发现得到的矩阵与答案相差的就是每一行是倒序的，所以直接倒序得出：
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size=int(matrix.size());
        int tmp;
        for(int i=0;i<size;++i)
            for(int j=0;j<i+1;j++){
                //先对称交换
                if(i!=j){
                    tmp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=tmp;
                }
            }
            //再倒置
        for(int i=0;i<size;++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};