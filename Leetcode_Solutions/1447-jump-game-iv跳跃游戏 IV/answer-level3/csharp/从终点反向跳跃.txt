### 解题思路
终点 广度优先 确定每个点的最近距离
cache下来结果
直到回到起点

### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class JumpEnd{
    public Dictionary<int, int> cache = new Dictionary<int, int>();
    public Dictionary<int, List<int>> groups = new Dictionary<int, List<int>>();
    //从结束点反向推
    public int MinJumps(int[] arr)
    {
        var index = 0;
        foreach(var a in arr){
            if(!groups.ContainsKey(a)) {
                groups[a] = new List<int>();
            }
            groups[a].Add(index);
            index++;
        }
        var tar = arr.Length - 1;
        var openQ = new Queue<VT>();
        openQ.Enqueue((arr.Length - 1,3));
        cache.Add(tar, 0);

        while(openQ.Count > 0){
            var fir = openQ.Dequeue();
            if(fir.Item1 == 0) break;
            var firDist = cache[fir.Item1];
            var v = arr[fir.Item1];
            //可以跳跃到达目的地
            if ((fir.Item2 & 2) > 0)
            {
                var gv = groups[v];
                foreach (var g in gv)
                {
                    if (!cache.ContainsKey(g))
                    {
                        cache[g] = firDist + 1;
                        openQ.Enqueue((g, 1));//只能移动到目的地
                    }
                }
            }
            //可以移动到目的地
            if((fir.Item2 & 1) > 0){
                if(fir.Item1 > 0){
                    var n = fir.Item1 - 1;
                    if (!cache.ContainsKey(n))
                    {
                        cache[n] = firDist + 1;
                        openQ.Enqueue((n, 3));
                    }
                }
                if(fir.Item1 < arr.Length-1){
                    var n = fir.Item1 + 1;
                    if (!cache.ContainsKey(n))
                    {
                        cache[n] = firDist + 1;
                        openQ.Enqueue((n, 3));
                    }
                }
            }
        }
        return cache[0];
    }
}

public class Solution {
    public int MinJumps(int[] arr) {
        var j = new JumpEnd();
        return j.MinJumps(arr);
    }
}
```