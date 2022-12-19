### 解题思路
此处撰写解题思路
我的思路:
    通过遍历寻找，如果找到了直接返回true;遍历循环完之后都没找到，就直接返回false'
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean flag=false;
        for(int i=0;i<matrix.length;i++)
        {
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