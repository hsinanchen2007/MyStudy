### 解题思路
cache头位置 是否可以交错

### 代码

```csharp
using VT = System.ValueTuple<int, int, int>;
class InterLeave{
    private string S1, S2, S3;
    private Dictionary<VT, bool> cache = new Dictionary<VT, bool>();
    private int totalNum = 0;
    private bool Inter(int s1, int s2, int tar){
        totalNum++;
        //所有Word消耗完
        if(s1 >= S1.Length && s2 >= S2.Length){
            if(tar < S3.Length) return false;
            return true;
        }
        //没有消耗完
        if(tar >= S3.Length) return false;
        var key = (s1, s2, tar);
        if(cache.ContainsKey(key)) return cache[key];
        if(s1 >= S1.Length){
            var c1 = S2[s2];
            var tc = S3[tar];
            if(c1 != tc) return false;
            var r = Inter(s1, s2 + 1, tar + 1);
            cache.Add(key, r);
            return r;
        }
        if(s2 >= S2.Length){
            var c1 = S1[s1];
            var tc = S3[tar];
            if(c1 != tc) return false;
            var r = Inter(s1 + 1, s2, tar + 1);
            cache.Add(key, r);
            return r;
        }

        var h1 = S1[s1];
        var h2 = S2[s2];
        var th = S3[tar];
        if (h1 != th && h2 != th)
        {
            cache.Add(key, false);
            return false;
        }

        if(h1 == h2){
            var r1 = Inter(s1 + 1, s2, tar + 1);
            var r2 = Inter(s1, s2 + 1, tar + 1);
            var r = r1 || r2;
            cache.Add(key, r);
            return r;
        }else if(h1 == th){
            var r1 = Inter(s1 + 1, s2, tar + 1);
            cache.Add(key, r1);
            return r1;
        }else {
            var r2 = Inter(s1, s2 + 1, tar + 1);
            cache.Add(key, r2);
            return r2;
        }
        return false;
    }
    public bool IsInterleave(string s1, string s2, string s3) {
        S1 = s1;
        S2 = s2;
        S3 = s3;
        return Inter(0, 0, 0);
    }
    // static void Main(string[] arg)
    // {
    //     var il = new InterLeave();
    //     // var r = il.IsInterleave("aabcc", "dbbca", "aadbbcbcac");
    //     var r = il.IsInterleave("aabcc", "dbbca", "aadbbbaccc");
    //     Console.WriteLine(r+":"+il.totalNum);
    // }
}

public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        var il = new InterLeave();
        return il.IsInterleave(s1, s2, s3);
    }
}
```