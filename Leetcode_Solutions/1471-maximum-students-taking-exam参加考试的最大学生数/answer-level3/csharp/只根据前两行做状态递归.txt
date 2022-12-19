### 解题思路
每行状态 只受前两个 状态影响

### 代码

```csharp
using VT = System.ValueTuple<ulong, ulong, int>;
class MaxStu2{
    private int totalPos;
    private int M, N;
    private char[][] S;
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    private Dictionary<VT, int> selectPos = new Dictionary<VT, int>();
    public int totalNum = 0;
    int MaxN(ulong lastRow, ulong curRow, int lastPos){
        totalNum++;
        var key = (lastRow, curRow, lastPos);
        if(cache.ContainsKey(key)) return cache[key];
        // var nowRow = (lastPos + 1) / N;
        // var pr = lastPos / N;
        // var nowRow = (lastPos + 1) / N;
        // if(nowRow > pr){
        //     lastRow = curRow;
        //     curRow = 0;
        // }
        var maxN = 0;
        for (var i = lastPos + 1; i < totalPos; i++){
            var col = i % N;
            var row = i / N;
            // if(row > nowRow){
            if(col==0){
                lastRow = curRow;
                curRow = 0;
                // nowRow = row;
            }
            ulong off = (ulong)1 << col;
            if(S[row][col] == '.'){
                var canSee = false;
                if(col > 0){
                    var lf = col - 1;
                    // var lm = N*row+lf;
                    var lc = ((UInt64)1) << lf;
                    canSee = (curRow & lc) > 0;
                }
                if(canSee) continue;
                // if(col < (N-1)){
                //     var rt = col + 1;
                //     var rm = N * row + rt;
                //     var rc = ((UInt64)1) << rm;
                //     canSee = (curRow & rc) > 0;
                // }
                // if(canSee) continue;
                if(col > 0 && row > 0){
                    var lf = col - 1;
                    // var up = row - 1;
                    // var lu = N * up + lf;
                    var lc = ((UInt64)1) << lf;
                    canSee = (lastRow & lc) > 0;
                }
                if(canSee) continue;
                if (col < (N - 1) && row > 0)
                {
                    var lf = col + 1;
                    // var up = row - 1;
                    // var lu = N * up + lf;
                    var lc = ((UInt64)1) << lf;
                    canSee = (lastRow & lc) > 0;
                }
                if(canSee) continue; 
                var newState = curRow | off;
                var mn = MaxN(lastRow, newState, i)+1;
                if (mn > maxN)
                {
                    maxN = Math.Max(maxN, mn);
                    selectPos[key] = i;
                }
            }
        }
        cache.Add(key, maxN);
        return maxN;
    }
    public int MaxStudents(char[][] seats) {
        S = seats;
        M = S.Length;
        N = S[0].Length;
        totalPos = M * N;
        // Console.WriteLine("MN:" + M + ":" + N);
        return MaxN(0, 0, -1);
    }
    // private void DumpPos(){
    //     var allPos = new List<int>();
    //     VT curKey = (0, 0, -1);
    //     Console.WriteLine("Cur:" + curKey);
    // Loop:
    //     if (selectPos.ContainsKey(curKey))
    //     {
    //         var sp = selectPos[curKey];
    //         allPos.Add(sp);
    //         var col = sp % N;
    //         var row = sp / N;
    //         Console.WriteLine("V:" + sp + ":"+cache[curKey]+":"+row+":"+col);
    //         var lp = curKey.Item3;
    //         var lastRow = curKey.Item1;
    //         var curRow = curKey.Item2;
    //         if (row != lp)
    //         {
    //             lastRow = curRow;
    //             curRow = 0;
    //         }
    //         curRow |= (ulong)1 << col;
    //         curKey = (lastRow, curRow, sp);
    //         Console.WriteLine("key:" + curKey);
    //         goto Loop;
    //     }

    //     // Console.WriteLine(JsonSerializer.Serialize(allPos));
    // }

    // static void Main(string[] arg)
    // {
    //     var ts = File.ReadAllLines("testSeat.json");
    //     var l = ts[0];
    //     var st = JsonSerializer.Deserialize<char[][]>(l);
    //     var ms = new MaxStu2();
    //     var n = ms.MaxStudents(st);
    //     Console.WriteLine(n+":"+ms.totalNum);
    //     // foreach(var c in ms.cache){
    //     //     Console.WriteLine("Ca:" + c.Key + ":" + c.Value);
    //     // }
    //     // Console.WriteLine("#####");
    //     // foreach(var s in ms.selectPos){
    //     //     Console.WriteLine("pos:"+s.Key+":"+s.Value);
    //     // }
    //     // ms.DumpPos();
    // }
}
public class Solution {
    public int MaxStudents(char[][] seats) {
        var ms = new MaxStu2();
        return ms.MaxStudents(seats);
    }
}
```