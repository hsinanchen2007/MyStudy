### 解题思路
对height 排序
从低height 开始 计算最大面积
低height 可以切割 区域 为多个子区域
下一个高height 只能在子区域内 求面积


### 代码

```csharp

using VT = System.ValueTuple<int, int>;
class HisPos{
    public int v;
    public int index;
}
class Histogram{
    public int total = 0;
    // public int LargestRectangleArea(int[] heights) {
    //     //选择每个高度 向前 向后 扩展 找到所有可以连续的高度
    //     var maxArea = 0;
    //     for (var i = 0; i < heights.Length; i++){
    //         var cur = i;
    //         var wid = 1;
    //         var hei = heights[i];
    //         total++;
    //         for (var j = cur-1; j >= 0; j--){
    //             total++;
    //             if(heights[j] >= hei){
    //                 wid++;
    //             }else{
    //                 break;
    //             }
    //         }
    //         for (var j = cur + 1; j < heights.Length; j++){
    //             total++;
    //             if(heights[j] >= hei){
    //                 wid++;
    //             }else break;
    //         }
    //         maxArea = Math.Max(maxArea, wid * hei);
    //     }
    //     return maxArea;
    // }
    private void CutRegion(List<VT> lsRegion, int p){
        var st = 0;
        var end = lsRegion.Count - 1;
        //寻找切割区间
        while(st <= end){
            var mid = (st + end) / 2;
            var rg = lsRegion[mid];
            if(rg.Item1 < p && p < rg.Item2){
                var ng1 = (rg.Item1, p);
                var ng2 = (p, rg.Item2);
                lsRegion[mid] = ng1;
                lsRegion.Insert(mid+1, ng2);
                break;
            }
            if(p <= rg.Item1){
                end = mid - 1;
            }else {
                st = mid + 1;
            }
        }
    }
    private int FindRegion(List<VT> lsRegion, int index){
        var st = 0;
        var end = lsRegion.Count - 1;
        while (st <= end)
        {
            var mid = (st + end) / 2;
            var rg = lsRegion[mid];
            if(rg.Item1 < index && index < rg.Item2){
                // var ng1 = (rg.Item1, index);
                // var ng2 = (index, rg.Item2);
                // lsRegion[mid] = ng1;
                // lsRegion.Insert(mid, ng2);
                return mid;
                // break;
            }
            if(index <= rg.Item1){
                end = mid - 1;
            }else {
                st = mid + 1;
            }
        }
        return st;
    }
    private void DumpRegion(){
        //Console.WriteLine("Reg:####");
        foreach(var r in lsRegion){
            //Console.WriteLine(r);
        }
    }
    List<VT> lsRegion;
    public int LargestRectangleArea(int[] heights)
    {
        var ls = new List<HisPos>();
        for (var i = 0; i < heights.Length; i++){
            var hp = new HisPos()
            {
                v = heights[i],
                index = i,
            };
            ls.Add(hp);
        }
        ls.Sort((a, b) =>
        {
            if(a.v == b.v) return a.index - b.index;
            return a.v - b.v;
        });
        var lastMin = 0;
        lsRegion = new List<VT>();
        lsRegion.Add((-1, ls.Count));
        var maxArea = 0;
        var usedRegion = new HashSet<int>();
        var collectPoints = new List<int>();
        for (var i = 0; i < ls.Count; )
        {
            var li = ls[i];
            //1 1 1 1 2 2 2 3 3 3
            if (li.v == lastMin)
            {
                var findRg = false;
                VT frg = (0, 0);
                collectPoints.Add(li.index);
                var rgId = FindRegion(lsRegion, li.index);
                //Console.WriteLine("rgID:" + rgId+":"+li.v+":"+li.index);
                // DumpRegion();
                if(!usedRegion.Contains(rgId)){
                    findRg = true;
                    frg = lsRegion[rgId];
                }
                if (findRg)
                {
                    usedRegion.Add(rgId);
                    var wid = frg.Item2 - frg.Item1 + 1 - 2;
                    var hei = li.v;
                    var ar = wid * hei;
                    maxArea = Math.Max(ar, maxArea);
                    //Console.WriteLine("MaxA:" + ar + ":" + maxArea);
                }
                i++;
            }
            else //if (li.v > lastMin)
            {
                usedRegion.Clear();
                foreach (var p in collectPoints)
                {
                    CutRegion(lsRegion, p);
                }
                collectPoints.Clear();
                lastMin = li.v;
            }
        }
        return maxArea;
    }
    // static void Main(string[] arg)
    // {
    //     var hg = new Histogram();
    //     var r = hg.LargestRectangleArea(new int[] {2,1,5,6,2,3 });
    //     Console.WriteLine(r+":"+hg.total);
    // }
}

public class Solution {
    public int LargestRectangleArea(int[] heights) {
        var hg = new Histogram();
        return hg.LargestRectangleArea(heights);
    }
}
```