### 解题思路
矩阵是个方阵，从外层向内层一圈一圈旋转，关键在于找对应边坐标之间的关系，逻辑很简单。
一的x和二的y有关系，一的y与二的x有关系。这个关系要么就是相等，要么就是加起来等于len-1.

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {

        int len = matrix.length;

        for (int level = 0; level < len / 2; level++) { // 控制当前旋转哪一层
            for (int i = level; i < len - 1 - level; i++) { // 控制当前层的开始点的y坐标
                // 矩形四条边4个对应位置的元素依次覆盖
                int temp = matrix[level][i];
                matrix[level][i] = matrix[len - 1 - i][level]; // 一的x和二的y有关系，一的y与二的x有关系，下面也一样
                matrix[len - 1 - i][level] = matrix[len - 1 - level][len - 1 - i];
                matrix[len - 1 - level][len - 1 - i] = matrix[i][len - 1 - level];
                matrix[i][len - 1 - level] = temp;
            }
        }
    }
}
```