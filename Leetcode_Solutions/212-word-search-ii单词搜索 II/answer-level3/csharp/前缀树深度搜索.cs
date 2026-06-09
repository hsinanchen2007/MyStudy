### 解题思路
分析所有word 构成前缀树
针对board上每个 Char， 从root出发，向四个方向寻找一个Match

### 代码

```csharp
using VT = System.ValueTuple<int, int>;

class PrefixNode {
    public char c;
    public Dictionary<char, PrefixNode> childrens = new Dictionary<char, PrefixNode>();
    public int endWord = -1;
}
class SearState{
    public VT pos;
    public PrefixNode curNode;
    public int nDir = -1;
}
class WordSearch2{
    public IList<string> FindWords(char[][] board, string[] words) {
        var root = new PrefixNode();
        var index = 0;
        var headHash = new HashSet<char>();
        foreach(var w in words){
            var curN = root;
            foreach(var c in w){
                curN.childrens.TryAdd(c, new PrefixNode()
                {
                    c = c,
                });
                curN = curN.childrens[c];
            }
            curN.endWord = index;
            index++;
            headHash.Add(w[0]);
        }

        var headPoints = new List<VT>();
        for (var i = 0; i < board.Length; i++){
            for (var j = 0; j < board[i].Length; j++){
                var c = board[i][j];
                if(headHash.Contains(c))  headPoints.Add((i, j));
            }
        }

        var findEnd = new HashSet<int>();
        foreach(var hp in headPoints){
            // var openQueue = new Queue<(VT, PrefixNode)>();
            // openQueue.Enqueue((hp, root));
            var stack = new List<SearState>();
            stack.Add(new SearState()
            {
                pos = hp,
                curNode = root,
                nDir = -1,
            });
            var visNode = new HashSet<VT>();
            visNode.Add(hp);
            while(stack.Count > 0){
                var top = stack[stack.Count - 1];
                var pos = top.pos;
                var curNode = top.curNode;
                var c = board[pos.Item1][pos.Item2];
                if(curNode.childrens.ContainsKey(c)){
                    curNode = curNode.childrens[c];
                    if(curNode.endWord != -1){//找到一个单词
                        findEnd.Add(curNode.endWord);
                    }
                    var neibor = new List<VT>()
                    {
                        (pos.Item1-1, pos.Item2),
                        (pos.Item1+1, pos.Item2),
                        (pos.Item1, pos.Item2-1),
                        (pos.Item1, pos.Item2+1),
                    };
                    var findPos = -1;
                    for (var i = top.nDir + 1; i < 4; i++)
                    {
                        top.nDir = i;
                        var n = neibor[i];
                        if(visNode.Contains(n)) continue;
                        if (n.Item1 >= 0 && n.Item1 < board.Length
                            && n.Item2 >= 0 && n.Item2 < board[0].Length)
                        {
                            findPos = i;
                            break;
                        }
                    }
                    if(findPos != -1){
                        var n = neibor[findPos];
                        visNode.Add(n);
                        var newS = new SearState()
                        {
                            pos = n,
                            curNode = curNode,
                            nDir = -1,
                        };
                        stack.Add(newS);
                    }else {
                        stack.RemoveAt(stack.Count - 1);
                        visNode.Remove(top.pos);
                    }
                }else {
                    stack.RemoveAt(stack.Count - 1);
                    visNode.Remove(top.pos);
                }
            }
        }
        var ret = new List<string>();
        foreach(var f in findEnd){
            ret.Add(words[f]);
        }
        return ret;
    }   
    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testWS2.json");
    //     var b = JsonSerializer.Deserialize<char[][]>(l[0]);
    //     var w = JsonSerializer.Deserialize<string[]>(l[1]);


    //     var ws = new WordSearch2();
    //     var r= ws.FindWords(b, w);
    //     Console.WriteLine(JsonSerializer.Serialize(r));

    // }
}
public class Solution {
    public IList<string> FindWords(char[][] board, string[] words) {
         var ws = new WordSearch2();
         return ws.FindWords(board, words);
    }
}
```