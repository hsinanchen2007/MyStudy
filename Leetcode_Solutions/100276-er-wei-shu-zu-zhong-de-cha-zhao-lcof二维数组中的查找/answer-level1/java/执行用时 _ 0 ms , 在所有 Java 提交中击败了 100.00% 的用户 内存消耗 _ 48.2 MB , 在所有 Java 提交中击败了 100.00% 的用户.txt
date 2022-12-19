### 解题思路
    剑指offer牛皮。后来想了下，这个题就是想让你按照二分的思路去想，所以就很容易发现不管大于还是小于都有三种情况。。。就会特别复杂

    但是从一个角上开始，就会发现 除了等于 就只有两种情况，就很容易递归。
### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null||matrix.length==0 ||matrix[0].length==0){
            return false;
        }
        if(target<matrix[0][0]||target>matrix[matrix.length-1][matrix[0].length-1]){
            return false;
        }

        int i = 0;
        int j = matrix[0].length - 1;

        while(i<matrix.length && j>=0){
            int value = matrix[i][j];
            if(value==target){
                return true;
            }else if(value<target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }

    
}

```