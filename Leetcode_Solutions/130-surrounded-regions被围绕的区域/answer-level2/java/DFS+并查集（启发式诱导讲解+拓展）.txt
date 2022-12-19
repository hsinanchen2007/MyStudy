#### Problem

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
	    X O O X
		X X O X
		X O X X

After running your function, the board should be:

X X X X
		X X X X
		X X X X
		X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

#这是图连通问题中的重点问题，类似的问题总结欢迎关注我的博客https://blog.csdn.net/qq_21515253
#本题题解及更深层的剖析也发布在了https://blog.csdn.net/qq_21515253/article/details/99703065，欢迎交流

本质上，这是一个规则的矩形图。

### 1、结点构造

首先我们先表示每个顶点

（1）2维矩阵中每个点表示为（i，j）的形式，我们可以通过**i * 列数 + j**使其变为唯一的一维数

（2）**新建一个Node类**

*以java为例，需要重写euqals等*

```java
class Node {
    private int i;
    private int j;
    
    public Node(int i, int j) {
        this.i = i;
        this.j = j;
    }
    
    @Override
    public int hashCode() {
        return i + j;
    }
    
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Node) {
            return ((Node) obj).getI() == i && ((Node) obj).getJ() == j;
        }
        return false;
    }
    
    public int getI() {
        return i;
    }
    
    public int getJ() {
        return j;
    }
}
```

**显然，方法一简单，方法二效率略低但表示更明确，适用于更复杂结点的问题**

本例采用（1）更好



### 2、边构造

对于图的边搭建一般有两种

（1）一种是经典的邻接矩阵、邻接链表一类的。

以

X O 
		X X

为例，

表示为NODE(0,0)--NODE(1,0)		NODE(1,0)--NODE(1,1)的无向图

（2）本题由于是规则的矩形图，其邻接范围无非上、下、左、右，因此对边的描述可以简化



**其实上面都不是重点**

### 3、策略

现在我们来分析一下这道题的核心策略。

被‘X'包围的’O‘，即对所有的'O'判断是否周围被'X’环绕。

但是，这是一个极其复杂的问题，搜索复杂度与O的数量以及矩阵大小密切相关。

不妨换个思路，是不是找出不被‘X’环绕的'O'呢？？

其实不难发现，不被'X'环绕的‘O’必与边界的‘O’连通，也就是说我们只需从边界的'O'进行搜索即可，问题也就变的简单了。

搜索策略自然很容易想到bfs、dfs之类的，当然并查集也是一种不错的方法。

#### 1、DFS

从边界的'O'出发，向上、下、左、右搜索，如果遇到’O'，进一步搜索，且标记该'O‘即可。

边界及与边界的连通点标记为’#‘，剩下的'O'为被'X'环绕。

此时剩下'O'变为’X‘，’#‘变为’O'，即可完成。

```java
class Solution {
    //存放二维矩阵（区域）
    private char[][] board;
    
    public void solve(char[][] board) {
        this.board = board;
        
        if (board == null || board.length == 0) {
            return;
        }
        
        //从边界dfs
        for (int i = 0; i < board.length; i++) {
            if (board[i][0] == 'O') {
                search(i, 0);
            }
            if (board[i][board[0].length - 1] == 'O') {
                search(i, board[0].length - 1);
            }
        }
        
        for (int j = 0; j < board[0].length; j++) {
            if (board[0][j] == 'O') {
                search(0, j);
            }
            if (board[board.length - 1][j] == 'O') {
                search(board.length - 1, j);
            }
        }
        
        //转变
        for (int i = 0; i < this.board.length; i++) {
            for (int j = 0; j < this.board[0].length; j++) {
                if (this.board[i][j] == 'O') {
                    this.board[i][j] = 'X';
                }
                if (this.board[i][j] == '#') {
                    this.board[i][j] = 'O';
                }
            }
        }
    }
    
   private void search(int i, int j) {
        if (i < board.length && i >= 0 && j >= 0 && j < board[0].length && board[i][j] == 'O') {
            board[i][j] = '#';
            //事实上，只需向下和向右搜索
            search(i + 1, j);
            search(i - 1, j);
            search(i, j + 1);
            search(i, j - 1);
        }
    }
}
```

#### 2、Union-Find

首先，什么是并查集？

**并查集**是一种树型的数据结构，用于**处理一些不交集（Disjoint Sets）的合并及查询问题**。有一个**联合-查找算法**（**union-find algorithm**）定义了两个用于此数据结构的操作：

- **Find**：**确定元素属于哪一个子集**。这个**确定方法就是不断向上查找找到它的根节点**，它可以**被用来确定两个元素是否属于同一子集**。

- **Union**：**将两个子集合并成同一个集合**。

  具体可以参见算法书或者https://www.cnblogs.com/MrSaver/p/9607552.html本博文



**在这里给出并查集的java表示，采用了高效的路径压缩。**

```java
//Node类参照上文
class UnionFind {
    HashMap<Node, Node> parent = new HashMap<>();
    HashMap<Node, Integer> size = new HashMap<>();
    
    public void union(Node node1, Node node2) {
        if (!parent.containsKey(node1)) {
            parent.put(node1, node1);
            size.put(node1, 1);
        }
    
        if (!parent.containsKey(node2)) {
            parent.put(node2, node2);
            size.put(node2, 1);
        }
        
        Node root1 = find(node1);
        Node root2 = find(node2);
        if (root1.equals(root2)) {
            return;
        }
        if (size.get(root1) < size.get(root2)) {
            size.put(root2, size.get(root1) + size.get(root2));
            parent.put(root1, root2);
        } else {
            size.put(root1, size.get(root1) + size.get(root2));
            parent.put(root2, root1);
        }
    }
    
    public Node find(Node node) {
        if (!parent.containsKey(node)) {
            parent.put(node, node);
        }
        while (!node.equals(parent.get(node))) {
            node = parent.get(node);
        }
        return node;
    }
    
    public boolean connected(Node node1, Node node2) {
        return find(node1).equals(find(node2));
    }
}
```



使用并查集可以找到与边界‘O’连通的所有‘O’。

**方法很简单，采用虚拟点的思想来降低算法复杂度。**

即把边界点与一个虚拟点连一起，与边界点连通的点与边界点相连，即所有非'X'环绕点都与一个虚拟点相连

```java
class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        UnionFind uf = new UnionFind();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == board.length - 1 || j == 0 || j == board[0].length - 1) {
                        uf.union(new Node(i, j), new Node(-1, -1));
                    } else {
                        if (i > 0 && board[i - 1][j] == 'O')
                            uf.union(new Node(i, j), new Node(i - 1, j));
                        if (i < board.length - 1 && board[i + 1][j] == 'O')
                            uf.union(new Node(i, j), new Node(i + 1, j));
                        if (j > 0 && board[i][j - 1] == 'O')
                            uf.union(new Node(i, j), new Node(i, j - 1));
                        if (j < board.length - 1 && board[i][j + 1] == 'O')
                            uf.union(new Node(i, j), new Node(i, j + 1));
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (uf.connected(new Node(i, j), new Node(-1, -1))) {
                    // 和dummyNode 在一个连通区域的,那么就是O；
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    
    }
}
```

但是据我所知，此方法无法通过leetcode上的最后一个case，理由是超时。

考虑构造点的问题，我们改用了简单的构造方法，通过了测试。

```java
class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        UnionFind uf = new UnionFind();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == board.length - 1 || j == 0 || j == board[0].length - 1) {
                        uf.union(i * board[0].length + j, -1);
                    } else {
                        if (i > 0 && board[i - 1][j] == 'O')
                            uf.union(i * board[0].length + j, (i - 1) * board[0].length + j);
                        if (i < board.length - 1 && board[i + 1][j] == 'O')
                            uf.union(i * board[0].length + j, (i + 1) * board[0].length + j);
                        if (j > 0 && board[i][j - 1] == 'O')
                            uf.union(i * board[0].length + j, i * board[0].length + j - 1);
                        if (j < board.length - 1 && board[i][j + 1] == 'O')
                            uf.union(i * board[0].length + j, i * board[0].length + j + 1);
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (uf.connected(i * board[0].length + j, -1)) {
                    // 和dummyNode 在一个连通区域的,那么就是O；
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
}

class UnionFind {
    HashMap<Integer, Integer> parent = new HashMap<>();
    HashMap<Integer, Integer> size = new HashMap<>();
    
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
        } else {
            size.put(root1, size.get(root1) + size.get(root2));
            parent.put(root2, root1);
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
}
```



