class Solution {
        /**
        * 根据题目描述，我们可以将 M x N 的二维数组想象转化成一个长度为m*n的顺序数组 Array[m*n] 
        */

    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = 0;
、      //判断极限情况
        if(m==0){
            return false;
        }
        n=matrix[0].length;
        if(n==0){
            return false;
        }
        return searchM(matrix,target,n,0,m*n-1);
    }
    //二分查找回调函数
    private boolean searchM(int[][] matrix,int target,int n,int begin,int end){
        //二分目标索引值
        int middle = (begin+end)/2;
        // Array[middle] 对应的值在matrix中表示为：matrix[middle/n][middle%n]
        if(matrix[middle/n][middle%n]==target){
            //找到目标值 返回true
            return true;
        }
        if(begin==end){
            return false;
        }
        //重新设置查找范围
        if(matrix[middle/n][middle%n]>target){
            end = middle-1;
        }
        else{
            begin=middle+1;
        }
        return searchM(matrix,target,n,begin,end);
    }
}