### 解题思路
对于某个Start，其子问题 即下一个点的最大长度 和 当前所在位置 是独立的
且整体解 一定是 某个子问题的最优解 构成

### 代码

```csharp
class Jump5{
    private int[] aa;
    private int dd;
    private Dictionary<int, int> cache = new Dictionary<int, int>();
    public int totalCount = 0;
    private int MJ(int start){
        totalCount++;
        // if(start < 0) return 0;
        // if(start >= aa.Length) return 0;
        if(cache.ContainsKey(start)) return cache[start];
        var mj = 1;
        var sh = aa[start];
        for (var i = 1; i <= dd; i++){
            var np = start + i;
            if(np < aa.Length){
                var v = aa[np];
                if(v >= sh) break;
                mj = Math.Max(mj, 1 + MJ(np));
            }else break;
        }
        for (var i = 1; i <= dd; i++){
            var np = start - i;
            if(np >= 0){
                var v = aa[np];
                if(v >= sh) break;
                mj = Math.Max(mj, 1 + MJ(np));
            }else break;
        }
        cache.Add(start, mj);
        return mj;
    }
    public int MaxJumps(int[] arr, int d) {
        aa = arr;
        dd = d;
        var mj = 1;
        for (var i = 0; i < arr.Length; i++){
            mj = Math.Max(mj, MJ(i));
        }
        return mj;
    }
}

public class Solution {
    public int MaxJumps(int[] arr, int d) {
        var j5 = new Jump5();
        return j5.MaxJumps(arr, d);
    }
}
```