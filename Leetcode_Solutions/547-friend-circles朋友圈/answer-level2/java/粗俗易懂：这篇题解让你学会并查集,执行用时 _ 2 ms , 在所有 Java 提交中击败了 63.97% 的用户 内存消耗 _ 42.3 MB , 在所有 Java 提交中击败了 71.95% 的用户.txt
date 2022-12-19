```
class Solution {
    // 内部类实现一个并查集，关于并查集的学习，我这里有一片博客讲的很明白的，还不太了解或者忘记并查集的可以看下：https://blog.csdn.net/xiaolinnulidushu/article/details/104123088
    class unionFind{
        private int[] parent;
        private int[] rank;

        public unionFind(int size){
            this.parent = new int[size];
            this.rank = new int[size];
            for (int i = 0; i < size; i++){
                parent[i] = -1; // 初始用-1来表示，这样在最后所有元素合并完之后，还为-1的就是一个集合的根节点
                rank[i] = 1;
            }
        }

        // 更新到每个节点都指向根节点
        public int find(int p){
            if (parent[p] == -1) return p; // 如果p的父节点是-1表示当前p就是根节点

            int curP = p;
            while (parent[p] != -1){ // 循环找到根节点
                p = parent[p];
            }

            parent[curP] = p; // 将查找的节点指向根节点，以减低树的高度，起到后续查询时优化的作用
            return p;
        }

        public boolean isConnected(int p, int q){
            return find(p) == find(q);
        }

        public void union(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) return;

            if (rank[pRoot] > rank[qRoot]){
                parent[qRoot] = pRoot;
            }else if (rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }else{
                parent[qRoot] = pRoot;
                rank[pRoot] += 1;
            }
        }
    }
    // 方式三：并查集
    public int findCircleNum(int[][] M) {
        int peopleCount = M.length;

        unionFind unionFind = new unionFind(peopleCount);
        for (int i = 0; i < peopleCount; i++){
            for (int j = 0; j <= i; j++){
                if (i == j) continue;
                if (M[i][j] == 1) unionFind.union(i, j);
            }
        }

        int[] arr = unionFind.parent;
        int count = 0;
        for (int i = 0; i < peopleCount; i++){
            if (arr[i] == -1){
                count++;
            }
        }

        return count;
    }


    // 方式二：BFS广度优先遍历 耗时8 9ms
    public int findCircleNum2(int[][] M) {
        int peopleCount = M.length;
        int[] visited = new int[peopleCount];

        int count = 1;
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < peopleCount; i++){
            if (visited[i] == 0){
                queue.add(i);
                while (!queue.isEmpty()){
                    int curPeople = queue.poll();
                    visited[curPeople] = 1;
                    for (int j = 0; j < peopleCount; j++){
                        if (M[curPeople][j] == 1 && visited[j] == 0){
                            queue.add(j);
                        }
                    }
                }
                count++;
            }
        }

        return count;
    }

    // 方式一：DFS深度优先遍历 耗时2ms左右
    public int findCircleNum1(int[][] M) {
        int peopleCount = M.length;
        int[] visited = new int[peopleCount]; // 开辟访问

        int count = 0;
        for (int i = 0; i < peopleCount; i++){
            if (visited[i] == 0){ // 当前同学没被访问过
                dfs(M, visited, i, peopleCount);
                count++;
            }
        }

        return count;
    }

    private void dfs(int[][] M, int[] visited, int i, int peopleCount){
        for (int j = 0; j < peopleCount; j++){
            if (M[i][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                dfs(M, visited, j, peopleCount);
            }
        }
    }
}
```
