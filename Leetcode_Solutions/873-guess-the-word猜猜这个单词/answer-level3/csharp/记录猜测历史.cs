### 解题思路
统计所有Word之间的相似度
取一个相似Word最多的单词
判断
计入历史
根据结果和历史 查找新的可用猜测单词



### 代码

```csharp
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *     public int Guess(string word);
 * }
 */

class Solution{
    private class WS{
        public int index;
        public int totalNum = 0;
        public Dictionary<int, List<int>> similarMap = new Dictionary<int, List<int>>();
        public Dictionary<int, HashSet<int>> simHash = new Dictionary<int, HashSet<int>>();
    }
    public int Similar(string a, string b)
    {
        var total = 0;
        for (var i = 0; i < 6; i++){
            if(a[i] == b[i]) total++;
        }
        return total;
    }
    public void FindSecretWord(string[] wordlist, Master master)
    {
        if(wordlist.Length == 0) return;
        var dict = new Dictionary<int, WS>();
        var lsSim = new List<WS>();
        for (var i = 0; i < wordlist.Length; i++)
        {
            lsSim.Add(new WS()
            {
                index = i,
            });
            dict.Add(i, lsSim[i]);
        }
        //构建相似矩阵
        for (var i = 0; i < wordlist.Length; i++)
        {
            var s1 = lsSim[i];
            for (var j = i + 1; j < wordlist.Length; j++)
            {
                var s2 = lsSim[j];
                var sv = Similar(wordlist[i], wordlist[j]);
                if(sv > 0){
                    s1.totalNum++;
                    s2.totalNum++;
                }
                s1.similarMap.TryAdd(sv, new List<int>());
                s2.similarMap.TryAdd(sv, new List<int>());
                s1.similarMap[sv].Add(j);
                s2.similarMap[sv].Add(i);

                s1.simHash.TryAdd(sv, new HashSet<int>());
                s2.simHash.TryAdd(sv, new HashSet<int>());
                s1.simHash[sv].Add(j);
                s2.simHash[sv].Add(i);
            }
        }
        //相似度最高的
        // lsSim.Sort((a, b) =>
        // {
        //     return b.totalNum - a.totalNum;
        // });
        var hashCheck = new HashSet<int>();
        WS curMax = lsSim[0];
        foreach(var s in lsSim){
            if(s.totalNum > curMax.totalNum) curMax = s;
        }
        // var pairList = new List<(int, int)>();
        var curSim = curMax;
        hashCheck.Add(curSim.index);
        //wordIndex Similar
        var history = new List<(int, int)>();

    GuessMatch:
        var first = wordlist[curSim.index];
        var ret = master.Guess(first);
        if(ret == 6) return;
        history.Add((curSim.index, ret));
        // Console.WriteLine("His:" + history[history.Count - 1]);
        // pairList.Add((curSim.index, ret));
        var newSet = curSim.similarMap[ret];
        // newSet.Sort((a, b) =>
        // {
        //     return dict[b].totalNum - dict[a].totalNum;
        // });
        var newMax = newSet[0];
        var nextI = 0;
        for (var i = 0; i < newSet.Count; i++){
            nextI = i;
            if(!hashCheck.Contains(newSet[i])) {
                newMax = newSet[i];
                var simOk = true;
                for (var j = 0; j < history.Count-1; j++){
                    var his = history[j];
                    if(!dict[newMax].simHash.ContainsKey(his.Item2)){
                        simOk = false;
                        break;
                    }
                    if(!dict[newMax].simHash[his.Item2].Contains(his.Item1)){
                        simOk = false;
                        break;
                    }
                }
                // break;
                if(simOk) break;
            }
        }
        for (var i = nextI + 1; i < newSet.Count; i++)
        {
            var s = newSet[i];
            if (dict[s].totalNum > dict[newMax].totalNum && !hashCheck.Contains(s))
            {
                var simOk = true;
                for (var j = 0; j < history.Count-1; j++){
                    var his = history[j];
                    if(!dict[s].simHash.ContainsKey(his.Item2)){
                        simOk = false;
                        break;
                    }
                    if(!dict[s].simHash[his.Item2].Contains(his.Item1)){
                        simOk = false;
                        break;
                    }
                }
                if (simOk)
                {
                    newMax = s;
                }
            }
        }
        curSim = dict[newMax];
        hashCheck.Add(newMax);
        goto GuessMatch;

    }

    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testGuess.json");
    //     var s = JsonSerializer.Deserialize<string>(l[0]);
    //     var w = JsonSerializer.Deserialize<string[]>(l[1]);


    //     var ma = new Master();
    //     // ma.secret = "acckzz";`
    //     ma.secret = s;
    //     // ma.wl = new string[] { "acckzz","ccbazz","eiowzz","abcczz"};
    //     ma.wl = w;

    //     var so = new Solution();
    //     so.FindSecretWord(ma.wl, ma);
    // }
}

```