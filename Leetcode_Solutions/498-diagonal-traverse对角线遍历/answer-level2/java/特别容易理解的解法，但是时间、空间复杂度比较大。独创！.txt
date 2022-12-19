![数组.jpg](https://pic.leetcode-cn.com/59f7b381193d1924a62fe37906acd620b56e737e36f82b3bd0b176060d1aeeca-%E6%95%B0%E7%BB%84.jpg)

class Solution {
    public static int[] findDiagonalOrder(int[][] matrix) {

        int array_length = matrix.length*matrix[0].length;
        int[] array = new int[array_length];
        int[] array1 = new int[array_length];
        int count = matrix.length+matrix[0].length-2;
        int k = 0;
        int m = 0;
        int[] array2 = new int[array.length];
        boolean flag=true;

        if((matrix == null)||(matrix.length == 0)){
            return new int[] {};
        }

        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;matrix[i]!=null&&j<matrix[i].length;j++) {
                array[k] = matrix[i][j];
                array1[k] = i+j;
                k++;
            }
        }
        /////////////////////////////////////
        for (int value = 0; value <= count; value++) {
             if(flag){
                for (int j = array1.length-1; j>=0; j--) {
                    if (array1[j] == value) {
                        array2[m] = array[j];
                        m++;
                    }
                }
                flag = false;
             }
             else{
                 for (int i = 0; i < array1.length; i++) {
                     if (array1[i] == value) {
                         array2[m] = array[i];
                         m++;
                     }
                 }
                 flag = true;
             }
        }

        return array2;
    }
}




