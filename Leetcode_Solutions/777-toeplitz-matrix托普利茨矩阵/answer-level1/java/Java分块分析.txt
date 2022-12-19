执行用时 :2 ms, 在所有 Java 提交中击败了98.30%的用户
内存消耗 :40.3 MB, 在所有 Java 提交中击败了95.18%的用户
【想法】
    （1）分两部分判断，上三角和下三角（下面以示例介绍想法）
    （2）上三角部分：遍历第一个子数组的元素并记录，然后内部不停进行++与记录元素对比，只要遇到一个不一样的就直接跳出循环返回false
    （3）下三角部分：从第二个子数组（因为我们把第一组的首元素归到了上三角部分）开始遍历每个子数组的第一个元素并记录，然后进行++进行对比，若遇到不相等则直接跳出循环进行返回false

```
public boolean isToeplitzMatrix(int[][] matrix) {
        int temp;
        for (int i = 0,m = 0; i < matrix[0].length; i = ++m) {
            int j = 0;
            temp = matrix[j][i];
            while (j++ < matrix.length-1 && i++ < matrix[0].length-1){
                if(matrix[j][i] != temp){
                    return false;
                }
            }
        }
        for (int i = 1,m = 0; i < matrix.length; i = ++m) {
            int j = 0;
            temp = matrix[i][j];
            while (j++ < matrix[0].length-1 && i++ < matrix.length-1){
                if(matrix[i][j] != temp){
                    return false;
                }
            }
        }
        return true;
    }

```
