### 解题思路
左下角的点
1. 向上是逐渐变小
2. 向右是逐渐变大
3. 向上和向右的合理分配，可以到达矩阵上的每一个点

我们可以用反证法证明算法的正确性
假设这种方案行不通
那么存在点（i,j），我们无法抵达
也就是说我们无法抵达（i+1，j）和（i，j-1） 因为我们一旦抵达这两个点，通过和target比较，向上或者向右一步就可以抵达target
无法抵达（i+1，j） 意味着 我们无法抵达 （i+2，j）和（i+1，j-1）
无法抵达（i，j-1） 意味着 我们无法抵达 （i+1，j-1）和（i，j-2）
。。。。。。
按照这种思维 我们发现我们无法到达我们规定的起点（左下角点）
这显然是相矛盾的，因此算法正确。

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0)
            return false;
        int i = matrix.length - 1;
        int j = 0;
        while (i >= 0  && j < matrix[0].length){
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target){
                i--;
            }
            else if (matrix[i][j] < target){
                j++;
            }
        }
        return false;
    }
}
```