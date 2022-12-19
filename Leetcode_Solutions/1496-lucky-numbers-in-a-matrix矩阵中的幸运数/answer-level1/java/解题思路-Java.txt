### 解题思路
找每行的最小数，然后再找最小数所在列的最大数
两数相等，则该数为幸运数
然后找到就跑，直接break  🏃

### 代码
执行用时 :2 ms, 在所有 Java 提交中击败了95.54%的用户
内存消耗 :41.9 MB, 在所有 Java 提交中击败了100.00%的用户
_(:з」∠)_感觉没多少人写这题的说
```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        //获取行数和列数
        int rowSize = matrix.length;
        int colSize = matrix[0].length;
        //设置return的list
        List<Integer> res = new ArrayList<>();
        //循环遍历每一行
        for(int i = 0; i<rowSize;i++){
            //初始化列最大值
            int colMax = 0;
            //取行第一个数当最小值默认值
            int rowMin = matrix[i][0];
            //记录最小值所在行
            int inCol = 0;
            //循环遍历该行中所有元素，找该行最小值
            for(int j = 1; j<colSize;j++){
                if(rowMin>matrix[i][j]){
                    rowMin=matrix[i][j];
                    inCol = j;
                }
            }
            //循环遍历最小值所在列，找该列最大值
            for(int x = 0; x<rowSize;x++){
                if(colMax<matrix[x][inCol]){
                    colMax=matrix[x][inCol];
                }
            }
            //两值相比，相等就是要找的幸运数
            if(colMax==rowMin){
                res.add(rowMin);
                break;
            }
        }
        return res;
    }
}
```