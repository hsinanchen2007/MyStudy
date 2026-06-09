### 解题思路
字符和 快速比较子串 是否有相同数量的字符
字符加权乘积 快速比较 字符串是否相等
递归比较 S1 S2 长度 Len 的子串是否 为扰乱子串

### 代码

```csharp
using VT = System.ValueTuple<int, int, int>;
class ScramStr
{
    private List<UInt64> hash1, hash2, sameHash1, sameHash2;
    private string S1, S2;
    //s1, s2, len
    private Dictionary<VT, bool> cache = new Dictionary<VT, bool>();
    public int totalCount = 0;
    //如果彻底没有交换 则 算扰乱吗？
    private bool IsSc(int s1, int e1, int s2, int e2)
    {
        totalCount++;
        // Console.WriteLine(key);
        //叶子相等即可
        if (s1 == e1)
        {
            var fs = S1[s1];
            var ss = S2[s2];
            if (fs == ss)
            {
                // cache[key] = true;
                return true;
            }
            // cache[key] = false;
            return false;
        }
        //整个Node相等
        UInt64 sH1 = 0;
        UInt64 startS1 = 0;
        if (s1 > 0)
        {
            sH1 = hash1[s1 - 1];
            startS1 = sameHash1[s1 - 1];
        }
        UInt64 sH2 = 0;
        UInt64 startS2 = 0;
        if (s2 > 0)
        {
            sH2 = hash2[s2 - 1];
            startS2 = sameHash2[s2 - 1];
        }

        var same1 = sameHash1[e1] - startS1;
        var same2 = sameHash2[e2] - startS2;
        if(same1 != same2) return false;//字符数量不匹配
        var deltaHash1 = hash1[e1] - sH1;
        var deltaHash2 = hash2[e2] - sH2;
        if(deltaHash1 == deltaHash2){
            // Console.WriteLine("SameHash:"+key+":" +deltaHash1+":"+deltaHash2);
            // cache[key] = true;
            return true;
        } 
        var key = (s1, s2, e1 - s1);
        if(cache.ContainsKey(key)) return cache[key];
        //s1s1 s1+1,e1-> s1,e1-1, e1e1
        for (var i = s1; i < e1; i++)
        {
            //S1 gr eat 交换 或者 不交换
            var fir1 = (s1, i);
            var sec1 = (i + 1, e1);

            var delta = i - s1;
            var fir2 = (s2, delta + s2);
            var sec2 = (delta + s2 + 1, e2);

            var ss = false;
            var ss2 = false;
            //不交换
            ss = IsSc(fir1.Item1, fir1.Item2, fir2.Item1, fir2.Item2);
            if(ss){
                ss2 = IsSc(sec1.Item1, sec1.Item2, sec2.Item1, sec2.Item2);
            }
            if(ss && ss2){
                cache[key] = true;
                return true;
            }

            //尝试交换一下
            var tl = e1 - s1;
            var delta2 = i - s1;
            var delta3 = e1 - (i + 1);
            fir2 = (e2 - delta2, e2);
            sec2 = (s2, s2 + delta3);
            ss = false;
            ss2 = false;
            ss = IsSc(fir1.Item1, fir1.Item2, fir2.Item1, fir2.Item2);
            if(ss){
                ss2 = IsSc(sec1.Item1, sec1.Item2, sec2.Item1, sec2.Item2);
            }
            if (ss && ss2)
            {
                cache[key] = true;
                return true;
            }
        }
        cache[key] = false;
        return false;
    }
    public bool IsScramble(string s1, string s2)
    {
        S1 = s1;
        S2 = s2;
        hash1 = new List<ulong>();
        hash2 = new List<ulong>();
        sameHash1 = new List<ulong>();
        sameHash2 = new List<ulong>();
        UInt64 curH = 0;
        UInt64 curOff = 1;
        UInt64 sh = 0;
        for (var i = 0; i < s1.Length; i++)
        {
            curH += (UInt64)(s1[i]-'a'+1) * curOff;
            curOff *= 31;
            hash1.Add(curH);
            sh += (UInt64)(s1[i]);
            sameHash1.Add(sh);
        }
        curH = 0;
        curOff = 1;
        sh = 0;
        for (var i = 0; i < s2.Length; i++)
        {
            curH += (UInt64)(s2[i]-'a'+1)  * curOff;
            curOff *= 31;
            hash2.Add(curH);
            sh += (UInt64)(s2[i]);
            sameHash2.Add(sh);
        }
        //great rg eat
        //first One Split Group 1 4 
        return IsSc(0, s1.Length - 1, 0, s2.Length - 1);
    }
    // static void Main(string[] arg)
    // {
    //     var ss = new ScramStr();
    //     var r = ss.IsScramble("great", "rgeat");
    //     // var r = ss.IsScramble("abcde", "caebd");
    //     // var r = ss.IsScramble("aaccd", "acaad");
    //     Console.WriteLine(r+":"+ss.totalCount+":"+ObjectDumper.Dump(ss.cache));
    //     // Console.WriteLine(JsonSerializer.Serialize(ss.hash1));
    //     // Console.WriteLine(JsonSerializer.Serialize(ss.hash2));
    // }
}
public class Solution {
    public bool IsScramble(string s1, string s2) {
        var ss = new ScramStr();
        return ss.IsScramble(s1, s2);
    }
}
```