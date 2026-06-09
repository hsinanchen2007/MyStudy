### 解题思路
规律一：将矩阵图画下来，发现要对比的对角线元素规律是：[i, j] 与[i + 1,j + 1] 这样行列同时+1，一直到超出数组界限为止。

规律二：然后又发现，只要列出第一行和第一列，按规律一进行判断，就可以对比完所有的元素。

于是，我写了两个for循环，分别处理第一行 与 第一列的情况，只要遇到不匹配的情况就返回false。

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int l1 = matrix.length;
        int l2 = matrix[0].length;

        for(int i = 0; i < l2; i++){
            int index1 = 0, index2 = i;
            int value = matrix[0][i];
            
            while(index1 < l1 && index2 < l2){
                if(value != matrix[index1][index2]){
                    return false;
                }
                index1++;
                index2++;
            }
        }

        for(int j = 1; j < l1; j++){
            int index3 = j, index4 = 0;
            int value2 = matrix[j][0];

            while(index3 < l1 && index4 < l2){
                if(value2 != matrix[index3][index4]){
                    return false;
                }
                index3++;
                index4++;
            }
        }
        return true;

    }
}
```