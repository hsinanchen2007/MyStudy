### 解题思路
此处撰写解题思路
我的思路:
    创建一个统计的变量，然后循环外层的次数到数组的长度4，然后再来一个内层的循环，最后再判断这个二维数组中小于0的数，统计
之后，返回，就ok；
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int len=0;
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]<0){
                    len++;
                }
            }
        }
        return len;
    }
}
```