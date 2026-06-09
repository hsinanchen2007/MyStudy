### 解题思路
1.暴力遍历每一个坐标
2.发现是1就进行上下左右广度遍历，并且添加个map来记录，防止重复遍历，直到不再有1.
3.注释里已经写得很清楚了，思路普通得不能再普通，方法暴力得不能再暴力
![QQ截图20200315130424.png](https://pic.leetcode-cn.com/8435acb2846892993db5eb1fa912668618788204fc981b2cac875e989acc382d-QQ%E6%88%AA%E5%9B%BE20200315130424.png)
### 代码
```java
class Solution {
     /*1.暴力遍历数组，当发现有1时，进行广度遍历就ok，当queue为0时，继续遍历*/
    public int maxAreaOfIsland(int[][] grid) {
        /*顺序上,下，左，右*/
        int[] dr = {-1,1,0,0};
        int[] dc = {0,0,-1,1};
       int max = 0  ;
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        /*i--行，j--列 , r--行, c --列*/
        for (int i = 0 ; i<grid.length ; i++ ) {
            for (int j = 0 ; j <grid[0].length;j++) {
                int count  = 0 ;
                if (grid[i][j]==1){
                    /*一个map，防止重复遍历，用来记录已经遍历过的下标*/
                    HashMap<Integer, Integer> book = new HashMap<>();
                    /*开始进行广度遍历*/
                    /*对下标编码*/
                    int code = i*grid[0].length + j ;
                    queue.add(code);
                    book.put(code,1);
                    while (!queue.isEmpty()){
                        code = queue.pollFirst();
                        count ++ ;
                        /*对code进行解码*/
                        int c = code%grid[0].length;
                        int r = (code - c)/grid[0].length;
                        for (int n = 0 ; n <4 ; n++){
                            /*对code周边进行遍历*/
                            /*这里可能会存在越界问题,必须用if来防止越界*/
                            int ro =  r+dr[n];
                            int colu = c + dc[n];
                            code = ro*grid[0].length + colu ;
                            /*重新判断是否符合广度遍历的条件*/
                            if (ro>=0&&colu>=0&&ro<grid.length&&colu<grid[0].length&&grid[ro][colu]==1&&(!book.containsKey(code)) ){
                                /*条件成立，加入队列*/
                                queue.add(code);
                                book.put(code,1);
                            }
                        }
                    }
                }
            max = Math.max(max,count);
            }
        }
        return max;
    }
}
```