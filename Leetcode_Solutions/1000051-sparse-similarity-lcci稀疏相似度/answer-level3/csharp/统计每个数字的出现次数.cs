### 解题思路
统计每个数字出现在哪些集合中
统计数字 构成的集合 对，以及每个对交集的数字数量


### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class SimDoc{
    public IList<string> ComputeSimilarities(int[][] docs) {
        var dict = new Dictionary<int, HashSet<int>>();
        for (var i = 0; i < docs.Length; i++){
            for (var j = 0; j < docs[i].Length; j++){
                var v = docs[i][j];
                if(!dict.ContainsKey(v)){
                    dict[v] = new HashSet<int>();
                }
                dict[v].Add(i);
            }
        }
        //稀疏相似
        // var greatD = new Dictionary<int, HashSet<int>>();
        // //可能相交的元素
        // foreach(var v in dict){
        //     if(v.Value.Count > 1) greatD.Add(v.Key, v.Value);
        // }
        //超过1个可能相似
        // var setCountG = new Dictionary<int, HashSet<int>>();
        // foreach(var v in greatD){
        //     foreach(var vv in v.Value){
        //         if(!setCountG.ContainsKey(vv)){
        //             setCountG[vv] = new HashSet<int>();//每个集合 可能和其它集合相交的元素
        //         }
        //         setCountG[vv].Add(v.Key);//元素
        //     }
        // }
        //任意两个集合的相似度
        var pairs = new Dictionary<VT, int>();
        foreach(var v in dict){
            //Console.WriteLine("V:"+v.Key+":"+v.Value.Count);
            if (v.Value.Count > 1)
            {
                var ls = v.Value.ToList();
                //Console.WriteLine(JsonSerializer.Serialize(ls));
                for (var i = 0; i < ls.Count; i++)
                {
                    for (var j = i + 1; j < ls.Count; j++)
                    {
                        var id1 = Math.Min(ls[i], ls[j]);
                        var id2 = Math.Max(ls[i], ls[j]);
                        // pairs((id1, id2), 0);
                        var k = (id1, id2);
                        //Console.WriteLine("id1:" + k);
                        if (!pairs.ContainsKey(k)) pairs.Add(k, 0);
                        pairs[k]++;
                        //Console.WriteLine("pair:" + k + ":" + pairs[k]);
                    }
                }
            }
        }
        var sim = new Dictionary<VT, double>();
        foreach(var v in pairs){
            var l1 = docs[v.Key.Item1].Length;
            var l2 = docs[v.Key.Item2].Length;
            //Console.WriteLine("PR:"+v.Key+":"+v.Value+":"+l1+":"+l2);
            sim.Add(v.Key, v.Value * 1.0 /(l1+l2-v.Value));
        }
        var ret = new List<string>();
        foreach(var s in sim){
            var ss = string.Format("{0},{1}: {2:0.0000}", s.Key.Item1, s.Key.Item2, s.Value);
            ret.Add(ss);
        }
        return ret;
    }
}
public class Solution {
    public IList<string> ComputeSimilarities(int[][] docs) {
        var sd = new SimDoc();
        return sd.ComputeSimilarities(docs);
    }
}
```