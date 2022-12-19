### 解题思路
若最小字符存在 大于其的 字符 在其前面，则压入堆栈 处理下一个最小字符
每次处理完当前最小字符， 将堆栈清空到第一层，继续处理

### 代码

```csharp
class MostSmall2{
    //> baseMax
    private int FindUp(List<int> arr, int v){
        var s = 0;
        var e = arr.Count - 1;
        while(s <= e){
            var mid = (s + e) / 2;
            var mv = arr[mid];
            if(mv > v){
                e = mid - 1;
            }else {
                s = mid + 1;
            }
        }
        return s;
    }
    public string RemoveDuplicateLetters(string s)
    {
        var hs = new HashSet<char>();
        foreach(var c in s) hs.Add(c);
        var ls = hs.ToList();
        ls.Sort();
        var charIndex = new Dictionary<char, int>();
        for (var i = 0; i < ls.Count; i++){
            charIndex.Add(ls[i], i);
        }
        //从小到达
        var dictAppear = new Dictionary<char, List<int>>();
        //每个字符出现序列
        for (var i = 0; i < s.Length; i++){
            var c = s[i];
            dictAppear.TryAdd(c, new List<int>());
            dictAppear[c].Add(i);
        }
        var setPosYet = new Dictionary<char, int>();
        var baseMax = -1;
        // var ret = new List<char>();
        var ret = new StringBuilder();
        var stack = new List<char>();
FindNextChar:
        for (var i = 0; i < ls.Count; i++){
            if(!setPosYet.ContainsKey(ls[i])){
                stack.Add(ls[i]);
                break;
            }
        }
        while (stack.Count > 0)
        {
            var top = stack[stack.Count - 1];
            var dp = dictAppear[top];
            //首次出现在baseMax之后的位置 
            var pos = FindUp(dp, baseMax);
            var tryPos = dp[pos];
            var findMinChar = false;
            var minChar = ' ';
            var notSetChar = ' ';
            // Console.WriteLine("FindCharPos:"+top+":"+baseMax+":"+tryPos);
            for (var j = charIndex[top] + 1; j < ls.Count; j++)
            {
                var other = ls[j];
                //尚未处理过位置
                if (!setPosYet.ContainsKey(other))
                {
                    // notSetChar = other;
                    if(notSetChar == ' ') notSetChar = other;
                    var op = dictAppear[other];
                    var oMax = op[op.Count - 1];
                    if (oMax < tryPos)
                    {
                        findMinChar = true;
                        minChar = other;
                        break;
                    }
                }
            }
            //字符比我大 位置比我小
            if(findMinChar){
                stack.Add(notSetChar);
            }else {
                baseMax = tryPos;
                setPosYet.Add(top, ret.Length);
                // ret.Add(top);
                ret.Append(top);
                stack.RemoveAt(stack.Count - 1);
                //删掉只剩下第一层
                while (stack.Count > 1)
                {
                    stack.RemoveAt(stack.Count - 1);
                }
            }
        }
        if(setPosYet.Count < ls.Count) {
            goto FindNextChar;
        }

        // var ret = new List<char>();
        // var baseMax = -1;
        // for (var i = 0; i < ls.Count;i++){
        //     var fir = ls[i];
        //     var dp = dictAppear[fir];
        //     //寻找第一个出现在BaseMax之后的位置
        //     var pos = FindUp(dp, baseMax);
        //     var tryPos = dp[pos];
        //     // baseMax = dp[pos];
        //     var minMaxPos = Int32.MaxValue;
        //     for (var j = i + 1; j < ls.Count; j++){
        //         var other = ls[j];
        //         var op = dictAppear[other];
        //         var oMax = op[op.Count - 1];
        //         if(oMax < tryPos){//比我当前试验的位置小
        //             minMaxPos = Math.Min(minMaxPos, oMax);
        //         }
        //     }
        //     if(minMaxPos < tryPos){

        //     }else {
        //         ret.Add(fir);
        //     }
        // }
        return ret.ToString();
    }
    // static void Main(string[] arg)
    // {
    //     var ms = new MostSmall2();
    //     // var r = ms.RemoveDuplicateLetters("bcabc");
    //     // var r = ms.RemoveDuplicateLetters("cbacdcbc");
    //     // var r = ms.RemoveDuplicateLetters("abacb");
    //     // var r = ms.RemoveDuplicateLetters("cbcba");
    //     // var r = ms.RemoveDuplicateLetters("abacb");
    //     // var r = ms.RemoveDuplicateLetters("cbacdcbc");
    //     var r = ms.RemoveDuplicateLetters("cbaddabaa");
    //     Console.WriteLine(r);
    // }
}
public class Solution {
    public string RemoveDuplicateLetters(string s) {
        var ms = new MostSmall2();
        return ms.RemoveDuplicateLetters(s);
    }
}
```