
从总体思考：相当于向右移动k%m列；另mod=k%m,donw=k/m。则如果mod为0，则所有列都下移donw行。否则，前mod列移动donw+1行，后面的向下移动donw行。

代码上实现如下：向右`tmp[i][(j+k)%grid[0].length]=grid[i][j];`，向下`grid[(i+downTimes)%grid.length][j]=tmp[i][j];`。
这样避免实际根据k一个一个移动，时间复杂度为O(N*M)。
```java
public List<List<Integer>> shiftGrid(int[][] grid, int k) {
    int[][] tmp=new int[grid.length][grid[0].length];
    for (int i = 0; i < grid.length; i++) {//每行都向右移动k个单位
        for (int j = 0; j < grid[0].length; j++) {
            tmp[i][(j+k)%grid[0].length]=grid[i][j];
        }
    }
    //向下的列数
    int donw=k/grid[0].length;
    int mod=k%grid[0].length;
    for (int i = 0; i < grid.length; i++) {
        for (int j = 0; j < grid[0].length; j++) {
            int downTimes=donw;
            if(j<mod){
                downTimes++;
            }
            grid[(i+downTimes)%grid.length][j]=tmp[i][j];
        }
    }
    //转化为输出要求的格式
    List<List<Integer>> res=new ArrayList<>(grid.length);
    for (int i = 0; i < grid.length; i++) {
        List<Integer> list=new ArrayList<>(grid[0].length);
        for (int j = 0; j < grid[0].length; j++) {
            list.add(grid[i][j]);
        }
        res.add(list);
    }
    return res;
}
```