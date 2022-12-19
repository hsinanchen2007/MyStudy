### 解题思路
将所有座位两两划分
每组作为 两个人，若是 couple 则不用处理
不是couple 则 合并两组Couple 到一个集合中
根据每个集合中 Couple的数量，确定交换次数 = couple数量-1

### 代码

```csharp
class CoupleNode {
    public int totalNodeCount = 1;
    public int coupleId;
    // public int seatPos = -1;
    public HashSet<CoupleNode> neiborLink = new HashSet<CoupleNode>();
    // public bool inLoop = false;
    public CoupleNode parent;
    public CoupleNode GetTopNode(){
        if(parent == null) return this;
        var p = parent;
        while(p.parent != null) p = p.parent;
        parent = p;
        return p;
    }
    public static void MergeNode(CoupleNode p1, CoupleNode p2){
        p1 = p1.GetTopNode();
        p2 = p2.GetTopNode();
        if(p1 == p2) return;
        p2.parent = p1;
        p1.totalNodeCount += p2.totalNodeCount;
    }
}
class HoldHands {
    //2N 最小交换次数
    //最后一次交换
    //1324 --> 12 34 | 43 21
    //Group位置 必然有一对 坐在一起
    //N Group 分配问题
    //操作交换 
    //N-1 对 OK了 则 最后一对也是Ok的 需要对齐
    //构成一个循环 构成 两两交换结构
    //05 21 43
    public int MinSwapsCouples(int[] row) {
        var N = row.Length / 2;

        var dc = new Dictionary<int, CoupleNode>();
        for (var i = 0; i < N; i++){
            var c = new CoupleNode()
            {   
                coupleId = i,
            };
            dc[i] = c;
        }

        for (var i = 0; i < row.Length; i += 2){
            var c1 = row[i]/2;
            var c2 = row[i + 1]/2;
            // Console.WriteLine("c1c2:" + c1 + ":" + c2);
            if(c1 != c2){
                CoupleNode.MergeNode(dc[c1], dc[c2]);
            }
        }
        var totalSwap = 0;
        foreach(var n in dc){
            if(n.Value.parent == null) {
                // Console.WriteLine("totalW:"+n.Value.totalNodeCount+":"+n.Value.coupleId);
                totalSwap += n.Value.totalNodeCount - 1;
            }
        }
        return totalSwap;
    }
}

public class Solution {
    public int MinSwapsCouples(int[] row) {
        var hh = new HoldHands();
        return hh.MinSwapsCouples(row);
    }
}
```