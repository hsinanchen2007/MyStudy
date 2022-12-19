这道题我们先观察矩阵的特点：
![矩阵.png](https://pic.leetcode-cn.com/8fa467188964a20b6b9f490233189b7a3219a6bb115dd304d838647748e211e4-%E7%9F%A9%E9%98%B5.png)
我们会发现红色区域都是排序好的数字，此时以两个红色区域交集的数字作为参考对象进行比较来移动红色区域。
```java []
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length==0||matrix[0].length==0){
            return false;
        }
        int x=0;
        int y=matrix[0].length-1;
        while(x<matrix.length&&y>=0){
            if(target==matrix[x][y]){
                return true;
            }else if(target<matrix[x][y]){
                y--;
            }else{
                x++;
            }
        }
        return false;
        
    }
}
```



