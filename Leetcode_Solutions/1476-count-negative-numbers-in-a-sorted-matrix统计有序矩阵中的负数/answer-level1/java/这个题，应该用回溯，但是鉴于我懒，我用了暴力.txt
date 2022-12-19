### 解题思路
![QQ截图20200308223239.png](https://pic.leetcode-cn.com/96720e1089ed2939ed33fe5b80bd5a5321f1a4c9aaef70a9a7be9d899dbd6011-QQ%E6%88%AA%E5%9B%BE20200308223239.png)

别问，问就暴力，要问我为啥不优化？因为这波我心情不是很好，懒得优化
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
         int row=grid.length;
        int col=grid[0].length;
        int res=0;
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(grid[i][j]<0){
                    res++;
                    continue;
                }else{
                    break;
                }



            }
        }
        return res;


    }
}
```