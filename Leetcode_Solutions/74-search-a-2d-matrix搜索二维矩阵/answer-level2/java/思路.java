### 解题思路
此处撰写解题思路
我的思路:
    通过二维数组的遍历，如果遍历的数组等于target的时候就直接返回true;
如果二维数组都遍历完了，那么肯定没有找到，直接返回false;;
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
    
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[i].length;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
}
```