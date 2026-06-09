### 解题思路
每个Start位置 进行Cache
使用字符串Hash 作为Key快速比较字符串

### 代码

```csharp
using VT = System.ValueTuple<int, int, System.UInt64, System.UInt64>;
using LHash = System.ValueTuple<int, System.UInt64>;
class FindWords{
    //特定位置开始之后裁剪的数据
    public Dictionary<int, (bool, List<string>)> cache = new Dictionary<int, (bool, List<string>)>();
    private List<string> empty = new List<string>(){
        string.Empty,
    };
    private string S;
    private int MaxLen;
    public int total = 0;
    private List<string> WB(int start, out bool isOk){
        total++;
        // Console.WriteLine("start:"+start+":" + S.Length+":"+MaxLen);
        if (start >= S.Length)
        {
            isOk = true;
            return empty;
        }
        if (cache.ContainsKey(start))
        {
            isOk = cache[start].Item1;
            return cache[start].Item2;
        }
        var ret = new List<string>();
        // var stack = new List<VT>();//eachWord StartPos
        //start End curHash curCoff
        VT top = (start, start-1, 0, 1);
        // while (stack.Count > 0)
        while(true)
        {
            // var top = stack[stack.Count - 1];
            var findMatch = false;
            var curH = top.Item3;
            var curCoff = top.Item4;
            for (var i = top.Item2 + 1; i < S.Length; i++)
            {
                curH += curCoff * (UInt64)(S[i] - 'a' + 1);
                curCoff *= 31;
                top.Item2 = i;
                top.Item3 = curH;
                top.Item4 = curCoff;
                if (dict.ContainsKey(curH))
                {
                    findMatch = true;
                    break;
                }
                var curLen = i - top.Item1 + 1;
                if (curLen >= MaxLen) break;
            }
            // Console.WriteLine("Top:" + top+":"+findMatch);
            if(findMatch){
                // stack[stack.Count - 1] = top;
                var retLs = WB(top.Item2 + 1, out var okFind);
                if(okFind) {
                    // var curSub = S.Substring(top.Item1, top.Item2 - top.Item1 + 1);
                    var curSub = dict[top.Item3];
                    foreach(var s in retLs){
                        if (s != String.Empty)
                        {
                            ret.Add(curSub + " " + s);
                        }else {
                            ret.Add(curSub);
                        }
                    }
                }
            }else {
                break;
            }
        }
        var findOne = ret.Count > 0;
        if(findOne)
        {
            cache.Add(start, (findOne, ret));
        }else {
            cache.Add(start, (findOne, null));
        }
        isOk = findOne;
        return ret;
    }
    private Dictionary<UInt64, string> dict;
    public IList<string> WordBreak(string s, IList<string> wordDict) {
        // Console.WriteLine("sL:" + s.Length + ":wL:" +wordDict.Count);
        //FirstWord SecondWord ThirdWord
        dict = new Dictionary<UInt64, string>();
        S = s;
        var maxLen = 0;
        // var dictLen = new HashSet<int>();//lenCache
        //每个单词的hash值
        foreach(var w in wordDict){
            UInt64 hv = 0;
            UInt64 coff = 1;
            for (var i = 0; i < w.Length; i++){
                hv += coff * (UInt64)(w[i]-'a'+1);//1~26
                coff *= 31;
            }
            dict.Add(hv, w);
            maxLen = Math.Max(w.Length, maxLen);
            // dictLen.Add(w.Length);//所有各种长度
        }
        MaxLen = maxLen;
        // var lsHashV = new List<List<LHash>>();
        // for (var i = 0; i < s.Length; i++){
        //     var start = i;
        //     UInt64 hv = 0;
        //     UInt64 coff = 1;
        //     var lh = new List<LHash>();
        //     lsHashV.Add(lh);
        //     for (var j = 0; j < maxLen; j++){
        //         var end = i + j;
        //         var curLen = end - start + 1;
        //         if(end < s.Length){
        //             hv += coff *((UInt64)s[end]-'a'+1);
        //             coff *= 31;
        //             if(dictLen.Contains(curLen) && dict.ContainsKey(hv)){
        //                 lh.Add((curLen, hv));
        //             }
        //         }else break;
        //     }
        // }
        // Console.WriteLine(ObjectDumper.Dump(dict));
        // Console.WriteLine("ML:" + maxLen);

        var ret = WB(0, out var isOk);
        if(isOk){
            return ret;
        }else {
            // return empty;
            return new List<string>();
        }

        // var allRet = new List<List<VT>>();
        // var stack = new List<VT>();//eachWord StartPos
        // //start End curHash curCoff lsHashPos
        // stack.Add((0, -1, 0, 1));
        // while(stack.Count > 0){
        //     var top = stack[stack.Count - 1];
        //     var findMatch = false;
        //     var curH = top.Item3;
        //     var curCoff = top.Item4;
        //     for (var i = top.Item2 + 1; i < s.Length; i++){
        //         curH += curCoff * (UInt64)(s[i] - 'a' + 1);
        //         curCoff *= 31;
        //         top.Item2 = i;
        //         top.Item3 = curH;
        //         top.Item4 = curCoff;
        //         if(dict.ContainsKey(curH)){
        //             findMatch = true;
        //             break;
        //         }
        //         var curLen = i - top.Item1 + 1;
        //         if(curLen >= maxLen) break;
        //     }
        //     // Console.WriteLine("topVluae:" + top+":"+findMatch);
        //     if(findMatch){
        //         stack[stack.Count - 1] = top;
        //         //消费了所有的字符了 start End
        //         if(top.Item2 >= s.Length-1){
        //             var ls = new List<VT>();
        //             ls.AddRange(stack);
        //             allRet.Add(ls);
        //             Console.WriteLine("FindOne:"+allRet.Count);
        //         }
        //         stack.Add((top.Item2 + 1, top.Item2, 0, 1));
        //     }else {
        //         stack.RemoveAt(stack.Count - 1);
        //     }

        // }
        // var lt = new List<string>();
        // foreach(var l in allRet){
        //     var sb = new StringBuilder();
        //     var first = true;
        //     foreach(var w in l){
        //         var ss = s.Substring(w.Item1, w.Item2 - w.Item1 + 1);
        //         if (!first)
        //         {
        //             sb.Append(" ");
        //         }
        //         sb.Append(ss);
        //         first = false;
        //     }
        //     lt.Add(sb.ToString());
        // }
        // return lt;
    }
    // static void Main(string[] arg)
    // {
    //     var ta = File.ReadAllLines("testAA.json");
    //     var l = JsonSerializer.Deserialize<string>(ta[0]);
    //     var wd = JsonSerializer.Deserialize<string[]>(ta[1]);


    //     var fw = new FindWords();
    //     // var ret = fw.WordBreak("catsanddog", new List<string>() { "cat", "cats", "and", "sand", "dog"});
    //     // var ret = fw.WordBreak("aaa", new string[] { "a", "aa", "aaa"});
    //     // var ret = fw.WordBreak("pineapplepenapple", new string[] { "apple", "pen", "applepen", "pine", "pineapple" });
    //     var ret = fw.WordBreak(l, wd);
    //     Console.WriteLine(JsonSerializer.Serialize(ret)+":"+fw.total);
    //     foreach(var c in fw.cache){
    //         Console.WriteLine(c.Key + ":" + JsonSerializer.Serialize(c.Value));
    //     }

    // }
}
public class Solution {
    public IList<string> WordBreak(string s, IList<string> wordDict) {
        var fw = new FindWords();
        return fw.WordBreak(s, wordDict);
    }
}
```