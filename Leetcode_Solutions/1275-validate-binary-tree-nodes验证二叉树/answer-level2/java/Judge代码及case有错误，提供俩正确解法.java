#### 一、错误

judge代码及case有问题，只判断了父亲的数量，即：有且只有1个节点的入度数为0，其余节点的入度数都是1。

对于单个连通域上述判断已经足够了（本题不考虑多叉树），但对于多个连通域时的某些情况就跪了：只有一棵是树，其他连通域所有节点入度数都是1。

如下图把样例4稍作修改，使其满足上述的入度数判断，但明显不是**一棵**树，但judge代码给出的结果却是true。。emmm。。。*（2020-02-27）*
![image.png](https://pic.leetcode-cn.com/4f00a4128721cfb6a55281ebdef77e699c4c7496ae89df02ff024181afbe32f6-image.png){:height="60%" width="60%"}




#### 二、正解
所以，正确的解法还需要判断一下连通域的数目，本文提供两个可行方案。
##### 1、DFS/BFS
1. 先通过统计各个节点的入度数，排除不满足上述入度数判断的情况。（目前Judge代码和case只做到了这里，所以只能判断出一部分多连通域是错的）
2. 再从root开始扫一遍（下面我用的是dfs）之后判断是否所有的节点都被访问过。

##### 2、并查集
1. 不需要先统计入度数和找root了，对孩子节点和父亲节点进行合并之前先判断一下：
    * 该孩子节点是否已经有父亲了（不能有多个父亲）; 
    * 该孩子节点与父亲节点是否已经在一个连通域中（不能有环）。
2. 都合并完后判断一下连通域的数量。 



##### DFS
``` Java
class Solution {
    int[] leftChild, rightChild;
    boolean[] visited;
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        // 统计每个结点的父亲数：1. 若父亲数大于1则为false  2.若父亲数等于0的不是1个则为false
        int[] indegreeCnt = new int[n];
        for (int i = 0; i < n; i++) {
            if((leftChild[i] != -1 && ++indegreeCnt[leftChild[i]] > 1)
             || (rightChild[i] != -1 && ++indegreeCnt[rightChild[i]] > 1)) {
                return false;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++){
            if (indegreeCnt[i] == 0) {
                if (root != -1) {
                    return false;
                }
                root = i;
            }
        }

        // 上面的判断可以解决单个连通域的树判断、及部分多连通域情况
        // 例如下面的情况无法判断，需要再判断连通域的个数。从root一遍dfs之后，若存在结点未被访问说明多个连通域。
        // 1 <--- 0 <--->  2， 4 --->3
        this.leftChild = leftChild;
        this.rightChild = rightChild;
        visited = new boolean[n];
        dfs(root);
        for (boolean v: visited) {
            if (!v) {
                return false;
            }
        }
        return true;     
    }

    private void dfs(int v) { 
        if (v == -1) {
            return;
        }       
        visited[v] = true;
        dfs(leftChild[v]);
        dfs(rightChild[v]);
    }
}

```


##### 并查集
``` Java
class Solution {
    
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        UnionFind uf = new UnionFind(n);
        
        for (int i = 0; i < n; i++) {
            // 若i节点的孩子节点之前已经有父亲了，则false
            // 若i节点和孩子节点已经在同一个连通域里了，说明形成了环，则fasle
            if (leftChild[i] != -1) {
                if (uf.find(leftChild[i]) != leftChild[i] || uf.connected(i, leftChild[i])) {
                    return false;  
                }           
                uf.union(i, leftChild[i]);
            }

            if (rightChild[i] != -1) {
                if (uf.find(rightChild[i]) != rightChild[i] || uf.connected(i, rightChild[i])) {
                    return false;  
                } 
                uf.union(i, rightChild[i]);
            }
        }
        // 最后判断一下连通域的数量
        return uf.size == 1;
    }
}


class UnionFind {
    int roots[];
    int size;

    public UnionFind(int n) {
        roots = new int[n];
        size = n;
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }
    }

    public int find(int i) {
        return i == roots[i]? i: (roots[i] = find(roots[i]));
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q); 
    }

    public void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot != qRoot) {
            roots[pRoot] = qRoot;
            size--;
        }    
    }

}
``` 


#### 三、最后
PS: 对于下图这种两个连通域的情况Judge代码还是能判断出来是错误的，，，因为下面的情况可以只通过统计入度数判断是否单连通域。。
![image.png](https://pic.leetcode-cn.com/eacad617708b38e71dca9a337f554b473c6985dffb843cf5db57060bdc22255a-image.png){:height="60%" width="60%"}
