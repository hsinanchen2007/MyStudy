### 解题思路
将图切分为多个岛屿
每个岛屿的所有边界 存储下来

统计每个边界点连接了哪些岛屿
则修改某个边界点后 连接的岛屿大小 = 所有连接岛屿大小之和+1

### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class Island{
    public HashSet<VT> nodes = new HashSet<VT>();
    public HashSet<VT> bound = new HashSet<VT>();//边界
}
class BigIsland{
    private int W, H;
    private bool InRange(VT p){
        return p.Item1 >= 0 && p.Item1 < W && p.Item2 >= 0 && p.Item2 < H;
    }
    public int LargestIsland(int[][] grid) {
        W = grid.Length;
        H = grid[0].Length;
        //Connect 4Island
        var allOne = new HashSet<VT>();
        var waitToSep = new HashSet<VT>();
        for (var i = 0; i < grid.Length; i++){
            for (var j = 0; j < grid[0].Length; j++){
                if(grid[i][j] == 1){
                    allOne.Add((i, j));
                    waitToSep.Add((i, j));
                }
            }
        }

        var allIslands = new List<Island>();
        var visited = new HashSet<VT>();
        while(waitToSep.Count > 0){
            var f = waitToSep.First();
            waitToSep.Remove(f);

            var open = new Queue<VT>();
            open.Enqueue(f);
            visited.Add(f);
            var thisIsland = new Island();
            allIslands.Add(thisIsland);
            thisIsland.nodes.Add(f);

            while(open.Count > 0){
                var fir = open.Dequeue();
                var neis = new List<VT>()
                {
                    (fir.Item1-1, fir.Item2),
                    (fir.Item1+1, fir.Item2),
                    (fir.Item1, fir.Item2-1),
                    (fir.Item1, fir.Item2+1),
                };
                foreach(var n in neis){
                    if(!InRange(n)) continue;//没在地图中
                    if (!allOne.Contains(n))
                    {
                        thisIsland.bound.Add(n);//添加0边界
                        continue;//不是1
                    }
                    if(visited.Contains(n)) continue; //已经访问过了
                    visited.Add(n);
                    open.Enqueue(n);
                    thisIsland.nodes.Add(n);
                    waitToSep.Remove(n);
                }
            }
        }
        if(allIslands.Count == 0) return 1;
        // Console.WriteLine("IslandNum:" + allIslands.Count);
        //划分多个岛屿 计算每个岛屿的边界
        //所有边界点每个边界连接的Island的总大小
        var dictBound = new Dictionary<VT, HashSet<int>>();//每个边界连接的Island统计
        for (var i = 0; i < allIslands.Count; i++)
        {
            var il = allIslands[i];
            foreach (var b in il.bound)
            {
                dictBound.TryAdd(b, new HashSet<int>());
                dictBound[b].Add(i);
            }
        }
        // Console.WriteLine("BoundNum:" + dictBound.Count);
        if(dictBound.Count == 0) return W * H;//没有边界 填满了1

        var maxIslandSize = 0;
        foreach(var d in dictBound){
            var sz = 0;
            foreach(var il in d.Value){
                sz += allIslands[il].nodes.Count;
            }
            maxIslandSize = Math.Max(sz+1, maxIslandSize);
        }
        return maxIslandSize;
    }
    // static void Main(string[] arg)
    // {
    //     var ls = File.ReadAllLines("testBI.json");
    //     var it = JsonSerializer.Deserialize<int[][]>(ls[0]);
    //     var bi = new BigIsland();
    //     var r = bi.LargestIsland(it);
    //     Console.WriteLine(r);
    // }
}
public class Solution {
    public int LargestIsland(int[][] grid) {
        var bi = new BigIsland();
        return bi.LargestIsland(grid);
    }
}
```