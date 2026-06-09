找规律
```java
class Solution {
	/*
     00 02 22 20
     01 12 21 10
     [
     [1,2,3],
     [4,5,6],
     [7,8,9]
     ]

     [
     [7,4,1],
     [8,5,2],
     [9,6,3]
     ]

     ij j(l-i) (l-i)(l-j) (l-j)i
     00 03 33 30
     01 13 32 20
     02 23 31 10
     11 12 22 21
     [
     [ 5, 1, 9,11],
     [ 2, 4, 8,10],
     [13, 3, 6, 7],
     [15,14,12,16]
     ]

     [
     [15,13, 2, 5],
     [14, 3, 4, 1],
     [12, 6, 8, 9],
     [16, 7,10,11]
     ]
     */
    public void rotate(int[][] matrix) {
        if (matrix.length == 1)
            return;

        for (int i = 0; i < matrix.length / 2; i++){
            for (int j = i; j < matrix[i].length - 1 - i; j++){
                int cache = matrix[i][j];
                int x = matrix[i].length - 1 - j;//(l-j)
                int y = matrix[i].length - 1 - i;//l
                matrix[i][j] = matrix[x][i];
                matrix[x][i] = matrix[y][x];
                matrix[y][x] = matrix[j][y];
                matrix[j][y] = cache;
            }
        }
    }
}

```