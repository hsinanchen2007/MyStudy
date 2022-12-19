### 解题思路
双百分百
![image.png](https://pic.leetcode-cn.com/4662e3441e03ae1d53c050d510747a44b99d712825b3302ffedf4126d2473811-image.png)

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        if(grid.length==0||grid[0].length==0){
            return 0;
        }
        int len1=grid.length;
        int len2=grid[0].length;
        int i=0;
        int j=len2-1;
        int count=0;
        while(i<len1&&j>-1){
            if(grid[i][j]==0){
                int temp1=i+1;
                int temp2=j-1;
                while(temp1<len1){
                    if(grid[temp1][j]<0){
                        count++;
                    }
                    temp1++;
                }
                while(temp2>-1){
                    if(grid[i][temp2]<0){
                        count++;
                    }
                    temp2--;
                }
                i++;
                j--;
            }else if(grid[i][j]<0){
                count=count+len1-i;
                j--;
            }else{
                i++;
            }
        }
        return count;
    }
}
```