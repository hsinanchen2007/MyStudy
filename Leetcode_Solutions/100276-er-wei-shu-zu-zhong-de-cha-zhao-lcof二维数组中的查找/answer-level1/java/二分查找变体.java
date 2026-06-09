    //从右上角开始查找
    //比target大往左走
    //比target小往下走
    //等于target返回true
    //走出去了都没找到返回false

    class Solution {
        public boolean findNumberIn2DArray(int[][] matrix, int target) {
            int height = matrix.length;
            int width = matrix[0].length;
            int n = width - 1;
            int m = 0;
            while(n >= 0 && m <height){
                if(matrix[m][n] > target){
                    n--;
                } else if(matrix[m][n] < target){
                    m++;
                } else {
                    return true;
                }
            }
            return false;
        }
    }

    //也可以从左下角开始查找

![f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg](https://pic.leetcode-cn.com/efbb67b33c890b393a67ca0d6e7db0607b607f15bb65b3a5d62f1a87dd88a51b-f8bf7751239b0869da5331e574654d3876f9cd33.jpg@518w_1e_1c.jpg)
