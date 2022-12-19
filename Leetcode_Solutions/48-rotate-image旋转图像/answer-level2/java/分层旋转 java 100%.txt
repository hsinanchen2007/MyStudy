### 解题思路
这题解法不是很难, 感觉比较难的是怎么抽象动作,也就是方法名 
初步设计:
    将整个n*n数组的旋转 分为n/2层的旋转, 每次旋转都有Max和min边界
    将数组的索引 表示为 FirstIndex,SecondIndex
    每层的旋转分为四次操作
        1. 正方形上边旋转到右边, 则对应位置为oldSecondIndex,MAX
        2. 正方形右边旋转到下边, 则对应位置为Max, Max-oldFirstIndex
        3. 正方形下边旋转到左边, 则对应位置位置oldSecondIndex,Min
        4. 正方形左边旋转到上边, 则对应位置为min,Max-oldFirstIndex
    这里定义一个数组, 存储下一层将要填充的值, 在填充的时候, 将数组的值更换为下一层要填充的值,,这里要注意顺序, 我这里替换的顺序全都是顺时针的
看思路感觉不如直接看代码清晰........
### 代码

```java
class Solution {
     public void rotate(int[][] matrix) {
        int floor = 0;
        // 用于存储将要进行旋转的一边的值, 在替换过程中, 会把下一个要替换的边的值按照顺时针的顺序存储
        int[] tmpTable = new int[matrix.length];
        for (; floor < matrix.length / 2; floor++) {
            rotateOneFloor(matrix,floor,tmpTable);
        }
    }

    /**
     * 定义旋转一层方法
     * @param matrix
     */
    private void rotateOneFloor(int[][] matrix, int floor, int[] tmpTable){
        int max = matrix.length-1 - floor;
        int min = floor;

        /* tmpTable存储当前将要旋转的一边的值, 存储顺序是按照顺时针存储,且在旋转过程中,会将下一个边的值按顺时针存入*/
        for(int i=min; i < max; i++){
            tmpTable[i] = matrix[floor][i];
        }

        /* 按照顺时针顺序旋转, 旋转顺序不可变 */
        // 旋转上边
        rotateUpSide(matrix,max,min,tmpTable);
        // 旋转右边
        rotateRightSide(matrix,max,min,tmpTable);
        // 旋转下边
        rotateBottomSide(matrix,max,min,tmpTable);
        // 旋转左边
        rotateLeftSide(matrix,max,min,tmpTable);
    }

    /**
     * 定义旋转上边方法
     * @param matrix
     *
     */
    private void rotateUpSide(int[][] matrix,int max, int min,int[] tmpTable){
        int secondIndex = max;
        // 存储将要被替换位置的值
        int tmp = 0;
        for(int firstIndex=min;firstIndex<max;firstIndex++){
            tmp = matrix[firstIndex][secondIndex];
            matrix[firstIndex][secondIndex] = tmpTable[firstIndex];
            tmpTable[firstIndex] = tmp;
        }
    }

    /**
     * 定义旋转右边方法
     * @param matrix
     * @param floor
     */
    private void rotateRightSide(int[][] matrix, int max, int min,int[] tmpTable){
        int firstIndex = max;
        int tmp = 0;
        // 定义tmpTable有效值的起始位置
        int tableIndex = min;
        for(int secondIndex=max;secondIndex>min;secondIndex--){
            tmp = matrix[firstIndex][secondIndex];
            matrix[firstIndex][secondIndex] = tmpTable[tableIndex];
            tmpTable[tableIndex] = tmp;
            tableIndex++;
        }
    }

    /**
     * 定义旋转下边方法
     * @param matrix
     * @param floor
     */
    private void rotateBottomSide(int[][] matrix, int max, int min,int[] tmpTable){
        int secondIndex = min;
        int tmp = 0;
        int tableIndex = min;
        for(int firstIndex=max; firstIndex > min; firstIndex--){
            tmp = matrix[firstIndex][secondIndex];
            matrix[firstIndex][secondIndex] = tmpTable[tableIndex];
            tmpTable[tableIndex] = tmp;
            tableIndex++;
        }
    }

    /**
     * 定义旋转左边方法
     * @param matrix
     * @param floor
     */
    private void rotateLeftSide(int[][] matrix, int max, int min,int[] tmpTable){
        int firstIndex = min;
        int tmp = 0;
        int tableIndex = min;
        for(int secondIndex=min;secondIndex < max; secondIndex++){
            tmp = matrix[firstIndex][secondIndex];
            matrix[firstIndex][secondIndex] = tmpTable[tableIndex];
            tmpTable[tableIndex] = tmp;
            tableIndex++;
        }
    }
}
```