### 解题思路
此处撰写解题思路
我的思路:
    通过双层循环判断是否存在这个target的值，如果存在用布尔类型的变量记录下来，直接跳出循环
然后再外层循环里面判断记录下来的是否为真,如果为真继续跳出循环，
最后直接返回这个布尔类型变量;
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean flag=false;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[i].length;j++){
                if(matrix[i][j]==target){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        return flag;
    }
}
```