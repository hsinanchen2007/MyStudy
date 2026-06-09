主要思路是先转邻接表，然后遍历方法用深度和广度应该都可以。

## 1、数据结构

理论上，首先要理解图，其次理解有向图。

题中graph, [0,1]这种数组表示一条从0到1的有向边，多个有向边连成整个有向图。

数据结构上，有向图使用邻接表存储的。所以这里把有向图转为链表处理。

![1584523033347.png](https://pic.leetcode-cn.com/83eb183500573a23db5c0059bb694ce6c7d229316bb20e4018b40f6c6b427e20-1584523033347.png)


参考：
https://www.cnblogs.com/xuqiang/archive/2011/03/28/1997680.html



## 2、算法设计

先将graph转为邻接表存储，依次遍历每个链表，对start能到达的节点依次遍历，如果节点是target直接返回true. 

### 2.1 例子：

int[][] graph=new int [][] {{0,1},{1,2},{1,2}};

### 2.2 转为邻接表：

0->1

1->2->2

### 2.3 广度遍历：

1）维护一个栈：从0的链表访问，访问过程中0能到达的节点继续入栈

2）维护一个数组：对已经入栈的节点，不再重复处理

3）不断从栈中取节点得到新的可访问链表，对链表上的可访问节点中判断是否有target

4）遍历过程中有target则直接返回true, 否则返回false



## 3、代码

```java
public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
    // 将矩阵转为邻接表
    List<Integer>[] adj= new ArrayList [n];
    for (int[] edge:graph){
        int from=edge[0];
        int to=edge [1];
        if (adj[from]==null)
            adj[from]=new ArrayList<>();
        adj[from].add(to);
    }
    // 建一个函数进行广度遍历
    return hasPath(n,adj,start,target);
}

private boolean hasPath(int n, List<Integer>[] adj, int start, int target){
    // 维护一个栈：从0的链表访问，访问过程中0能到达的节点继续入栈
    LinkedList<Integer> queue = new LinkedList<> ();
    queue.offer(start);
    // 维护一个数组：对已经入栈的节点，不再重复处理
    boolean[] visited = new boolean [n];
    visited[start]=true;

    while(!queue.isEmpty()){
        int size=queue.size();
        // 不断从栈中取节点得到新的可访问链表，对链表上的可访问节点中判断是否有target
        for(int i = 0; i < size; i++){
            int node = queue.poll();
            List<Integer> nextList = adj [node];
            if (nextList==null){
                continue;
            }
            for (Integer next : nextList){
                // 遍历过程中有target则直接返回true, 否则最终返回false
                if (next==target){
                    return true;
                }
                // 已经入栈的节点，不再重复处理
                if (visited[next]){
                    continue;
                }
                // 用数组标记新的节点
                visited [next] =true;
                // 访问过程中0能到达的节点继续入栈
                queue.add(next);
            }
        }
    }
    return false;
}
```

