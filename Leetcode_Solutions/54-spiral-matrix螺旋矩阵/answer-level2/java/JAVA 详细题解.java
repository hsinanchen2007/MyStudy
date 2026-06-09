无图言*
![屏幕快照 2019-11-15 19.47.53.png](https://pic.leetcode-cn.com/2ed3cec5b69d76f4bea7e9d1397ff54ddbbf7a769b1c9008e59972922f55c2bc-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-15%2019.47.53.png)

按照正常思路写就好了，向右走的下一步是向下，向下走的下一步是向左，向左走的下一步是向上，向上走的下一步是向右；
```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix.length == 0) {return result;}
        int rowLength = matrix.length, colLength = matrix[0].length;
        boolean[][] processed = new boolean[rowLength][colLength];
        // 行指针，负责上下；列指针，负责左右
        int rPointer = 0, cPointer = 0;
        // 1 up  2 down  3 left  4 right
        int direction = 4;
        for (int i = 0; i < rowLength * colLength; i++) {
            result.add(matrix[rPointer][cPointer]);
            processed[rPointer][cPointer] = true;
            switch (direction){
                case 1:{
                    if(rPointer - 1 < 0 || processed[rPointer - 1][cPointer]) {
                        direction = 4;
                        cPointer++;
                    }
                    else { rPointer--; }
                    break;
                }
                case 2:{
                    if(rPointer + 1 >= rowLength || processed[rPointer + 1][cPointer]) {
                        direction = 3;
                        cPointer--;
                    }
                    else { rPointer++; }
                    break;
                }
                case 3:{
                    if(cPointer - 1 < 0 || processed[rPointer][cPointer - 1]) {
                        direction = 1;
                        rPointer--;
                    }
                    else { cPointer--; }
                    break;
                }
                case 4:{
                    if(cPointer + 1 >= colLength || processed[rPointer][cPointer + 1]) {
                        direction = 2;
                        rPointer++;
                    }
                    else { cPointer++; }
                    break;
                }
                default:{
                    break;
                }
            }
        }
        return result;
    }
}
```
