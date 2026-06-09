### 解题思路
每个集合记录 最大和最小值 和 数字总量

### 代码

```csharp
class NumUnion{

    public int v;
    public int max, min;
    public NumUnion parent = null;
    public int totalCount = 1;
    public NumUnion GetTopParent(){
        if(parent == null) return this;
        var p = parent;
        while(p.parent != null){
            p = p.parent;
        }
        this.parent = p;
        return p;
    }
    public static void MergeTwo(NumUnion p1, NumUnion p2){
        p1 = p1.GetTopParent();
        p2 = p2.GetTopParent();
        if(p1 == p2) return;
        p2.parent = p1;
        p1.max = Math.Max(p1.max, p2.max);
        p1.min = Math.Min(p1.min, p2.min);
        p1.totalCount += p2.totalCount;
    }
}
class ConseqList {
    public int LongestConsecutive(int[] nums) {
        //记录Pre 和 Next Index
        var dictU = new Dictionary<int, NumUnion>();

        foreach(var n in nums){
            var nu = new NumUnion()
            {
                v = n,
                max = n, 
                min = n,
                totalCount = 1,
            };
            dictU.TryAdd(n, nu);
        }
        var lst = dictU.Values.ToList();
        foreach(var nu in lst){
            var tp = nu.GetTopParent();
            var max = tp.min - 1;
            var min = tp.max + 1;
            if(dictU.ContainsKey(max)){
                var mn = dictU[max];
                var mp = mn.GetTopParent();
                // NumUnion.MergeTwo(mp, tp);
                NumUnion.MergeTwo(tp, mp);
            }
            if(dictU.ContainsKey(min)){
                NumUnion.MergeTwo(tp, dictU[min]);
            }
        }
        var maxCount = 0;
        foreach(var nu in lst){
            if(nu.parent == null){
                maxCount = Math.Max(maxCount, nu.totalCount);
            }
        }
        return maxCount;
    }
}
public class Solution {
    public int LongestConsecutive(int[] nums) {
        var cl = new ConseqList();
        return cl.LongestConsecutive(nums);
    }
}
```