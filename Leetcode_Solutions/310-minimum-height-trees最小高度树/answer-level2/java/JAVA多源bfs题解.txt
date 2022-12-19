### 解题思路
0. 为了方便解题，模拟一下无向图，写一个类Node,记录值val和邻接列表neighbors
1. 模拟无向图，插入节点，边
2. 此题中的bfs为多源bfs，开始搜索的点为树的叶子节点,即neighbors.size()==1
3. 开始bfs搜索，每轮需要以下操作：
    - 记录当前一轮的个数
    - 删除叶子节点
    - 更新边
    - 若更新边之后，成为叶子节点，则加入队列
4. 最后遗留的就是答案，发现答案只会有一个或两个节点，简单证明一下：
     假设有最小高度的三个节点a,b,c
     对于任意a,b,c中的一个节点x，必有x成为剩余两个节点的父节点，因此不会有超过两个答案
### 代码

```java
class Solution {
    private HashMap<Integer,Node> map;
    private Queue<Node> queue;
    private int num=0;
    ArrayList<Integer> result;
    //use Multi-source breadth first search
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
         if (n==1&&edges.length==0){
            return Arrays.asList(0);
        }
        map=new HashMap<>();
        queue=new LinkedList<>();
        result=new ArrayList<>();
        //init vertex
        for (int i = 0; i < n; i++) {
            map.put(i,new Node(i,new ArrayList<>(),false));
        }
        //init edge
        for (int[] edge : edges) {
            addEdge(edge);
        }
        //init leaf node
        map.forEach((k,v)->{
            if (v.neighbors.size()==1){
                v.height=0;
                v.isVisited=true;
                queue.add(v);
                num++;
            }
        });
        //bfs
        bfs();
        return result;
    }

    private void addEdge(int[] edge){
        map.get(edge[0]).neighbors.add(map.get(edge[1]));
        map.get(edge[1]).neighbors.add(map.get(edge[0]));
    }

    private void bfs(){
        while (!queue.isEmpty()){
            result.clear();
            int temp=0;
            for (int i = 0; i < num; i++) {
                Node node= queue.poll();
                result.add(node.val);
                for (Node neighbor : node.neighbors) {
                    neighbor.neighbors.remove(node);
                    if (neighbor.neighbors.size()==1){
                        queue.add(neighbor);
                        temp++;
                    }
                }
            }
            num=temp;
        }
    }
}

class Node{
    int val;
    ArrayList<Node> neighbors;
    int height;
    boolean isVisited;

    public Node(int val, ArrayList<Node> neighbors, int height) {
        this.val = val;
        this.neighbors = neighbors;
        this.height = height;
    }

    public Node(int val, ArrayList<Node> neighbors,boolean isVisited) {
        this.val = val;
        this.neighbors = neighbors;
        this.isVisited=isVisited;
    }
}
```