### 解题思路
*整体思路：找出网格中所有腐烂的橘子，让它们集体传播腐烂一次，就像植物大战僵尸里的喷菇，每传播一次后返回一个新的网格与原网格进行比较。
此处用了2个比较重要的方法。在假设所给网格为可以正常进行腐烂传播的情况下（非特殊网格如{{0}}，{{1}}，{{2}}）
1.containsIndex，找出所有腐烂橘子的下标，此方法返回一个map集合，集合包含自增key和网格中所有值为2的下标value
2.spreadDecay，根据所有腐烂橘子的下标进行传播腐烂，此方法返回一个传播腐烂过后的新网格，实际上就是将值为2元素的相邻1元素全部改为2
3. orangesRotting，此方法是主方法，每调用一次spreadDecay，传播次数count就自增1，当腐烂可以扩散整个网格时，网格中不再含有1，while循环结束，返回传播的次数.
4. 当腐烂无法扩散至整个网格时，spreadDecay方法返回的网格和原网格是一致的，且网格中必含有1，触发if判定条件，返回-1
5. 补丁说明：因为题意在某些情况下有冲突，传播了0次和无法传播在逻辑上有重复的地区，比如输入{{0，1}}，既可以认为是无法传播，也可以认为传播了0次，为了题意统一，所以在进入while循环前加入了一个特殊情况的补丁
### 代码

```java
class Solution {
      public int orangesRotting(int[][] grid) {
        int count = 0;
       /*补丁：判断特殊情形的grid(根本无法开始传播的情形)*/
        if(!containsInt(grid,2)&&!containsInt(grid,1)){
            /*当只包含0，无法传播，返回0*/
            return 0 ;
        }else if(!containsInt(grid,0)&&!containsInt(grid,2)){
            /*只包含1，相当于有无法传播的角落，返回-1*/
            return -1 ;
        }else  if(!containsInt(grid,2)){
            /*只包含0和1，相当于有无法传播的角落，返回-1*/
            return -1;
        }
        /*如果网格中包含2和1，那么才有传播腐烂的可能*/
        while (containsInt(grid, 2) && containsInt(grid, 1)) {
            /*开始传播腐烂*/
            int[][] Cgrid = spreadDecay(grid);
            count++;
            /*如果传播腐烂后的网格和原网格一样，那么代表腐烂已经不能再传播了*/
            /*当网格中还有好的橘子时*/
            if (equals(Cgrid, grid) && containsInt(Cgrid, 1)) {
                return -1;
            }
            /*如果程序能走到这里，说明还能继续传播腐烂，将grid进行迭代*/
            grid = Cgrid;
        }
        return count;
    }


    public int[][] inverse(int[][] grid) {
        int[][] Iarray = new int[3][3];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                Iarray[j][i] = grid[i][j];
            }
        }
        return Iarray;
    }

    public void PrintArray(int[][] grid) {
        for (int[] a : grid) {
            System.out.println(Arrays.toString(a));
        }
    }

    public int[][] spreadDecay(int[][] grid) {
        /*遍历获得的map,获得腐烂橘子的下标*/
        /*对原gird进行深拷贝*/
        int [][] ipgrid = new int[grid.length][grid[0].length];
        for (int i = 0; i <grid.length ; i++) {
            ipgrid[i] = grid[i].clone();
        }
        Map<Integer, Map<Integer, Integer>> Maps = containsIndex(ipgrid, 2);
        if (!Maps.isEmpty()) {
            Set<Integer> integers = Maps.keySet();
            Iterator<Integer> iterator = integers.iterator();
            while (iterator.hasNext()) {
                /*拿出大Maps中小integermap*/
                Map<Integer, Integer> integerMap = Maps.get(iterator.next());
                /*再从小的map中拿出i，j*/
                Set<Integer> key = integerMap.keySet();
                Iterator<Integer> iterator1 = key.iterator();
                int i = iterator1.next();
                int j = integerMap.get(i);
                /*向四个方向传播腐烂*/
                /*1.向上*/
                if (ipgrid[i][j] == 2 && i > 0) {
                    if (ipgrid[i - 1][j] == 1) {
                        ipgrid[i - 1][j] = 2;
                    }
                }
                /*2.向下*/
                if (ipgrid[i][j] == 2 && i < ipgrid.length - 1) {
                    if (ipgrid[i + 1][j] == 1) {
                        ipgrid[i + 1][j] = 2;
                    }
                }
                /*3.向左*/
                if (ipgrid[i][j] == 2 && j != 0) {
                    if (ipgrid[i][j - 1] == 1) {
                        ipgrid[i][j - 1] = 2;
                    }
                }
                /*4.向右*/
                if (ipgrid[i][j] == 2 && j < ipgrid[i].length - 1) {
                    if (ipgrid[i][j + 1] == 1) {
                        ipgrid[i][j + 1] = 2;
                    }
                }
            }
        }
        return ipgrid;
    }

    public boolean containsInt(int[][] grid, int number) {
        for (int[] a : grid) {
            for (int element : a) {
                if (element == number) {
                    return true;
                }
            }
        }
        return false;
    }

    public Map<Integer, Map<Integer, Integer>> containsIndex(int[][] grid, int number) {
        /*返回带有指定数字的所有下标的map集合*/
        int count = 0 ;
        Map<Integer, Map<Integer, Integer>> Maps = new HashMap<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == number) {
                    Map<Integer, Integer> IndexMap = new HashMap<>();
                    IndexMap.put(i, j);
                    Maps.put(count,IndexMap);
                    count ++ ;
                }
            }

        }
        return Maps;
    }
    public boolean equals(int[][] gird,int[][]Cgrid){
        for (int i = 0; i <gird.length ; i++) {
            if (!Arrays.equals(gird[i],Cgrid[i])){
                return false;
            }
        }
        return  true;
    }
}
```