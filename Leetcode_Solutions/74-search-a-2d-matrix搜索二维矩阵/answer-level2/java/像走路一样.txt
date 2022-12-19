### 解题思路
左下角开始的对角线上的元素有一个特点，就是上面的元素比他小，右侧的元素比他大
所有只要target小于当前元素，那么就向上走，否则向下走，如果相等返回true 否则返回false
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int x = matrix.length-1;
        int y = 0;
        while(x>=0 && y<=matrix[0].length-1){
            if(target==matrix[x][y]){
                return true;
            }else if(target<matrix[x][y]){
                x--;
            }else{
                y++;
            }
        }
        return false;
    }
}
```