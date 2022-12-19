### 解题思路
由于数组中的值都是从小到大顺序排列的,可以先从最后一组首位元素开始判断,淘汰掉大于目标值的数组
剩下的就是暴力破解了,没啥技术含量,希望大佬指引个学习方向,我刚接触数据结构,好多学得懵懵懂懂的

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        
        int max = matrix.length - 1;
        while(max >= 0 && matrix[max].length > 0 && matrix[max][0] >= target){
            if(matrix[max--][0] == target){
                return true;
            }
        }

        for(int i = 0; i <= max; i++){
            for(int j = 1; j < matrix[i].length; j++){
                if (matrix[i][j] == target){
                    return true;
                }else if(matrix[i][j] > target){
                    break;
                }
            }
        }

        return false;
    }
}
```
![image.png](https://pic.leetcode-cn.com/a2e20fc7654d3c9c660f7684508eedeff1fb11d9d886b03051df14af72889508-image.png)
