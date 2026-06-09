## intro

看了下没人用并查集来解决这个问题，发个新的思路分享下，虽然速度很慢...(没有优化)

常规思路的DFS/BFS的染色我就不贴了

并查集就不介绍了，具体可以去谷歌搜索/知乎专栏/博客等

我个人感觉其实挺不好理解的，因为并的对象不是自己，而是自己的对手，推荐用样例自己手动模拟一下这个过程。



## 代码

```java
class Solution {
    int[] father;   //并查集
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        father = new int[n*2];    //开两倍的数组
        for(int i = 0; i < n*2; i++) //初始化并查集
            father[i] = i;
        for(int i = 0; i < graph.length; i++){
            for(int j = 0; j < graph[i].length; j++){
                int x = find(i); //查找自己的根节点
                int y = find(graph[i][j]);
                int a = find(i + n); //查找自己不喜欢的人的根节点
                int b = find(graph[i][j] + n); 
                if(x == y) return false; //发现这俩人已经在一组
                else{
                    father[a] = y;  //将不喜欢的人合并
                    father[b] = x;
                }
            }
        }
        return true;
    }
    private int find(int x){ //寻找根节点
        if(x != father[x])  
            father[x] = find(father[x]); //路径压缩
        return father[x];
    }
}
```