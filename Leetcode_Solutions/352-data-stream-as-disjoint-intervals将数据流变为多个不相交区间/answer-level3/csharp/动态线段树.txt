### 解题思路
Int32 范围构造线段树
获得区间 则 移除掉区间内节点 
则所有区间是 不相交的

最后合并相邻区间返回结果

### 代码

```csharp
using VT = System.ValueTuple<System.Int64, System.Int64>;
public class SummaryRanges {

    //0 ~ Int32
    //Leaf = 0 1 2 3 4 5 ... Int32
    //0  1 2  3 4 5 6
    //p*2+1 p*2+2  Int32-1
    private Dictionary<Int64, int> nodeValue = new Dictionary<Int64, int>();
    // private Heap<Int64> curNodes;
    /** Initialize your data structure here. */
    public SummaryRanges() {
        //存储最小的NodeId
        // curNodes = new Heap<Int64>((a, b) =>
        // {
        //     return Math.Sign(a - b);
        // });
    }
    
    private bool FindInRange(Int64 cur){
        // //Console.WriteLine("FindInRange:" + cur);
        while (cur > 0)
        {
            if (nodeValue.ContainsKey(cur)) return true;
            var p = (cur - 1) / 2;
            cur = p;
            // //Console.WriteLine("p:" + cur);
        }
        return false;
    }

    //2^31 中间节点 2^31-1个
    public void AddNum(int val) {
        Int64 leafId = (Int64)(Int32.MaxValue) - 1 + (Int64)val;
        if(FindInRange(leafId)) return;//已经在某个区间里面了

        nodeValue[leafId] = 1;
        // curNodes.Insert(leafId);
        var cur = leafId;

        //Console.WriteLine("AddNum:" + val+":"+cur+":"+nodeValue.Count);
    MergeNode:
        var p = (cur-1) / 2;
        if(p <= 0) return;
        var modV = cur % 2;
        var otherLeaf = cur;
        if(modV == 1){
            otherLeaf = cur + 1;
        }else {
            otherLeaf = cur - 1;
        }
        //Console.WriteLine("Other:"+cur+":"+otherLeaf+":"+p);
        //父区间存在了 则子区间没有意义了
        if(nodeValue.ContainsKey(otherLeaf)){
            nodeValue.Remove(cur);
            nodeValue.Remove(otherLeaf);
            nodeValue[p] = 1;
            cur = p;
            goto MergeNode;
        }
    }
    private Int64 FindL(Int64 nodeId){
        var midNode = (Int64)Int32.MaxValue - 1;
        if(nodeId >= midNode) return nodeId - midNode;
        var l = nodeId * 2 + 1;
        return FindL(l);
    }
    private Int64 FindR(Int64 nodeId){
        var midNode = (Int64)Int32.MaxValue - 1;
        if(nodeId >= midNode) return nodeId - midNode;
        var r = nodeId * 2 + 2;
        return FindR(r);
    }
    private VT GetNodeRange(Int64 nodeId){
        var l = FindL(nodeId);
        var r = FindR(nodeId);
        return (l, r);
    }
    public int[][] GetIntervals() {
        //自顶部向下部查找独立区间
        var nodes = nodeValue.Keys.ToList();
        var ret = new List<VT>();
        foreach(var n in nodes){
            ret.Add(GetNodeRange(n));
        }
        //不相交区间 排序 按照 区间的起点
        ret.Sort((a, b) =>
        {
            return Math.Sign(a.Item1 - b.Item1);
        });
        var mergeRet = new List<int[]>();
        if(ret.Count == 0)
        {
            return mergeRet.ToArray();
        }
        //Console.WriteLine("ret:" + ret.Count);
        mergeRet.Add(new int[] { 
            (int)ret[0].Item1,
            (int)ret[0].Item2,
        });
        for (var i = 1; i < ret.Count;i++){
            var c = mergeRet[mergeRet.Count - 1];
            var next = ret[i];
            if((c[1]+1) == next.Item1){
                c[1] = (int)next.Item2;
            }else {
                mergeRet.Add(new int[] { 
                    (int)next.Item1,
                    (int)next.Item2,
                });
            }
        }
        return mergeRet.ToArray();
    }

    // static void Main(string[] arg)
    // {
    //     // var v = Int32.MaxValue;
    //     // //Console.WriteLine(v);
    //     var ds = new SummaryRanges();
    //     ds.AddNum(1);
    //     var r = ds.GetIntervals();
    //     //Console.WriteLine(JsonSerializer.Serialize(r));
    //     ds.AddNum(3);
    //     r = ds.GetIntervals();
    //     //Console.WriteLine(JsonSerializer.Serialize(r));
    //     ds.AddNum(7);
    //     r = ds.GetIntervals();
    //     //Console.WriteLine(JsonSerializer.Serialize(r));
    //     ds.AddNum(2);
    //     r = ds.GetIntervals();
    //     //Console.WriteLine(JsonSerializer.Serialize(r));
    //     ds.AddNum(6);
    //     r = ds.GetIntervals();
    //     //Console.WriteLine(JsonSerializer.Serialize(r));
    // }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.AddNum(val);
 * int[][] param_2 = obj.GetIntervals();
 */
```