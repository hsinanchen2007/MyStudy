### 解题思路
问题规模比较小
1:确定所有点之间的最短距离
2:起点 和 剩余点 为key 动态规划 所有子问题 最优解

### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class VisAllNode {
    private Dictionary<VT, int> allPath = new Dictionary<VT, int>();
    private Dictionary<VT, int> allBitPath = new Dictionary<VT, int>();
    private int maxN;
    private void FindShortPath(int s, int[][] g){
        var openQ = new Queue<VT>();
        openQ.Enqueue((s, 0));
        var hs = new HashSet<int>();
        hs.Add(s);
        while(openQ.Count > 0){
            var fir = openQ.Dequeue();
            var neis = g[fir.Item1];
            foreach(var n in neis){
                if(hs.Contains(n)) continue;
                hs.Add(n);
                var dist = fir.Item2 + 1;
                openQ.Enqueue((n, dist));
                allPath.Add((s, n), fir.Item2 + 1);
                allBitPath.Add((1 << s, 1 << n), fir.Item2 + 1);
            }
        }
    }
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    //最多12个顶点
    private int FindMinPath(int start, int leftNodes){
        //剩余0个节点不需要寻路了
        if(leftNodes == 0) return 0;
        var notA = (~leftNodes);
        var minOne = leftNodes - 1;
        var newV = (notA & minOne) + 1;
        if(newV == leftNodes){//只剩余1个节点了
            return allBitPath[(1<<start, leftNodes)];
        }
        var key = (start, leftNodes);
        if(cache.ContainsKey(key)) return cache[key];

        var minDist = Int32.MaxValue;
        var sb = 1 << start;
        //遍历每个节点 寻找最短路径
        for (var i = 0; i < maxN; i++){
            var ep = 1 << i;
            if((ep & leftNodes) > 0){
                var dist = allBitPath[(sb, ep)];
                var otherDist = FindMinPath(i, leftNodes & (~ep));
                minDist = Math.Min(minDist, dist + otherDist);
            }
        }
        cache.Add(key, minDist);
        return minDist;
    }

    public int ShortestPathLength(int[][] graph) {
        //遍历所有路径 以所有点起点 
        //对称性 S->E E->S 对称
        //找到任意两点之间的最短距离
        for (var i = 0; i < graph.Length; i++){
            FindShortPath(i, graph);
        }
        maxN = graph.Length;
        var minDist = Int32.MaxValue;
        var leftNodes = 0;
        for (var i = 0; i < maxN; i++){
            leftNodes |= 1 << i;
        }
        for (var i = 0; i < maxN; i++)
        {
            var ep = 1 << i;
            var dist = FindMinPath(i, leftNodes & (~ep));
            minDist = Math.Min(minDist, dist);
        }
        return minDist;
    }
}

public class Solution {
    public int ShortestPathLength(int[][] graph) {
        var van = new VisAllNode();
        return van.ShortestPathLength(graph);
    }
}
```