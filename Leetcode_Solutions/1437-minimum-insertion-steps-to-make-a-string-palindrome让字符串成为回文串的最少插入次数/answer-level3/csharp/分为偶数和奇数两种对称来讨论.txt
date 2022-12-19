### 解题思路
以左右两侧需要对称的部分 来计算最小插入字符数量

### 代码

```csharp
using VT = System.ValueTuple<int,int>;
class StrPal{
    //操作 Insert在某个位置 选择中心
    private string S;
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    public int totalCount = 0;
    private int MIOdd(int leftPos, int rightPos){
        totalCount++;
        //左右为空集
        if(leftPos < 0 && rightPos >= S.Length) return 0;
        if(leftPos < 0){
            return S.Length - rightPos;
        }
        if(rightPos >= S.Length){
            return leftPos + 1;
        }
        var key = (leftPos, rightPos);
        if(cache.ContainsKey(key)) return cache[key];

        if (S[leftPos] == S[rightPos])
        {
            var v = MIOdd(leftPos - 1, rightPos + 1);
            cache.Add(key, v);
            return v;
        }
        var m1 = MIOdd(leftPos - 1, rightPos)+1;
        var m2 = MIOdd(leftPos, rightPos + 1)+1;
        var mv = Math.Min(m1, m2);
        cache.Add(key, mv);
        return mv;
    }
    public int MinInsertions(string s) {
        S = s;
        var mi = Int32.MaxValue;
        //abca 级数对称
        for (var i = 0; i < s.Length; i++){
            mi = Math.Min(mi, MIOdd(i-1, i+1));
        }
        //偶数对称 abccb
        for (var i = 0; i < s.Length-1; i++){
            if(s[i] == s[i+1]){
                mi = Math.Min(mi, MIOdd(i-1, i+2));
            }
        }
        return mi;
    }
}

public class Solution {
    public int MinInsertions(string s) {
        var sp = new StrPal();
        return sp.MinInsertions(s);
    }
}
```