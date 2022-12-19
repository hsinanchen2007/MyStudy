# 连通块问题的大总结请参考我的博客https://blog.csdn.net/qq_21515253/article/details/99703065
# 本人根据leetcode刷题经验做了x分享，欢迎大家指教
### Problem 

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
		Input: 
			[[1,1,0],
 			[1,1,0],
			 [0,0,1]]
		Output: 2
		Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. The 2nd student himself is in a friend circle. So return 2.

这次题目直接给的是邻接矩阵，无论是点构造，还是边构造都已经提前完成了。

本题变成了已知邻接矩阵判断连通块数量。

#### 策略一：并查集

对于此问题，使用并查集非常简单，这里直接上代码

```java
class Solution {
    public int findCircleNum(int[][] M) {
        if (M == null || M.length == 0) {
            return 0;
        }
        UnionFind uf = new UnionFind(M);
        return uf.getTop();
    }
    
}

class UnionFind {
    HashMap<Integer, Integer> parent = new HashMap<>();
    HashMap<Integer, Integer> size = new HashMap<>();
    HashSet<Integer> top = new HashSet<>();
    
    public UnionFind() {}
    
    //根据邻接矩阵，进行union
    public UnionFind(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            top.add(i);
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 1) {
                    union(i, j);
                }
            }
        }
        
    }
    
    public void union(int node1, int node2) {
        if (!parent.containsKey(node1)) {
            parent.put(node1, node1);
            size.put(node1, 1);
        }
        
        if (!parent.containsKey(node2)) {
            parent.put(node2, node2);
            size.put(node2, 1);
        }
        
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2) {
            return;
        }
        if (size.get(root1) < size.get(root2)) {
            size.put(root2, size.get(root1) + size.get(root2));
            parent.put(root1, root2);
            //top.add(root2);
            top.remove(root1);
        } else {
            size.put(root1, size.get(root1) + size.get(root2));
            parent.put(root2, root1);
            //top.add(root1);
            top.remove(root2);
        }
    }
    
    public int find(int node) {
        if (!parent.containsKey(node)) {
            parent.put(node, node);
        }
        while (!(node == (parent.get(node)))) {
            node = parent.get(node);
        }
        return node;
    }
    
    public boolean connected(int node1, int node2) {
        return find(node1) == find(node2);
    }
    
    public int getTop() {
        return top.size();
    }
}
```

#### 策略二：DFS

仍然考虑**格式化**的策略

**格式化node，就是把grid\[node][another]从1变为0，然后进一步格式化another **
		

```java
class Solution {
   
   /* 
    * 对于与其他点相连通的i，进行dfs
    */
    public int findCircleNum(int[][] grid) {
        int circleNum = 0;
        int len = grid.length;
        for(int i = 0 ; i < len; i++){
            for(int j = 0; j < len ;j++){
                if(grid[i][j] == 1){
                    circleNum++;
                    dfs(grid,i);
                }
            }
        }
        return circleNum;
    }
    
    /*
     * 搜索+格式化
     */
    public void dfs(int[][] grid, int x){
        int len = grid.length;
        grid[x][x] = 0;
        for(int i=1;i<len;i++){
            if(grid[x][i]==1){
                grid[x][i] = 0;
                grid[i][x] = 0;
                dfs(grid,i);
            }
        }
    }
}
```

当然，上述代码虽然清晰，但累赘。

### **我们可以考虑dfs常用的visited数组的策略去保证对每个node进行dfs，降低时间复杂度。**

```java
class Solution {
   private boolean[] visited;
    private int[][] visitMa;
    
    public int findCircleNum(int[][] M) {
        if (M == null || M.length == 0) {
            return 0;
        }
        visitMa = M;
        int length = visitMa.length;
        int count = 0;
        visited = new boolean[length];//访问标志
        
        //与上述代码复杂度相比，大大降低，因为visited数组的使用
        for(int i = 0;i < length;i++){
            if(visited[i] == false){			//如果未被访问
                DFS(i);				//深度优先搜索
                count++;			//朋友圈个数+1
            }
        }
        return count;
    }
    
    //深度优先搜索
    public void DFS(int i){
        visited[i] = true;
        for(int j = 0;j < visitMa.length;j++){
            if(visited[j] == false && visitMa[i][j] == 1){
                DFS(j);
            }
        }
    }
}
```

