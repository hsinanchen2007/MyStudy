看了许多大佬的解题思路确实受益匪浅，但是我这种渣渣就算是有这个思路，现场也写不出来(题目描述确实看了好久)，还是要多练练，虽热很菜。这里就分享一种暴力解法
1. 首先找到二维数组中是陆地的下标并保存起来；
2. 然后遍历数组，如果当前遍历的地方是水域，那么计算当前这个水域到每个陆地的曼哈顿距离，并且取最小的一个保存在List中(题目中说的是海洋区域到离它最近的陆地区域的距离)；
3. 遍历完毕后，对List进行排序，取最大的值(题目中说: 这个海洋区域到离它最近的陆地区域的距离是最大的)返回就ok了;
4. 虽然超时，但是我在本地的Idea中运行是没有问题的，我这种思路只是供大家去理解题意

```java
class Solution {
    public int maxDistance(int[][] grid) {
        /**
         * 保存陆地的下标
         * list = {[1,0],[0,1]}
         */
        boolean landflag = false;
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                //如果是陆地区域则保存下标
                if (grid[i][j] == 1) {
                    int[] land = {i, j};
                    list.add(land);
                    landflag = true;
                }
            }
        }
        if(landflag == false){
            return -1;
        }
        boolean waterflag = false;
        List<Integer> minList = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                //如果是海洋区域,计算它与陆地区域的距离，并且取最小值放入List中
                if (grid[i][j] == 0) {
                    int initDistance = 0;
                    for (int[] ints : list) {
                        int land_X = ints[0];
                        int land_Y = ints[1];
                        //计算当前海洋区域到陆地区域的距离
                        int distance = Math.abs(land_X - i) + Math.abs(land_Y - j);
                        if (initDistance == 0) {
                            initDistance = distance;
                        } else {
                            initDistance = Math.min(initDistance, distance);
                        }
                    }
                    //initDistance就是当前海洋区域距离最近的陆地的距离
                    minList.add(initDistance);
                    waterflag = true;
                }
            }
        }
        if(waterflag == false){
            return -1;
        }
        Collections.sort(minList);
        return minList.get(minList.size()-1);
    }
}
```
