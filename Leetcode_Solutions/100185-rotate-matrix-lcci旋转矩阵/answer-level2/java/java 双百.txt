### 解题思路
转90度类似于电风扇叶片，每次对调四个位置的值，这四个位置的关系顺时针为
i, j
j, N-1-i
N-1-i, N-1-j
N-1-j, i
另外只用遍历风扇叶片区域的值，

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int z = matrix.length;

        for (int i = 0; i < z >> 1; i++) {
            for (int j = i; j < z - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[z - j - 1][i];
                matrix[z - j - 1][i] = matrix[z - i - 1][z - j - 1];
                matrix[z - i - 1][z - j - 1] = matrix[j][z - i - 1];
                matrix[j][z - i - 1] = tmp;
            }
        }  
    }
}
```