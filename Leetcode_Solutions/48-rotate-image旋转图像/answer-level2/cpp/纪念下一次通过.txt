class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //需要交换的圈数
        int layers=n/2;
        for(int i=0;i<layers;i++){
            rotateOneLayer(matrix,i);
        }
    }
    
    //以4条长度相等的边为一圈，该函数完成一圈的交换
    void rotateOneLayer(vector<vector<int>>& matrix,int row){
        int n=matrix.size();
        int len=matrix.size()-row-1;
        
        //一次交换4个数
        //4数交换是本题的一个重点
        for(int i=row;i<len;i++){
            int tmp=matrix[row][i];
            matrix[row][i]=matrix[n-1-i][row];
            matrix[n-1-i][row]=matrix[n-1-row][n-1-i];
            matrix[n-1-row][n-1-i]=matrix[i][n-1-row];
            matrix[i][n-1-row]=tmp;
        }
    }
};