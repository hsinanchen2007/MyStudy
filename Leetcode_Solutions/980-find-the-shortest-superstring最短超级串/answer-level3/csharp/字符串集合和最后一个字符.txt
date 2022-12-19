### 解题思路
对于每个字符串 可以通过hash 快速比较子串是否相等
每个字符串 记录 和自己尾部有交集的字符串集合
字符串集合 可以通过int 存储
递归 子状态 当前剩余字符串集合 和 最后一个结尾字符串



### 代码

```csharp
using VT = System.ValueTuple<int, int>;
using VT2 = System.ValueTuple<uint, int>;
class WordH {
    public Dictionary<UInt64, int> head;
    public Dictionary<UInt64, int> tail;
    public List<UInt64> headH = new List<ulong>();
    public List<UInt64> tailH = new List<ulong>();
    //对象 长度
    public Dictionary<int, int> tailRela = new Dictionary<int, int>();
    public int tailSet = 0;
    public string wd;
    public void InitTail(){
        tailSet = 0;
        foreach(var tr in tailRela){
            tailSet |= 1 << tr.Key;
        }
        //Console.WriteLine("wId:" + tailSet);
    }
}
class SmallSuper{
    private Dictionary<VT2, int> cache = new Dictionary<VT2, int>();
    private Dictionary<VT2, int> minSelect = new Dictionary<VT2, int>();
    //head Tail Len
    public Dictionary<VT, int> pairShareLen = new Dictionary<VT, int>();
    //最短长度
    public int total = 0;
    private int MinLen(UInt32 wordSet, int lastIndex){
        total++;
        //最短长度字符串
        if(wordSet == 0) return 0;
        var key = (wordSet, lastIndex);
        if(cache.ContainsKey(key)) return cache[key];
        var ml = Int32.MaxValue;
        if(lastIndex == -1){
            //任意选择一个现在残留字符串作为Head
            for (var i = 0; i < wordList.Count; i++){
                var vl = ((UInt32)1) << i;
                if((vl & wordSet) > 0){
                    var totalLen = 0;
                    totalLen += wordList[i].wd.Length;
                    totalLen += MinLen(wordSet & (~vl), i);
                    if (totalLen < ml)
                    {
                        ml = Math.Min(ml, totalLen);
                        minSelect[key] = i;
                    }
                }
            }
        }else {
            var wd = wordList[lastIndex];
            for (var i = 0; i < wordList.Count; i++)
            {
                var vl = ((UInt32)1) << i;
                if ((vl & wordSet) > 0)
                {
                    var totalLen = 0;
                    var inter = (wd.tailSet & vl) > 0;
                    if (inter)
                    {
                        var len = pairShareLen[(lastIndex, i)];
                        totalLen += wordList[i].wd.Length - len;
                        totalLen += MinLen(wordSet & (~vl), i);
                        if (totalLen < ml)
                        {
                            ml = Math.Min(ml, totalLen);
                            minSelect[key] = i;
                        }
                    }else {
                        totalLen += wordList[i].wd.Length;
                        totalLen += MinLen(wordSet & (~vl), i);
                        if (totalLen < ml)
                        {
                            minSelect[key] = i;
                            ml = Math.Min(ml, totalLen);
                        }
                    }
                }
            }
        }
        cache.Add(key, ml);
        return ml;
    }
    public List<WordH> wordList;
    public string ShortestSuperstring(string[] A) {
        //bad abc
        //head tail 所有排列中 前后融合最短的 prefix suffix
        //一个完全包含另外一个
        //部分相交 前相交 后相交
        //完全不相交
        //len = 20  num = 12
        //12!排列
        //12*11 关系

        //headHash len hash list<int>
        //tailHash len hash List<int> 快速判断两个但是 是否包含 是否 相交 相交最大
        wordList = new List<WordH>();
        for (var i = 0; i < A.Length; i++)
        {
            var wh = new WordH();
            var headDict = new Dictionary<UInt64, int>();//hash len
            var w = A[i];
            wh.wd = w;
            UInt64 sum = 0;
            UInt64 coff = 1;
            for (var j = 0; j < w.Length; j++){
                sum += coff * (UInt64)(w[j]-'a'+1);
                coff *= 31;
                headDict.Add(sum, j+1);
                wh.headH.Add(sum);
            }
            var tailDict = new Dictionary<UInt64, int>();
            sum = 0;
            coff = 31;
            for (var j = w.Length - 1; j >= 0; j--){
                sum *= coff;
                sum += (UInt64)(w[j] - 'a' + 1);
                tailDict.Add(sum, w.Length-j);
                wh.tailH.Add(sum);
            }
            wh.head = headDict;
            wh.tail = tailDict;
            wordList.Add(wh);
        }
        //没有关系的互相隔离 只寻找有关系的组
        for (var i = 0; i < A.Length; i++){
            var w1 = wordList[i];
            for (var j = i+1; j < A.Length; j++){
                var w2 = wordList[j];
                //maxLen RelationShip
                var findLen = -1;
                for (var k = Math.Min(w1.tailH.Count, w2.headH.Count)-1; k >= 0; k--){
                    // var tailOff = w1.tailH.Count - k-1;
                    if(w1.tailH[k] == w2.headH[k]){
                        findLen = k;
                        break;
                    }
                }
                if(findLen >= 0){
                    pairShareLen.Add((i, j), findLen + 1);
                    w1.tailRela.Add(j, findLen+1);
                    // w2.headRela.Add(i, findLen + 1);
                }
                findLen = -1;
                for (var k = Math.Min(w1.headH.Count, w2.tailH.Count) - 1; k >= 0; k--)
                {
                    // var tailOff = w2.tailH.Count - k - 1;
                    if(w1.headH[k] == w2.tailH[k]){
                        findLen = k;
                        break;
                    }
                }
                if (findLen >= 0)
                {
                    findLen++;
                    pairShareLen.Add((j, i), findLen);
                    // w1.headRela.Add(j, findLen);
                    w2.tailRela.Add(i, findLen);
                }
            }
        }
        foreach(var w in wordList){
            w.InitTail();
        }
        UInt32 v = 0;
        for (var i = 0; i < A.Length; i++) v |= (UInt32)1 << i;
        var ml = MinLen(v, -1);
        // return ml;
        //Console.WriteLine(ml);
        return GetStr();
    }
    private string GetStr(){
        uint v = 0;
        for (var i = 0; i < wordList.Count; i++) v |= (UInt32)1 << i;
        var sb = new List<int>();
        uint curSet = v;
        var key = (curSet, -1);
    Loop:
        var curLen = cache[key];
        var sw = minSelect[key];
        //Console.WriteLine("L:" + key + ":" + curLen+":"+sw);
        sb.Add(sw);

        var vs = (uint)1 << sw;
        curSet = curSet & (~vs);
        if (curSet > 0)
        {
            key = (curSet, sw);
            if(!minSelect.ContainsKey(key)) key = (curSet, -1);
            goto Loop;
        }

        var sbd = new StringBuilder();
        //Console.WriteLine(JsonSerializer.Serialize(sb));
        var last = -1;
        for (var i = 0; i < sb.Count; i++){
            var n = sb[i];
            var pa = (last, n);
            if(pairShareLen.ContainsKey(pa)){
                var fl = pairShareLen[pa];
                var sub = wordList[n].wd.Substring(fl);
                sbd.Append(sub);
            }else {
                sbd.Append(wordList[n].wd);
            }
            last = n;
        }
        var ssr = sbd.ToString();
        //Console.WriteLine(ssr.Length);
        return ssr;
    }
    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testSmall.json");
    //     var s = JsonSerializer.Deserialize<string[]>(l[0]);
    //     var rr  = JsonSerializer.Deserialize<string>(l[1]);

    //     ////Console.WriteLine("Ret:" + rr.Length);

    //     var ss = new SmallSuper();
    //     var r = ss.ShortestSuperstring(s);
    //     //Console.WriteLine(r+":"+ss.total);
    //     // var str = ss.GetStr();
    //     // ////Console.WriteLine(str);
    //     //[1,3,2,0,4]
    //     /*
    //     Pairs:(4, 0):4
    //     Pairs:(2, 1):3
    //     Pairs:(1, 3):4
    //     Pairs:(2, 3):2
    //     13240
    //     */
    //     foreach(var c in ss.cache){
    //         //Console.WriteLine("CA:" + c.Key + ":" + c.Value);
    //     }
    //     foreach(var ms in ss.minSelect){
    //         //Console.WriteLine("MINS:" + ms.Key + ":" + ms.Value);
    //     }
    //     foreach(var pa in ss.pairShareLen){
    //         //Console.WriteLine("Pairs:" + pa.Key + ":" + pa.Value);
    //     }
    // }

}
public class Solution {
    public string ShortestSuperstring(string[] A) {
        var ss = new SmallSuper();
        return ss.ShortestSuperstring(A);
    }
}
```