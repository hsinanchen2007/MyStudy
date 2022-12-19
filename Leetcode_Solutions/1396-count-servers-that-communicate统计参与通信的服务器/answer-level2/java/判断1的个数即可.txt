![100.png](https://pic.leetcode-cn.com/4407c4b588ae3bb8cd20b5c0b651079117f0d98327ad9ddacf677695da87bdd5-100.png)

1. 如果当前行中1的个数大于1, 那么所有大于1的都满足条件, 加起来
```
// flag的作用是标记最后一个为1的元素的列号
 for (int j = 0; j < grid[i].length; j++) {
    if(grid[i][j] == 1)
        flag = j;
    row += grid[i][j];
}
    if(row > 1)
        sum += row;

```

2. 如果当前行中只有1个1, 那么判断有1的那一列共有几个1, 如果1的个数大于1, 那么证明此处的1也满足条件, 为结果加1
```
 if(row == 1){
    for(int k= 0; k < grid.length; k++){
        col += grid[k][flag];
    }
}

```

源码
```
class Solution {
    public int countServers(int[][] grid) {
        int sum = 0;
        for (int i = 0; i < grid.length; i++) {

            int row = 0, col = 0, flag = 0;
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1)
                    flag = j;
                row += grid[i][j];
            }
            if(row > 1)
                sum += row;
            if(row == 1){
                for(int k= 0; k < grid.length; k++){
                    col += grid[k][flag];
                }
            }
            if(col > 1)
                sum += 1;
        }
        return sum;
    }
}
```
