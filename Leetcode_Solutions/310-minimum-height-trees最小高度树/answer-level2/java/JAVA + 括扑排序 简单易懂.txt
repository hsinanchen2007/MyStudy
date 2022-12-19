## 思路
一开始想到括扑排序的时候想起了括扑排序的定义是：对一个*有向无环图*(Directed Acyclic Graph简称DAG)G进行拓扑排序，是将G中所有顶点排成一个线性序列，使得图中任意一对顶点u和v，若边<u,v>∈E(G)，则u在线性序列中出现在v之前。
我们不看这一大串的定义，只要记得是有向无环图这个关键

## 题解
按照题目的意思是：输入的数据是一个无向无环图的数据。因为是无向的，所以没办法使用出度和入度进行标记
可是我们可以仔细的分析一下，无向图中的所谓的入度为0的节点，其实就是在输入数据中只出现一次的那个节点！

我们把思路转化成，一个结点至少有1条边，我们统计出每个结点有多少条边即可

```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> result = new ArrayList<>();
        //极端条件
        if(n<=1) {
            result.add(0);
            return result;
        }
        int[] edge = new int[n];
        //构建每个结点的邻接表
        HashMap<Integer,List<Integer>> adj = new HashMap<>();
        for(int[] link : edges) {
            edge[link[0]]++;
            edge[link[1]]++;
            if(!adj.containsKey(link[0])) {
                adj.put(link[0],new ArrayList<>());
            }
            if(!adj.containsKey(link[1])) {
                adj.put(link[1],new ArrayList<>());
            }
            List<Integer> temp = adj.get(link[0]);
            temp.add(link[1]);
            adj.put(link[0],temp);
            temp = adj.get(link[1]);
            temp.add(link[0]);
            adj.put(link[1],temp);
        }
        //将每个边的数量为1的结点加入队列
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0;i<n;i++){
            if(edge[i]==1) {
                queue.add(i);
            }
        }
        int count = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            //终止条件！当已入队的节点数量和剩余的队列中的节点数量和为n的时候，就是找到了root
            if(count+size==n) {
                for(int i=0;i<size;i++){
                    result.add(queue.poll());
                }
                break;
            }
            count+=size;

            //正常执行
            for(int i=0;i<size;i++){
                int head = queue.poll();
                //将队中节点对应的邻接结点的边数量减一
                for(int item:adj.get(head)) {
                    edge[item]-=1;
                    //发现边数量为1的节点将其入队
                    if(edge[item]==1) {
                        queue.add(item);
                    }

                }
            }
            //System.out.println(count);
        }


        return result;
    }
}
```