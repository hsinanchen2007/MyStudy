### 解题思路
    1,2,3
    4,5,6
    7,8,9
    step1:上下对折
    7,8,9
    4,5,6
    1,2,3
    step2:双线对角互换
         ↓7,8,9↑ 最后一轮跳过避免重复交换
    4->8 ↓4,5,6↑ 6->2
    1->9 ↓1,2,3↑ 
    

### 代码

```java
class Solution {
    /**
    解题思路：
    1,2,3
    4,5,6
    7,8,9
    step1:上下对折
    7,8,9
    4,5,6
    1,2,3
    step2:双线对角互换
        ↓7,8,9↑最后一轮跳过避免重复交换
    4->8↓4,5,6↑6->2
    1->9↓1,2,3↑
    */

    public void rotate(int[][] matrix) {

        //上下对折
        for (int i = 0; i < matrix.length / 2; i++) {
            int[] temp = matrix[i];
            matrix[i] = matrix[matrix.length - 1 - i];
            matrix[matrix.length - 1 - i] = temp;
        }
        
        //对角互换
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 0; j < i; j++) {
                if (j >= i - j) {
                    break;
                }
                int temp = matrix[i - j][j];
                matrix[i - j][j] = matrix[j][i - j];
                matrix[j][i - j] = temp;
                int length = matrix.length - 1;
                if (i == length) {
                    continue;
                }
                int temp2 = matrix[length - (i - j)][length - j];
                matrix[length - (i - j)][length - j] = matrix[length - j][length - (i - j)];
                matrix[length - j][length - (i - j)] = temp2;
            }
        }


    }
}
```