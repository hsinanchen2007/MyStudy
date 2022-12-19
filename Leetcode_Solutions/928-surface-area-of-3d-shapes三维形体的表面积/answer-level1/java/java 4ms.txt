### 解题思路
这代码再优化就是 题解二 的答案了。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int vs = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                int val = grid[i][j];
                if(val == 0)
                    continue;

                int before = 0, right = 0;//只需计算两个面
                if(i < grid.length - 1)
                    right = grid[i + 1][j];
                if(j < grid[0].length - 1)
                    before = grid[i][j + 1];
                
                while(val > 0){//遍历高度，每个分开计算
                    int v = 6;  //当前体积
                    if(right >= val)
                        v -= 2; //
                    if(before >= val)
                        v -= 2;
                    if(val > 1)//down 高度
                        v -= 2;

                    vs += v;
                    val--;
                }
            } 
        }
        return vs;
    }
}
```