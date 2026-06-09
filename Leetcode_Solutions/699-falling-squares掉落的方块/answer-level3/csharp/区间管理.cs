### 解题思路
根据不同高度 划分独立区间
二分法 查找 新落方块 相交的区间
合并区间 刷新当前最高高度

### 代码

```csharp
using VT = System.ValueTuple<int, int, int>;
class Squares{
    //SameHeight 合并
    //不同高度拆分
    //  3   3
    //  2 2
    //  1 1 1
    //0 0 0 0
    //最高的相交区域
    private List<VT> listRe;

    private VT InterRegion(VT a, VT b){
        var minX = Math.Max(a.Item1, b.Item1);
        var maxX = Math.Min(a.Item2, b.Item2);
        return (minX, maxX, b.Item3);
    }
    private bool IsEqualOrSmall(VT a, VT b){
        return a.Item1 >= b.Item1 && a.Item2 <= b.Item2;
    }
    //A 下层 inter 上层
    private List<VT> DivRegion(VT a, VT inter, bool insertYet){
        var ret = new List<VT>();
        if(a.Item1 < inter.Item1){
            var mx = (a.Item1, inter.Item1, a.Item3);
            ret.Add(mx);
        }
        if(!insertYet) ret.Add(inter);
        if(a.Item2 > inter.Item2){
            var mx = (inter.Item2, a.Item2, a.Item3);
            ret.Add(mx);
        }
        return ret;
    }
    private int allHei = 0;
    //修正区域属性
    private void FindInterRegion(int[] pos){
        var pv = (pos[0], pos[0] + pos[1], pos[1]);
        var s = 0;
        var e = listRe.Count - 1;
        var pStart = pv.Item1;
        var pEnd = pv.Item2;
        var pHei = pv.Item3;
        var startInRegion = -1;
        //区域互相独立
        while(s <= e){
            var mid = (s + e) / 2;
            var r = listRe[mid];
            if(pStart < r.Item1){
                e = mid - 1;
            }else if(pStart >= r.Item2){
                s = mid + 1;
            }else {//pStart >= r.Item1 < r.Item2
                startInRegion = mid;
                break;
            }
        }
        //肯定找到Start
        s = 0;
        e = listRe.Count - 1;
        var endInRegion = -1;
        while(s <= e){
            var mid = (s + e) / 2;
            var r = listRe[mid];
            if(pEnd <= r.Item1){
                e = mid - 1;
            }else if(pEnd > r.Item2){
                s = mid + 1;
            }else {
                endInRegion = mid;
                break;
            }
        }
        var maxHei = -1;
        var maxRegion = -1;
        // var sameHeightRegions = new List<int>();
        //找到所有相交区域 中最高的区域
        for (var i = startInRegion; i <= endInRegion; i++){
            var rg = listRe[i];
            if(rg.Item3 > maxHei){
                maxHei = rg.Item3;
                maxRegion = i;
                // sameHeightRegions.Clear();
                // sameHeightRegions.Add(i);
            }
            // else if(rg.Item3 == maxHei){
            //     sameHeightRegions.Add(i);
            // }//< maxHei 无视
        }
        var highestRegion = (pStart, pEnd, maxHei + pHei);
        //吸收所有相交Region 修改其高度
        var newAbsorbRegion = new List<VT>();
        var insertYet = false;
        //Low High Low
        //Low Absorb Low
        for (var i = startInRegion; i <= endInRegion; i++){
            var oldRe = listRe[i];
            if(IsEqualOrSmall(oldRe, highestRegion)){
                if(!insertYet) newAbsorbRegion.Add(highestRegion);
                insertYet = true;
            }else {
                var ret = DivRegion(oldRe, highestRegion, insertYet);
                newAbsorbRegion.AddRange(ret);
                insertYet = true;
            }
        }
        //替换区间
        listRe.RemoveRange(startInRegion, endInRegion - startInRegion + 1);
        listRe.InsertRange(startInRegion, newAbsorbRegion);
        allHei = Math.Max(allHei, highestRegion.Item3);
    }   
    public IList<int> FallingSquares(int[][] positions) {
        listRe = new List<VT>();//区域和 区域高度 区域独立
        //0 ++ height = 0
        var bottom = (0, Int32.MaxValue, 0);
        listRe.Add(bottom);
        var ret = new List<int>();
        for (var i = 0; i < positions.Length; i++){
            FindInterRegion(positions[i]);
            ret.Add(allHei);
        }
        return ret;
    }
    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testSQ.json");
    //     var js = JsonSerializer.Deserialize<int[][]>(l[0]);

    //     var sq = new Squares();
    //     var r = sq.FallingSquares(js);
    //     Console.WriteLine(JsonSerializer.Serialize(r));

    // }
}
public class Solution {
    public IList<int> FallingSquares(int[][] positions) {
        var sq = new Squares();
        return sq.FallingSquares(positions);
    }
}
```