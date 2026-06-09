### 解题思路
首先搜索 确定所有病毒区域 Region
确定每个区域的边界Cell，记录每个Cell接触次数
根据边界Cell接触次数 确定墙体数量

扩容所有无墙体的区域
若两个区域相交 则 并查集合并区域 和区域边界
合并完边界，对未扩容的边界仍需要进行扩容

最当所有区域都处理完，则流程结束



### 代码

```csharp


using VT = System.ValueTuple<int, int>;
class Region{
    public Dictionary<VT, int> boundEdge = new Dictionary<VT, int>();//必然是0
    public Region parent = null;
    public bool safe = false;
    public bool enLargetYet = false;
    public VT seed;
    public Region GetTop(){
        if(parent == null) return this;
        var p = parent;
        while(p.parent != null){
            p = p.parent;
        }
        parent = p;
        return p;
    }
}
class Virtus{
    private Dictionary<VT, Region> cellToRegion = new Dictionary<VT, Region>();
    private int[][] G;
    private List<Region> regionsX = new List<Region>();
    private void FindRegions(VT pos){
        var oq = new Queue<VT>();
        oq.Enqueue(pos);
        var region = new Region();
        region.seed = pos;
        regionsX.Add(region);
        cellToRegion.Add(pos, region);
        while(oq.Count > 0){
            var fir = oq.Dequeue();
            var nei = new List<VT>(){
                (fir.Item1+1, fir.Item2),
                (fir.Item1-1, fir.Item2),
                (fir.Item1, fir.Item2+1),
                (fir.Item1, fir.Item2-1),
            };
            foreach(var n in nei){
                if(cellToRegion.ContainsKey(n)) continue;//已经处理过了
                if(n.Item1 >= 0 && n.Item1 < G.Length && n.Item2 >= 0 && n.Item2 < G[0].Length){
                    var gv = G[n.Item1][n.Item2];
                    if(gv == 1) {
                        oq.Enqueue(n);
                        cellToRegion.Add(n, region);
                    }else {
                        if(!region.boundEdge.ContainsKey(n)) region.boundEdge[n] = 0;
                        region.boundEdge[n]++;
                    }
                }
            }
        }
    }
    private void Merge(Region p1, Region p2){
        p1 = p1.GetTop();
        p2 = p2.GetTop();
        if(p1 == p2) return;
        p2.parent = p1;
        foreach (var b in p2.boundEdge)
        {
            if(!p1.boundEdge.ContainsKey(b.Key)) p1.boundEdge[b.Key] = 0;
            p1.boundEdge[b.Key] += b.Value;
        }
    }

    private void Enlarge(Region r){
        r = r.GetTop();
        var oq = new Queue<VT>();
        //////Console.WriteLine("En:" + r.boundEdge.Count);
        var visB = new HashSet<VT>();
        foreach(var b in r.boundEdge){
            if (!cellToRegion.ContainsKey(b.Key)) //边界已经被污染了
            {
                cellToRegion.Add(b.Key, r);
                G[b.Key.Item1][b.Key.Item2] = 1;
            }
        }
        foreach (var b in r.boundEdge)
        {
            visB.Add(b.Key);
            oq.Enqueue(b.Key);
        }
        // var newB = new HashSet<VT>();
        r.boundEdge.Clear();
        while(oq.Count >0){
            //////Console.WriteLine("BoundCount:"+r.boundEdge.Count);
            var fir = oq.Dequeue();
            var nei = new List<VT>(){
                (fir.Item1+1, fir.Item2),
                (fir.Item1-1, fir.Item2),
                (fir.Item1, fir.Item2+1),
                (fir.Item1, fir.Item2-1),
            };
            foreach(var n in nei){
                //1 肯定都被处理过了
                if (cellToRegion.ContainsKey(n))
                {
                    var otherTop = cellToRegion[n].GetTop();
                    //对方已经是安全区了不能污染了 相当于碰到墙壁了
                    if (!otherTop.safe && otherTop != r)
                    {
                        var ob = otherTop.boundEdge;
                        if (!otherTop.enLargetYet) //未扩容则加入我的边界准备扩容 否则只是加入边界
                        {
                            //消除其它人的边界 融入我的边界
                            foreach (var b in ob)
                            {
                                if (!visB.Contains(b.Key))
                                {
                                    oq.Enqueue(b.Key);
                                    visB.Add(b.Key);
                                }
                                if (!cellToRegion.ContainsKey(b.Key))
                                {
                                    cellToRegion.Add(b.Key, r);
                                    G[b.Key.Item1][b.Key.Item2] = 1;
                                }
                            }
                        }
                        Merge(r, otherTop);
                    }
                    continue;//已经处理过了
                }
                if(n.Item1 >= 0 && n.Item1 < G.Length && n.Item2 >= 0 && n.Item2 < G[0].Length){
                    var gv = G[n.Item1][n.Item2];
                    if(!r.boundEdge.ContainsKey(n)) r.boundEdge[n] = 0;
                    r.boundEdge[n]++;
                    //////Console.WriteLine("BV:" + r.boundEdge[n]);
                }
            }
        }
        var nb = new Dictionary<VT, int>();
        foreach(var b in r.boundEdge){
            if(!cellToRegion.ContainsKey(b.Key)){
                nb[b.Key] = b.Value;
            }
        }
        r.boundEdge = nb;
        //////Console.WriteLine("BV:"+r.boundEdge.Count);
    }
    public int ContainVirus(int[][] grid) {
        G = grid;
        for (var i = 0; i < grid.Length; i++){
            for (var j = 0; j < grid[i].Length; j++){
                var cv = grid[i][j];
                var k = (i, j);
                if(cv == 1){
                    if(!cellToRegion.ContainsKey(k)){
                        FindRegions(k);
                    }
                }
            }
        }
        if(regionsX.Count == 0) return 0;
        var total = 0;
        var nullParRegion = regionsX;
    FindMax:
        Region maxR = null;
        int maxBound = -1;
        var maxI = 0;
        var index = 0;
        for (var i = 0; i < nullParRegion.Count; i++)
        {
            var r = nullParRegion[i];
            if (r.boundEdge.Count > maxBound && r.parent == null)
            {
                maxBound = r.boundEdge.Count;
                maxR = r;
                maxI = index;
            }
            index++;
        }
        var temp = nullParRegion[0];
        nullParRegion[0] = maxR;
        nullParRegion[maxI] = temp;
        //Console.WriteLine("MaxR:"+maxR.boundEdge.Count+":"+maxI+":"+temp.boundEdge.Count+":"+nullParRegion.Count+":"+maxR.seed);
        foreach (var b in maxR.boundEdge)
        {
            // //////Console.WriteLine(total+":"+b.Key+":"+b.Value);
            total += b.Value;
        }
        maxR.GetTop().safe = true;

        //////Console.WriteLine("total:"+total);
        var newNull = new List<Region>();
        for (var i = 1; i < nullParRegion.Count; i++) {
            var r = nullParRegion[i];
            if(r.parent == null) {
            //传染还是要传染的
                newNull.Add(r);
                //Console.WriteLine("Before:"+r.seed+":" + r.boundEdge.Count);
                r.enLargetYet = true;
                Enlarge(r);
                //Console.WriteLine("EnLarge:"+r.boundEdge.Count);
            }
        }
        foreach(var r in newNull) r.enLargetYet = false;
        nullParRegion = newNull;
        //Console.WriteLine("nullCount:"+nullParRegion.Count);
        // foreach(var l in G){
        //     //Console.WriteLine(JsonSerializer.Serialize(l));
        // }
        if(nullParRegion.Count > 0) goto FindMax;
        return total;
    }
}

public class Solution {
    public int ContainVirus(int[][] grid) {
        var b = new Virtus();
        return b.ContainVirus(grid);
    }
}
```