### 解题思路
解题思路见代码中

### 代码

```java
import java.util.*;


/**
 * DFS
 * 1.先找到所有出度为1的顶点，将他们全都入队；
 * 2.然后每次都一次性的遍历完队列中的全部元素的出度大于1的邻边，将邻边的出度都减1，当执行完一个元素
 * 的邻边的遍历之后，如果出度变为了0，就入新队；
 * 3.循环的结束条件是新队为空时 最关键的一步如下：
 *              for(int w: graph[v]){
                    if(inDegree[w] > 1){
                        w_list.add(w);
                        inDegree[w] --;
                    }
                }
                for(int w: w_list){
                    if(inDegree[w] == 1){
                        newQueue.add(w);
                    }
                }
 */
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        // 构建图 和出度表
        ArrayList<Integer>[] graph = new ArrayList[n];
        int[] inDegree = new int[n];
        for(int i=0; i<n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] e: edges){
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
            inDegree[e[0]] ++;
            inDegree[e[1]] ++;
        }

        // 获得当前所有出度为1的节点，并入队
        HashSet<Integer> queue = new HashSet<>();
        for(int i=0; i<n; i++){
            if(inDegree[i] == 1){
                queue.add(i);
            }
        }

        while(!queue.isEmpty()){
            // 记录当前所有出度为1的顶点的下面顶点集合
            HashSet<Integer> newQueue = new HashSet<>();
            for(int v: queue){
                ArrayList<Integer> w_list = new ArrayList<>();  // 记录哪些顶点需要改变
                // 遍历v的所有出度不为1的邻边
                for(int w: graph[v]){
                    if(inDegree[w] > 1){
                        w_list.add(w);
                        inDegree[w] --;
                    }
                }
                for(int w: w_list){
                    if(inDegree[w] == 1){
                        newQueue.add(w);
                    }
                }
            }

            if(newQueue.isEmpty()){
                break;
            }

            queue = newQueue;
        }

        List<Integer> res = new ArrayList<>();
        for(int i: queue){
            res.add(i);
        }
        if(edges.length == 0){
            res.add(0);
        }
        return res;

    }

}
```