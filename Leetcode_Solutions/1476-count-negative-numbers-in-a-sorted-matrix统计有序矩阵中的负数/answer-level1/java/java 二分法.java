### 解题思路
对每一行进行二分查找
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        
        
        int cnt=0;
        for(int i=0;i<grid.length;i++){
            int left=0,right=grid[0].length-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(grid[i][mid]<0){
                    cnt+=right-mid+1;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }
        return cnt;
    }
}
```