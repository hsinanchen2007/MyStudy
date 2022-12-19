### 解题思路
拆分字符串为 两部分
第一个 回文 和 后面部分
后面部分 必然是一个最优解 且 不受前面部分影响
独立 计算 所有组合 中最优解

### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class PalStr{
    public Dictionary<VT, int> cache = new Dictionary<VT, int>();
    private string ss;
    private int maxK;
    public Dictionary<VT, int> changeC = new Dictionary<VT, int>();
    private int MinPal(int start, int end){
        var key = (start, end);
        if(changeC.ContainsKey(key)) return changeC[key];

        var len = end - start + 1;
        var mid = (start + end) / 2;
        var mod = len % 2;
        var changeNum = 0;
        if(mod == 0){
            var left = (start, mid);
            var right = (mid + 1, end);
            for (var i = left.Item1; i <= left.Item2; i++){
                var delta = i - left.Item1;
                var rpos = right.Item2 - delta;
                if(ss[i] != ss[rpos]) changeNum++;
            }
        }else {
            var left = (start, mid - 1);
            var right = (mid + 1, end);
            for (var i = left.Item1; i <= left.Item2; i++){
                var delta = i - left.Item1;
                var rpos = right.Item2 - delta;
                if(ss[i] != ss[rpos]) changeNum++;
            }
        }
        changeC.Add(key, changeNum);
        return changeNum;
    }
    public int total = 0;
    private int MinChange(int start, int leftK){
        total++;
        var leftChar = ss.Length - start;
        if(leftChar < leftK) return -1;
        if(leftChar <= 0) return 0;
        if(leftK <= 0) return 0;
        if(leftK == 1){
            return MinPal(start, ss.Length - 1);
        }

        var key = (start, leftK);
        if(cache.ContainsKey(key)) return cache[key];

        var endC = leftChar - leftK;
        var minV = Int32.MaxValue;
        for (var i = 0; i < (endC + 1); i++){
            var num = MinPal(start, start + i);
            var after = MinChange(start + i + 1, leftK - 1);
            if(after != -1){
                // Console.WriteLine(i+":"+num+":"+after+":"+start+":"+leftK);
                minV = Math.Min(minV, num + after);
            }
        }
        if(minV == Int32.MaxValue) minV = -1;
        cache.Add(key, minV);
        return minV;
    }
    public int PalindromePartition(string s, int k) {
        ss = s;
        maxK = k;
        return MinChange(0, k);
    }   
}

public class Solution {
    public int PalindromePartition(string s, int k) {
        var ps = new PalStr();
        return ps.PalindromePartition(s, k);
    }
}
```