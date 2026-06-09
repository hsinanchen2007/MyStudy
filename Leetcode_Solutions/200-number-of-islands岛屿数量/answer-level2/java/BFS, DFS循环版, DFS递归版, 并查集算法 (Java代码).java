#### 第一次做; 并查集:1)元素-boss哈希表, 2)boss-人数哈希表, 3)初始化操作,collection 4)union(), 5)find(), 注意路径压缩在哪里; union()操作中, 必须通过findBoss()找某个元素的boss!; 核心:1)只需向右和向下遍历; 2)将所有的水域通过虚拟节点连接在一起
```java
/*
并查集Union Find
*/
import java.util.HashMap;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Collection;

class Solution {
    public int numIslands(char[][] grid) {
        if(grid==null || grid.length==0 || grid[0].length==0)
            return 0;
        int rows = grid.length, cols = grid[0].length;
        /*
        1.如果当前是 “陆地”，尝试与周围合并一下”，此时 “周围” 并不需要像 “深度优先遍历” 和 “广度优先遍历” 一样，方向是四周。事实上，只要 “向右”、“向下” 两个方向就可以了
        2.需要给水域设置一个虚拟节点, 否则会出问题, 看下面的例子, 第二行第三个0自成一派, 这样就不能保证门派中只有一个水域, 所以应该让所有的水域成一派
        11110
        11010
        11100
        00000
        */
        ArrayList<Coor> al = new ArrayList<>();
        Coor[][] coors = new Coor[rows][cols];
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                Coor co = new Coor(i, j);
                al.add(co);
                coors[i][j] = co;
            }
        }
        //虚拟水域节点
        Coor water = new Coor(-1,-1);
        //将虚拟节点加入记录
        al.add(water);
        UnionFind uf = new UnionFind();
        uf.initialize(al);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    //right
                    if(isValid(grid, i, j+1) && grid[i][j+1]=='1')
                        uf.union(coors[i][j], coors[i][j+1]);
                    //down
                    if(isValid(grid, i+1, j) && grid[i+1][j]=='1')
                        uf.union(coors[i][j], coors[i+1][j]);
                }
                else{
                    uf.union(coors[i][j], water);
                }
            }
        }
        return uf.count()-1;
        
    }
    public boolean isValid(char[][] grid, int i, int j){
        return i>=0 && i<grid.length && j>=0 && j<grid[0].length;
    }
    
    public class UnionFind{
        //记录元素的掌门人
        private HashMap<Coor, Coor> bossMap;
        //记录门派的人数: 用于Union操作中, 让人数少的门派加入到人数多的门派
        private HashMap<Coor, Integer> countMap;
        UnionFind(){
            bossMap = new HashMap<>();
            countMap = new HashMap<>();
        }
        //初始化操作, 每个元素自成一派
        public void initialize(Collection<Coor> coors){
            bossMap.clear();
            countMap.clear();
            for(Coor co : coors){
                bossMap.put(co, co);
                countMap.put(co, 1);
            }
        }
        //返回门派数量
        public int count(){
            return countMap.size();
        }
        //Union操作
        public void union(Coor a, Coor b){
            //input check
            if(a==null || b==null)
                return;
            //获取掌门
            /*
            核心: 不能通过bossMap找a的boss, 只能通过findBoss找a的boss, 因为bossMap中的key,value可能不正确, bossMap的value只能通过findBoss()更新, 没有用到findBoss()一定会出错
            (5,3)的boss变成了(5,2), 但是此时boosMap中(5,3)的value依然是(5,3), 等下一次findBoss()途径(5,3)的时候会把boosMap中(5,3)的value改成正确的;  
            最后一个节点怎么办? 最后一个节点没有下一次了... 没有关系, 因为最后一个节点不会进入到该函数, 已经没有可以跟最后一个节点进行合并的节点了
            */
            
            Coor aBoss = findBoss(a);
            Coor bBoss = findBoss(b);
            //两个掌门不同的话,才需要合并
            if(aBoss != bBoss){
                int aCount = countMap.get(aBoss);
                int bCount = countMap.get(bBoss);
                if(aCount<=bCount){
                    //因为门派人数少, 导致本来是大哥, 现在成了小弟
                    bossMap.put(aBoss, bBoss);
                    //更新门派人数
                    countMap.put(bBoss, aCount + bCount);
                    //aBoss不再是掌门, 删除其对应门派的人数记录
                    countMap.remove(aBoss);
                }
                else{
                    bossMap.put(bBoss, aBoss);
                    countMap.put(aBoss, aCount + bCount);
                    countMap.remove(bBoss);
                }
            }
        }
        //Find操作
        public boolean isSameGang(Coor a, Coor b){
            return bossMap.get(a) == bossMap.get(b);
        }
        //循环版
        private Coor findBoss(Coor co){
            //findBoss中之所以用栈, 是为了路径压缩! 可以加速Find操作
            Stack<Coor> s = new Stack<>();
            //如果当前元素不是掌门(掌门的表现形式是什么? 在bossMap中,key和value一样的是掌门)
            while(co != bossMap.get(co)){
                s.push(co);
                co = bossMap.get(co);
            }
            //路径压缩, 让树更扁
            while(!s.isEmpty()){
                bossMap.put(s.pop(), co);
            }
            return co;
        }
    }
    public class Coor{
        int x;
        int y;
        Coor(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
```

#### 第一次做; 深度优先遍历(递归版)
```java
/*
深度优先遍历:循环+栈, 栈不为空时
还有个递归版
*/
import java.util.Stack;

class Solution {
    public int numIslands(char[][] grid) {
        if(grid==null || grid.length==0 || grid[0].length==0)
            return 0;
        int rows=grid.length, cols=grid[0].length;
        boolean[][] flag = new boolean[rows][cols];
        int res = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                res += dfs(flag, grid, i, j);
            }
        }
        return res;
    }
    /*
    深度优先遍历的核心目的是为了扩张土地
    */
    public int dfs(boolean[][] flag, char[][] grid, int i, int j){
        //坐标是否越界
        if(!isValid(grid, i, j))
            return 0;
        //是否访问过该坐标
        if(flag[i][j]==true)
            return 0;
        //改坐标是否表示水域
        if(grid[i][j]=='0')
            return 0;
        //dfs
        flag[i][j]=true;
        //up
        if(expand(flag, grid, i -1, j)){
            //新条件新递归
            dfs(flag, grid, i-1, j);
        }
        //down
        if(expand(flag, grid, i+1, j)){
            //新条件新递归
            dfs(flag, grid, i+1, j);
        }
        //left
        if(expand(flag, grid, i, j-1)){
            dfs(flag, grid, i, j-1);
        }
        //right
        if(expand(flag, grid, i, j+1)){
            dfs(flag, grid, i, j+1);
        }
        return 1;
    }
    //判断(i,j)能否成为带扩张的土地
    public boolean expand(boolean[][] flag, char[][] grid, int i, int j){
        return isValid(grid,i,j) && !flag[i][j] && grid[i][j]=='1';
    }
    public boolean isValid(char[][] grid, int i, int j){
        return i>=0 && i<grid.length && j>=0 && j<grid[0].length;
    }
}
```

#### 第一次做; 深度优先遍历(循环版): 循环+栈, 栈不为空时...
```java
/*
深度优先遍历:循环+栈, 栈不为空时
还有个递归版
*/
import java.util.Stack;

class Solution {
    public int numIslands(char[][] grid) {
        if(grid==null || grid.length==0 || grid[0].length==0)
            return 0;
        int rows=grid.length, cols=grid[0].length;
        boolean[][] flag = new boolean[rows][cols];
        int res = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                res += dfs(flag, grid, i, j);
            }
        }
        return res;
    }
    public int dfs(boolean[][] flag, char[][] grid, int i, int j){
        //坐标是否越界
        if(!isValid(grid, i, j))
            return 0;
        //是否访问过该坐标
        if(flag[i][j]==true)
            return 0;
        //改坐标是否表示水域
        if(grid[i][j]=='0')
            return 0;
        //dfs
        Stack<Coordinate> s = new Stack<>();
        s.push(new Coordinate(i,j));
        while(!s.isEmpty()){
            Coordinate curr = s.pop();
            //up
            if(expand(flag, grid, curr.x -1, curr.y)){
                flag[curr.x-1][curr.y]=true;
                //dfs的核心1: 将curr重新压栈
                s.push(curr);
                //再将新的坐标压栈
                s.push(new Coordinate(curr.x-1, curr.y));
                //dfs的核心2: 找到向某一方向延伸的道路后直接continue, 不再考虑其他方向的延伸
                continue;
            }
            //down
            if(expand(flag, grid, curr.x+1, curr.y)){
                flag[curr.x+1][curr.y]=true;
                s.push(curr);
                s.push(new Coordinate(curr.x+1, curr.y));
                continue;
            }
            //left
            if(expand(flag, grid, curr.x, curr.y-1)){
                flag[curr.x][curr.y-1]=true;
                s.push(curr);
                s.push(new Coordinate(curr.x, curr.y-1));
                continue;
            }
            //right
            if(expand(flag, grid, curr.x, curr.y+1)){
                flag[curr.x][curr.y+1]=true;
                s.push(curr);
                s.push(new Coordinate(curr.x, curr.y+1));
                continue;
            }
        }
        return 1;
    }
    //判断(i,j)能否成为带扩张的土地
    public boolean expand(boolean[][] flag, char[][] grid, int i, int j){
        return isValid(grid,i,j) && !flag[i][j] && grid[i][j]=='1';
    }
    public boolean isValid(char[][] grid, int i, int j){
        return i>=0 && i<grid.length && j>=0 && j<grid[0].length;
    }
    public class Coordinate{
        int x;
        int y;
        Coordinate(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
```

#### 第一次做; 广度优先遍历: 循环+队列, 队列不为空时...
```java
/*
三种方法:
1.广度优先遍历
2.深度优先遍历
3.并查集

先用广度优先遍历
踩坑最多的是...把char[][]中的元素当成int判断了! 得注意数据类型啊!
*/
import java.util.LinkedList;


class Solution {
    public int numIslands(char[][] grid) {
        //input check
        if (grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] flag = new boolean[rows][cols];
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res += bfs(grid, i, j, flag);
            }
        }
        return res;
    }

    public int bfs(char[][] grid, int i, int j, boolean[][] flag) {
        //坐标越界检查
        if (!isCoordinateValid(grid, i, j))
            return 0;
        //是否访问过
        if (flag[i][j] == true)
            return 0;
        //是否是水
        if (grid[i][j] == '0')
            return 0;
        //bfs
        LinkedList<Coordinate> queue = new LinkedList<>();
        queue.add(new Coordinate(i, j));
        flag[i][j] = true;
        while (!queue.isEmpty()) {
            Coordinate curr = queue.poll();
            //up; 坐标不越界,并没没有访问过
            if (expand(grid, curr.x - 1, curr.y, flag)) {
                queue.add(new Coordinate(curr.x - 1, curr.y));
                flag[curr.x - 1][curr.y] = true;
            }
            //down
            if (expand(grid, curr.x + 1, curr.y, flag)) {
                queue.add(new Coordinate(curr.x + 1, curr.y));
                flag[curr.x + 1][curr.y] = true;
            }
            //left
            if (expand(grid, curr.x, curr.y - 1, flag)) {
                queue.add(new Coordinate(curr.x, curr.y - 1));
                flag[curr.x][curr.y - 1] = true;
            }
            //right
            if (expand(grid, curr.x, curr.y + 1, flag)) {
                queue.add(new Coordinate(curr.x, curr.y + 1));
                flag[curr.x][curr.y + 1] = true;
            }
        }
        return 1;
    }

    public boolean expand(char[][] grid, int i, int j, boolean[][] flag) {
        return isCoordinateValid(grid, i, j) && !flag[i][j] && grid[i][j] == '1';
    }

    public boolean isCoordinateValid(char[][] grid, int i, int j) {
        int rows = grid.length;
        int cols = grid[0].length;
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    public class Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
```