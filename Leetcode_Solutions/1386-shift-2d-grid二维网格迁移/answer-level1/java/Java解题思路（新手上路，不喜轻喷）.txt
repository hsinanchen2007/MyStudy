### 解题思路
借助两个int数实现存储和交换，第一重循环是控制迁移次数的，然后用交换数buy存放数组最后一个元素的值，后面两个for是为了遍历整个数组，循环中间实现元素的交换；
最后一部分将数组转化成List

### 代码

```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int buy,cunchu;
        for(;k>0;k--){
            buy=grid[grid.length-1][grid[0].length-1];
            for(int i = 0;i<grid.length;i++){
                for(int j = 0;j<grid[0].length;j++){
                    cunchu=grid[i][j];
                    grid[i][j]=buy;
                    buy=cunchu;
                }
            }
        }
        List<List<Integer>> r = new ArrayList<List<Integer>>();
        for(int[] gridLine:grid){
            ArrayList<Integer> g = new ArrayList<Integer>();
            for(int gridNo : gridLine){
                g.add(gridNo);
            }
            r.add(g);
        }
        return r;
    }
}
```