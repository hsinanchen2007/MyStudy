### 解题思路
** 左下角为开始位置**
**>target** i--;
**小于target j++**

![Snipaste_2020-03-30_23-40-00.jpg](https://pic.leetcode-cn.com/64b156219afe1203305adabebe1a9e93f98520284de75ecf19b65f34a3769eed-Snipaste_2020-03-30_23-40-00.jpg)

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {//从左下角的角度去看，行递减，列递增
        int i=matrix.length-1,j=0;
        while(i>=0&&j<matrix[0].length){
            if(matrix[i][j]>target) i--;
            else if(matrix[i][j]<target) j++;
            else return true;
        }
        return false;

    }
}
```