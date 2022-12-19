### 解题思路
此处撰写解题思路
改进第一次的倒序遍历代码，减少时间复杂度
时间复杂度：O(n)
空间复杂度：O(5)
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        if(m==0)        //特判
            return 0;
        int count=0;
        int i=0,j=n-1;
        while(i<m && j>=0){     
            if(grid[i][j]<0){
                count++;
                if(j==0){       //当每一行倒序遍历完最后一个时
                    i++;        //遍历下一行
                    j=n-1;      //重置j的值
                    continue;   //跳过本次循环
                }
                j--;
            }
            else {      //因为矩阵是以非递增的顺序排列，所以当遇到的第一个值不是负数时候，剩下的也就无需遍历
                i++;        //访问下一行，j重置
                j=n-1;
            }
        }
        return count;
    }
}
```
###解题思路

倒序遍历每一行，遇到grid[i][j]<0是count+1，否则跳转到下一行继续倒序遍历
时间复杂度：O(n^2)
空间复杂度：定义了m,count,i,n,j五个变量，O(5)

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m=grid.length;
        if(m==0)
            return 0;
        int count=0;
        for(int i=0;i<m;i++){
            int n=grid[i].length;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]<0)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
}
```