### 解题思路
若找到目标，则停止处理其他节点

### 代码

```csharp
using VT = System.ValueTuple<int, int, double>;

class WaNode{
    public int node;
    public HashSet<int> edges = new HashSet<int>();
}
class WaJump{
    private Dictionary<int, WaNode> nodes= new Dictionary<int, WaNode>();
    public double FrogPosition(int n, int[][] edges, int t, int target) {
        for(var i = 1; i <= n; i++){
            nodes.Add(i, new WaNode(){
                node = i,
            });
        }
        foreach(var e in edges){
            nodes[e[0]].edges.Add(e[1]);
            nodes[e[1]].edges.Add(e[0]);
        }
        // foreach(var nn in nodes){
        //     Console.WriteLine(nn.Key+":"+nn.Value.edges.Count);
        // }
        //Pos time poss
        var openNode = new Queue<VT>();
        openNode.Enqueue((1, 0, 1.0));
        var hs = new HashSet<int>();
        hs.Add(1);
        var findTar = false;
        while(openNode.Count > 0){
            var fir = openNode.Dequeue();
            if(fir.Item1 == target) findTar = true;
            // Console.WriteLine("F:"+fir);
            if(fir.Item2 >= t){ 
                if(fir.Item1 == target){
                    return fir.Item3;
                }
                continue;
            }
            if(findTar && fir.Item1 != target)
            {
                continue;
            }
            var neibors = nodes[fir.Item1].edges;
            var lst = new List<int>();
            foreach(var ne in neibors){
                if(hs.Contains(ne)) continue;
                hs.Add(ne);
                lst.Add(ne);
            }
            if(lst.Count > 0){
                var pos = 1.0/lst.Count;
                foreach(var l in lst){
                    openNode.Enqueue((l, fir.Item2+1, fir.Item3 * pos));
                }
            }else {
                openNode.Enqueue((fir.Item1, fir.Item2+1, fir.Item3));
            }
        }
        return 0.0;
    }

}

public class Solution {
    public double FrogPosition(int n, int[][] edges, int t, int target) {
        var wa = new WaJump();
        return wa.FrogPosition(n, edges, t, target);
    }
}
```