### 解题思路
双手指位置和当前字符位置 的最优解 和 之前的状态是独立的

### 代码

```csharp
using VT = System.ValueTuple<int,int>;

class Board{
    private VT GetCharPos(char c){
        var n = c - 'A';
        var row = n / 6;
        var col = n % 6;
        return (row, col);
    }
    private int GetDist(VT v1, VT v2){
        return Math.Abs(v1.Item1 - v2.Item1) + Math.Abs(v1.Item2 - v2.Item2);
    }
    public bool EqualPos(VT a, VT b){
        return a.Item1 == b.Item1 && a.Item2 == b.Item2;
    }
    public int totalNum = 0;
    private Dictionary<(VT, VT, int), int> cache = new Dictionary<(VT, VT, int), int>();
    private int MinD(VT first, VT second, int start){
        totalNum++;
        if(start >= W.Length) return 0;
        var key = (first, second, start);
        if(cache.ContainsKey(key)) return cache[key];
        var newPos = GetCharPos(W[start]);
        //0距离
        //0距离
        var m1 = Int32.MaxValue;
        var m2 = Int32.MaxValue;
        var m3 = Int32.MaxValue;
        if(EqualPos(first, newPos) || EqualPos(second, newPos)){
            m1 = MinD(first, second, start + 1);
        }else
        {
            if (first.Item1 == -1)
            {
                m2 = MinD(newPos, second, start + 1);
            }
            else
            {
                m2 = MinD(newPos, second, start + 1) + GetDist(newPos, first);
            }
            if (second.Item1 == -1)
            {
                m3 = MinD(first, newPos, start + 1);
            }
            else
            {
                m3 = MinD(first, newPos, start + 1) + GetDist(newPos, second);
            }
        }

        var md = Int32.MaxValue;
        md = Math.Min(md, m1);
        md = Math.Min(md, m2);
        md = Math.Min(md, m3);
        cache.Add(key, md);
        return md;
    }
    private string W;
    public int MinimumDistance(string word) {
        W = word;
        return MinD((-1, -1), (-1, -1), 0);
    }

    // static void Main(string[] arg)
    // {
    //     var b = new Board();
    //     // var r = b.MinimumDistance("CAKE");
    //     // var r = b.MinimumDistance("HAPPY");
    //     // var r = b.MinimumDistance("NEW");
    //     var r = b.MinimumDistance("YEAR");
    //     Console.WriteLine(r+":"+b.totalNum);
    // }
}

public class Solution {
    public int MinimumDistance(string word) {
        var b = new Board();
        return b.MinimumDistance(word);
    }
}
```