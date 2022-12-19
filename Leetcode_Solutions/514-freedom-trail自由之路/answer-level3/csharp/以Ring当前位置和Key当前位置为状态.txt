### 解题思路
所有动态规划问题，本质是独立子状态的递推
这里以Ring Key 位置为状态
Cache这些状态结果
Ring旋转最小值 到达某个目标位置

### 代码

```csharp
using VT = System.ValueTuple<int,int>;
class RingBoard{
    public int total = 0;
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    private int FindMS(int ar, int sk){
        total++;
        if(sk >= K.Length) return 0;
        var key = (ar, sk);
        if(cache.ContainsKey(key)) return cache[key];
        var minStep = Int32.MaxValue;
        if(R[ar] == K[sk]){ //不动最好
            var t1 = FindMS(ar, sk + 1)+1;
            minStep = Math.Min(minStep, t1);
        }else {
            var cp = charPos[K[sk]];
            foreach(var p in cp){
                var dist1 = Math.Abs(ar - p);
                var dist2 = Math.Abs(ar + R.Length - p) % R.Length;
                var dist3 = Math.Abs(p + R.Length - ar) % R.Length;
                var dist = Math.Min(dist1, dist2);
                dist = Math.Min(dist3, dist);
                var t1 = FindMS(p, sk+1)+dist+1;
                minStep = Math.Min(minStep, t1);
            }
        }
        cache.Add(key, minStep);
        return minStep;
    }
    private string R, K;
    private Dictionary<char, List<int>> charPos = new Dictionary<char, List<int>>();
    public int FindRotateSteps(string ring, string key)
    {
        R = ring;
        K = key;
        for (var i = 0; i < R.Length; i++)
        {
            var c = R[i];
            charPos.TryAdd(c, new List<int>());
            charPos[c].Add(i);
        }
        //遍历问题
        //当前Ring位置
        return FindMS(0, 0);
    }
    // static void Main(string[] arg)
    // {
    //     var tr = File.ReadAllLines("testRing.json");
    //     var rj = JsonSerializer.Deserialize<string>(tr[0]);
    //     var k = JsonSerializer.Deserialize<string>(tr[1]);


    //     var rb = new RingBoard();
    //     // var r = rb.FindRotateSteps("godding", "gd");
    //     var r = rb.FindRotateSteps(rj, k);
    //     Console.WriteLine(r + ":" + rb.total);
    //     foreach(var d in rb.cache){
    //         Console.WriteLine("cache:" + d.Key + ":"+d.Value);
    //     }
    // }
}
public class Solution {
    public int FindRotateSteps(string ring, string key) {
        var rb = new RingBoard();
        return rb.FindRotateSteps(ring, key);
    }
}
```