### 解题思路
对单词按照长度分组
对组按照长度排序
遍历每个组
对所有单词建立 前缀树
每个组只能和 长度>= 自己的单词 构成列
对单词树预先处理，得到每个分支的最长单词长度
对每个字母预测其最长单词，整个单词中最短的长度就是 可能最大的面积
根据面积大小过滤掉 小于等于的 分支



### 代码

```csharp
class TireNode{
    public int maxDeep = 0;
    public char c;
    public Dictionary<char, TireNode> nextNode = new Dictionary<char, TireNode>();
    public HashSet<int> endWord = new HashSet<int>();//哪些单词结束了
}
class TireStack {
    public int wN;
    public List<TireNode> curNodes = new List<TireNode>();
}
class WordRect
{
    private TireNode root = new TireNode();
    private string DumpStack(List<string> list, List<TireStack> stack) {
        var sb = new StringBuilder();
        sb.AppendLine(list.Count + ":" + stack.Count+":"+list[0]);
        for (var i = 0; i < stack.Count; i++){
            sb.AppendLine(stack[i].wN.ToString());
            if (stack[i].wN >= 0)
            {
                sb.AppendLine(list[stack[i].wN]);
            }
        }
        return sb.ToString();
    }
    private List<string> GetMaxRet(List<string> list, List<TireStack> stack){
        var ret = new List<string>();
        for (var i = 0; i < stack.Count; i++){
            if (stack[i].wN >= 0)
            {
                ret.Add(list[stack[i].wN]);
            }
        }
        return ret;
    }
    public int total = 0;
    //每条Path有个MaxLen 如果MaxLen < 当前Len 则应该在之前处理过了 
    //从小宽度 到 大宽度排序
    private void SetTreeMaxDeep(TireNode node){
        var md = 1;
        foreach(var c in node.nextNode){
            SetTreeMaxDeep(c.Value);
            md = Math.Max(md, c.Value.maxDeep + 1);
        }
        node.maxDeep = md;
    }
    public string[] MaxRectangle(string[] words)
    {
        var dictLen = new Dictionary<int, List<string>>();
        var index = 0;
        int maxLen = 0;
        foreach (var w in words)
        {
            dictLen.TryAdd(w.Length, new List<string>());
            dictLen[w.Length].Add(w);
            maxLen = Math.Max(w.Length, maxLen);

            var curNode = root;
            foreach (var c in w)
            {
                curNode.nextNode.TryAdd(c, new TireNode()
                {
                    c = c,
                });
                curNode = curNode.nextNode[c];
            }
            curNode.endWord.Add(index++);
        }
        //按单词长度分类 
        //按单词前缀 构成树
        //单词可以重复
        //单词可以乱序 C(M,N)
        //第一个单词
        //第二个单词
        //第三个单词 最大长度不超过单词最大长度
        //求最大面积
        //1000Row * 100Col
        //遍历所有单词组
        var maxArea = 0;
        List<string> ret = new List<string>();
        var sortDict = new List<(int, List<string>)>();
        foreach(var wd in dictLen) sortDict.Add((wd.Key, wd.Value));
        //单词宽度从窄到宽
        sortDict.Sort((a, b) => { return a.Item1 - b.Item1; });
        SetTreeMaxDeep(root);

        foreach (var wd in sortDict)
        {
            var list = wd.Item2;
            var stack = new List<TireStack>();
            var ts = new TireStack()
            {
                wN = -1,
            };
            //开始都是Root节点
            for (var i = 0; i < wd.Item1; i++)
            {
                ts.curNodes.Add(root);
            }
            stack.Add(ts);
            while (stack.Count > 0)
            {
                total++;
                var top = stack[stack.Count - 1];
                var allOver = true;
                for (var i = 0; i < top.curNodes.Count; i++)
                {
                    var tn = top.curNodes[i];
                    if (tn.endWord.Count == 0)
                    {
                        // Console.WriteLine("EndWord:" + tn.endWord.First());
                        allOver = false;
                        break;
                    }
                }
                if (allOver)
                {
                    // Console.WriteLine("allOver:" + DumpStack(list, stack));
                    var na = wd.Item1 * (stack.Count - 1);
                    if(na > maxArea) {
                        maxArea = na;
                        ret = GetMaxRet(list, stack);
                    }
                }
                // >= curNeedDeep
                var curNeedDeep = wd.Item1;
                var findAWord = false;
                while (top.wN < (list.Count - 1))
                {
                    top.wN++;
                    var w = list[top.wN];
                    var findAllNext = true;
                    // var allOver = true;
                    var nextStack = new TireStack()
                    {
                        wN = -1,
                    };
                    var allMinDepth = Int32.MaxValue;
                    for (var i = 0; i < top.curNodes.Count; i++)
                    {
                        var c = w[i];
                        var tn = top.curNodes[i];
                        if (!tn.nextNode.ContainsKey(c))
                        {
                            findAllNext = false;
                            break;
                        }
                        var nc = tn.nextNode[c];
                        var totalDeep = nc.maxDeep + stack.Count-1;
                        // Console.WriteLine("totalDeep:" + nc.maxDeep + ":" + stack.Count+":"+curNeedDeep);
                        //深度不够 需要比当前深度深的字符串
                        if(totalDeep < curNeedDeep) {
                            findAllNext = false;
                            break;
                        }
                        allMinDepth = Math.Min(totalDeep, allMinDepth);
                        // top.curNodes[i] = tn.nextNode[c];
                        nextStack.curNodes.Add(tn.nextNode[c]);
                        // var nextC = tn.nextNode[c];
                        //不是所有单词都结束
                        // if (nextC.endWord.Count == 0) allOver = false;
                    }
                    if (findAllNext)
                    {
                        var newArea = allMinDepth * wd.Item1;
                        //需要新面积更大才有意义
                        if (newArea > maxArea)
                        {
                            findAWord = true;
                            stack.Add(nextStack);
                            break;
                        }
                    }
                }
                if (!findAWord)
                {
                    stack.RemoveAt(stack.Count - 1);
                }
            }
        }
        return ret.ToArray();
    }
    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testWR.json");
    //     var w = JsonSerializer.Deserialize<string[]>(l[0]);

    //     var wr = new WordRect();
    //     // var r = wr.MaxRectangle(new string[] { "this", "real", "hard", "trh", "hea", "iar", "sld" });
    //     var r = wr.MaxRectangle(new string[] { "aa" });
    //     // var r = wr.MaxRectangle(w);
    //     Console.WriteLine(wr.total+":"+JsonSerializer.Serialize(r));
    // }
}
public class Solution {
    public string[] MaxRectangle(string[] words) {
        var wr = new WordRect();
        return wr.MaxRectangle(words);
    }
}
```