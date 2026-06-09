### 解题思路
服了 每次做类似数组题 得花2个小时左右
调试好烦啊 各种情况 思维能力跟不上啊

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        //设置一个数组保存行数是否出现0
        int[] rowZero = new int[matrix.length];

        //保存列的数据 是否遍历过
        boolean[] col = new boolean[matrix[0].length];

        //保存整行的数据的相应的0位置
        int[]     zeroIndex = new int[matrix[0].length];

        //遍历矩阵
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {     
                if (matrix[i][j] == 0 && !col[j]) {//找到0的值 保存为0的数组
                    zeroIndex[j] = 1;
                }
            }

            //循环为0的数组
            boolean flag = false;
            for (int k = 0; k < matrix[0].length; k++) {
                if (zeroIndex[k] == 1) {
                    //重置索引值为初始化
                    zeroIndex[k] = 0;
                    if (rowZero[i] == 1) {//行重置
                        for (int n = 0;  n < matrix[0].length; n++) { 
                            matrix[i][n] = 0;
                        }
                        flag = true;
                    }
                    if (!col[k]) {//列没有被重置过
                        for (int l = 0; l < matrix.length; l++) {
                            if (matrix[l][k] == 0) {//是否出现0
                               rowZero[l] = 1;
                            } else {
                               matrix[l][k] = 0;
                            }             
                            col[k] = true;//做标记
                        }
                    }
                } 
            }

            if (rowZero[i] == 1) {//如果此行有0值
                for (int n = 0;  n < matrix[0].length; n++) { 
                    matrix[i][n] = 0;
                }
            }
        }
    }
}
```