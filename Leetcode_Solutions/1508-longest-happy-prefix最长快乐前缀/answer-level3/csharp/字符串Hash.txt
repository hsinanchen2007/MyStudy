### 解题思路
prefix 做hash
suffix 做逆向hash
hash可迭代
若hash 值相等 且 长度相等 则是一个 最长解

### 代码

```csharp
class HappyPrefix {
    Dictionary<UInt64, int> hashPrefix = new Dictionary<ulong, int>();
    public string LongestPrefix(string s) {
        UInt64 preSum = 0;
        for (var i = 0; i < s.Length-1; i++){
            preSum *= 31;
            preSum += (UInt64)(s[i] - 'a'+1);
            hashPrefix.Add(preSum, i+1);
        }
        var maxHappy = 0;
        UInt64 sufSum = 0;
        UInt64 mulV = 1;
        for (var i = s.Length-1; i > 0; i--){
            // sufSum *= 31;
            sufSum += (UInt64)(s[i] - 'a'+1) * mulV;
            mulV *= 31;
            if(hashPrefix.ContainsKey(sufSum)){
                var sameLen = hashPrefix[sufSum] == (s.Length - i);
                if(sameLen){
                    maxHappy = Math.Max(maxHappy, s.Length - i);
                }
            }
        }
        // return maxHappy;
        if(maxHappy > 0){
            return s.Substring(0, maxHappy);
        }
        return string.Empty;
    }

    // static void Main(string[] arg)
    // {
    //     var hp = new HappyPrefix();
    //     // var r = hp.LongestPrefix("level");
    //     // var r = hp.LongestPrefix("ababab");
    //     // var r = hp.LongestPrefix("leetcodeleet");
    //     // var r = hp.LongestPrefix("a");
    //     var r = hp.LongestPrefix("aaaaa");
    //     Console.WriteLine(r);
    // }
}
public class Solution {
    public string LongestPrefix(string s) {
        var hp = new HappyPrefix();
        return hp.LongestPrefix(s);
    }
}
```