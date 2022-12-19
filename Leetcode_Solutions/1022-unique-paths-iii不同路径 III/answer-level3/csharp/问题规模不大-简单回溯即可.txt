### 解题思路
记录位置和当前方向

### 代码

```csharp


using VT = System.ValueTuple<int, int>;

class UMove{
    public VT pos;
    public int moveDir = -1;
}
class UPath{
    private int[][] G;
    private List<VT> GetNeibor(VT pos){
        var nei = new VT[] { 
            (pos.Item1-1, pos.Item2),
            (pos.Item1+1, pos.Item2),
            (pos.Item1, pos.Item2+1),
            (pos.Item1, pos.Item2-1),
        };
        var ls = new List<VT>();
        foreach(var n in nei){
            var v = CheckValid(n);
            if(v) ls.Add(n);
        }
        return ls;
    }
    private bool CheckValid(VT n){
        var inR = n.Item1 >= 0 && n.Item1 < G.Length && n.Item2 >= 0 && n.Item2 < G[0].Length;
        if(inR){
            return G[n.Item1][n.Item2] != -1;
        }
        return false;
    }
    private bool CompareVT(VT v1, VT v2){
        return v1.Item1 == v2.Item1 && v1.Item2 == v2.Item2;
    }
    public int UniquePathsIII(int[][] grid) {
        G = grid;
        //1 -> 2
        //0 walk -1 block
        //DepthSearch When RepeatBlock
        var startPos = new UMove();
        var endPos = new UMove();

        
        var canWalkCount = 0;
        for (var i = 0; i < grid.Length; i++){
            for (var j = 0; j < grid[i].Length; j++){
                if(grid[i][j] == 1) {
                    startPos.pos = (i, j);
                }else if(grid[i][j] == 2){
                    endPos.pos = (i, j);
                }
                if(grid[i][j] != -1){
                    canWalkCount++;
                }
            }
        }

        //检查所有zero点的可达性
        var openQueue = new Queue<VT>();
        var hs = new HashSet<VT>();
        openQueue.Enqueue(startPos.pos);
        hs.Add(startPos.pos);
        while(openQueue.Count > 0){
            var fir = openQueue.Dequeue();
            var ns = GetNeibor(fir);
            if(ns.Count == 0){ //没有邻居可走
                return 0;
            }
            if(ns.Count == 1){//起点和终点可以只有一个邻居 其它点需要两个邻居至少
                if(!CompareVT(fir, startPos.pos) && !CompareVT(fir, endPos.pos)) return 0;
            }
            foreach(var n in ns){
                if(!hs.Contains(n)){
                    hs.Add(n);
                    if (!CompareVT(n, endPos.pos)) //最后一个点不能扩展
                    {
                        openQueue.Enqueue(n);
                    }
                }
            }
        }
        //没有遍历所有的点
        if(hs.Count != canWalkCount) return 0;

        var stack = new List<UMove>();
        hs.Clear();
        stack.Add(startPos);
        hs.Add(startPos.pos);
        var pathCount = 0;
        while(stack.Count > 0){
            var top = stack[stack.Count - 1];
            if (hs.Count == canWalkCount)
            {
                pathCount++;
            }
            var findNext = false;
            var neis = GetNeibor(top.pos);
            var nextPos = (-1, -1);
            // Console.WriteLine("MD:"+top.pos+":"+top.moveDir);
            for (var nextDir = top.moveDir + 1; nextDir < neis.Count; nextDir++){
                top.moveDir = nextDir;
                var nn = neis[nextDir];
                if(hs.Contains(nn)) continue;
                //不是最后一步
                if(CompareVT(nn, endPos.pos) && hs.Count != (canWalkCount-1)) continue;
                findNext = true;
                nextPos = nn;
                break;
            }
            // Console.WriteLine("hs:"+hs.Count+":"+top.pos+":"+nextPos);
            if(!findNext){
                top.moveDir = -1;
                stack.RemoveAt(stack.Count - 1);
                hs.Remove(top.pos);
            }else{
                hs.Add(nextPos);
                stack.Add(new UMove()
                {
                    pos = nextPos,
                });
            }
        }
        return pathCount;
    }
}

public class Solution {
    public int UniquePathsIII(int[][] grid) {
        var np = new UPath();
        return np.UniquePathsIII(grid);
    }
}
```