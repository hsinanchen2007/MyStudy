### 解题思路
不考虑Evil的时候，动态规划计数 s1<= <=s2 字符串数量
分为四种状态 
In 两种之间 
Great 大于下界  
Small 小于上界
Any 任意字符满足条件

考虑Evil的时候，再加一个状态，当前字符串最大匹配位置
使用KMP 算法进行递推，根据当前位置，以及是否匹配 决定读取下一个字符之后，最大匹配位置

所以子状态就是 
当前 字符串推进位置 StartPos, 当前需要满足的条件State, 以及Evil字符串的匹配进度

### 代码

```csharp

using VT = System.ValueTuple<int, State, int>;
class KMPCmp{
    private List<int> lps;
    private string pattern;
    // public int jPatPos;
    public void InitSearch(string pat){
        // jPatPos = 0;//当前匹配位置
        pattern = pat;
        lps = new List<int>();
        ComputeLPSArray();
    }
    public bool IsCurMatch(ref int jPatPos){
        //匹配模式回到开头
        if(jPatPos == pattern.Length){
            jPatPos = lps[jPatPos - 1];
            return true;
        }
        return false;
    }
    //输入一个字符寻找当前匹配的位置 0为没有匹配
    public int FindMatchPos(int jPatPos, char c){
        while (true)
        {
            if (pattern[jPatPos] == c) //该位置匹配 则 向后移动一个位置
            {
                jPatPos++;
                return jPatPos; //匹配了若干个 返回非0
            }
            if (pattern[jPatPos] != c)//该位置不匹配 则 向前移动到某个位置进行检查
            {
                if (jPatPos != 0)
                {
                    jPatPos = lps[jPatPos - 1];
                }
                else
                {
                    return jPatPos; //完全不匹配 返回0
                }
            }
        }
        return jPatPos;
    }
    // public void Search(string pat, string txt){
    //     var M = pat.Length;
    //     var N = txt.Length;
    //     pattern = pat;
    //     lps = new List<int>();
    //     ComputeLPSArray();
    //     int i = 0; // index for txt[] 
    //     //当前Pattern位置
    //     var j = 0;
    //     while (i < N) {
    //         Console.WriteLine("MatchInfo:" + i + ":" + j);
    //         if (pat[j] == txt[i]) { 
    //             j++; 
    //             i++; 
    //         } 
    //         if (j == M) { 
    //             Console.Write("Found pattern "
    //                           + "at index " + (i - j)); 
    //             j = lps[j - 1]; 
    //         } 
  
    //         // mismatch after j matches 
    //         else if (i < N && pat[j] != txt[i]) { 
    //             // Do not match lps[0..lps[j-1]] characters, 
    //             // they will match anyway 
    //             if (j != 0) 
    //                 j = lps[j - 1]; 
    //             else
    //                 i = i + 1; 
    //         } 
    //     } 
    // }
    private void ComputeLPSArray(){
        var len = 0;
        for (var i = 0; i < pattern.Length; i++) lps.Add(0);
        var ii = 1;
        while(ii < pattern.Length){
            if(pattern[ii] == pattern[len]){
                len++;
                lps[ii] = len;
                ii++;
            }else {
                if(len != 0){
                    len = lps[len - 1];
                }else {
                    lps[ii] = len;
                    ii++;
                }
            }
        }
        // Console.WriteLine(JsonSerializer.Serialize(lps));
    }
    // public static void Main() 
    // { 
    //     string txt = "ABABDABACDABABCABAB"; 
    //     string pat = "ABABCABAB";
    //     var kmp = new KMPCmp();
    //     kmp.InitSearch(pat);
    //     // kmp.Search(pat, txt); 
    //     var jpos = 0;
    //     for (var i = 0; i < txt.Length; i++)
    //     {
    //         jpos = kmp.FindMatchPos(jpos, txt[i]);
    //         if(kmp.IsCurMatch(ref jpos)){
    //             Console.WriteLine("FindMatch:" + (i-pat.Length+1));
    //         }
    //     }

    //     var v = 'a' + 1;
    //     Console.WriteLine((char)v);
    // } 
}
enum State
{
    IN,
    Great,
    Small,
    Any,
}
class AllGood{
    private const UInt64 ModV = 1000000000 + 7;
    private string S1, S2;
    private string Evil;
    
    public int total = 0;
    // private List<ulong> threeOneValue = new List<ulong>();
    // private void InitThreeOne(){
    //     ulong coff = 1;
    //     for (var i = 0; i < Evil.Length; i++){
    //         threeOneValue.Add(coff);
    //         coff *= 31;
    //     }
    //     Console.WriteLine("Three:" + JsonSerializer.Serialize(threeOneValue));
    // }
    private Dictionary<VT, ulong> cache = new Dictionary<VT, ulong>();
    //状态空间太大了preHash 压缩到0 1 2 3 --> pat Len 状态
    //KMP 状态
    private UInt64 GetTNum(int startPos, State state, int jPos){
        total++;
        // Console.WriteLine("GT:" + startPos + ":"+state+":"+preHash);
        // if(preHash == evilHash) return 0;
        if(jPos == Evil.Length) return 0;//Match了
        if (startPos >= S1.Length)
        {
            return 1;
        }
        //当前前缀 所在状态 
        // var hS = 0;
        // if(hashToState.ContainsKey(preHash)){
        //     hS = hashToState[preHash];
        // }
        var key = (startPos, state, jPos);
        if(cache.ContainsKey(key)) return cache[key];
        //0 为无hash状态
        // var preLen = startPos;
        // var removeFirst = false;
        // var curLen = preLen;
        // //移除第一个字符 计算newHash preString 1 ~ 26 < 31
        // //evilLength >= 1 <= 50
        // if(preLen >= Evil.Length){
        //     removeFirst = true;
        //     curLen = Evil.Length - 1;
        // }
        // ulong toAddHash = preHash;
        // ulong firstChar = 0;
        // if(removeFirst){
        //     firstChar = preHash % 31;
        //     toAddHash = preHash / 31;
        // }
        // Console.WriteLine("preLen:"+removeFirst+":"+toAddHash+":"+firstChar);

        var c1 = S1[startPos];
        var c2 = S2[startPos];
        //aa da b 之间 寻找字符 aa da
        if (state == State.IN)//两者之间
        {
            //aa = ad  aa < dd
            UInt64 a = 0;
            if (c1 == c2){ //ax 
                // var p = toAddHash +(UInt64)(c1-'a'+1) * threeOneValue[curLen];
                var nPos = kmpMatch.FindMatchPos(jPos, c1);
                a = 1 * GetTNum(startPos + 1, State.IN, nPos);//返回在之间的
            }else {//c1 < c2  ax
                // var p = toAddHash + (UInt64)(c1 - 'a' + 1) * threeOneValue[curLen];
                var nPos = kmpMatch.FindMatchPos(jPos, c1);
                a = 1 * GetTNum(startPos + 1, State.Great, nPos);
            }
            //== c1  > c1 < c2 == c2
            //aa < dd   bx
            UInt64 b = 0;
            if (c2 > (c1 + 1))
            {
                for (var i = c1 + 1; i < c2; i++)
                {
                    // var p = toAddHash + (UInt64)(i - 'a' + 1) * threeOneValue[curLen];
                    var nPos = kmpMatch.FindMatchPos(jPos, (char)i);
                    b += GetTNum(startPos + 1, State.Any, nPos);
                    b %= ModV;
                }
                // b = (UInt64)(c2 - c1 - 1) * 
                // b %= ModV;
            }
            //ad < dd  dx
            UInt64 c = 0;
            //Extra c2
            if (c2 > c1)
            {
                // var pc = toAddHash + (UInt64)(c2 - 'a' + 1) * threeOneValue[curLen];
                var nPos = kmpMatch.FindMatchPos(jPos, c2);
                c = 1 * GetTNum(startPos + 1, State.Small, nPos);
            }
            a += b;
            a %= ModV;
            a += c;
            a %= ModV;
            cache.Add(key, a);
            return a;
        }
        //aa <  dd  aX--> Great
        //>= a 只要>= a即可
        if(state == State.Great){
            //== c1 c1+1-->Z
            //a 
            // var pa = toAddHash + (UInt64)(c1 - 'a' + 1) * threeOneValue[curLen];
            var nPos = kmpMatch.FindMatchPos(jPos, c1);
            var a = 1 * GetTNum(startPos + 1, State.Great, nPos);
            //c1+1 -> z
            UInt64 b = 0;
            if(c1 < 'z'){
                for (var i = c1 + 1; i <= 'z'; i++)
                {
                    // var pb = toAddHash + (UInt64)(i - 'a' + 1) * threeOneValue[curLen];
                    var nPos2 = kmpMatch.FindMatchPos(jPos, (char)i);
                    b += GetTNum(startPos + 1, State.Any, nPos2);
                    b %= ModV;
                    // b = (UInt64)('z' - c1) * GetTNum(startPos + 1, State.Any);
                }
                // b %= ModV;
            }
            a += b;
            a %= ModV;
            cache.Add(key, a);
            return a;
        }
        //AnyCharCanUse 'a'->'z'
        if(state == State.Any){
            UInt64 ret = 0;
            for (var i = 'a'; i <= 'z'; i++){
                // var pa = toAddHash + (UInt64)(i - 'a' + 1) * threeOneValue[curLen];
                var nPos = kmpMatch.FindMatchPos(jPos, (char)i);
                ret += GetTNum(startPos + 1, State.Any, nPos);
                ret %= ModV;
            }
                // var len = S1.Length - startPos;
                // var num = (UInt64)('z' - 'a' + 1);
                // UInt64 ret = 1;
                // for (var i = 0; i < len; i++){
                //     ret *= num;
                //     ret %= ModV;
                // }
            cache.Add(key, ret);
            return ret;
        }
        //aa dd  dx 
        if(state == State.Small){
            //c2
            // var pa = toAddHash + (ulong)(c2 - 'a' + 1) * threeOneValue[curLen];
            var nPos = kmpMatch.FindMatchPos(jPos, c2);
            var a = 1 * GetTNum(startPos + 1, State.Small, nPos);
            UInt64 b = 0;
            //a -> c2-1
            if(c2 > 'a'){
                for (var i = 'a'; i < c2; i++){
                    // var pb = toAddHash + (ulong)(i - 'a' + 1) * threeOneValue[curLen];
                    var nPos2 = kmpMatch.FindMatchPos(jPos, i);
                    b += GetTNum(startPos + 1, State.Any, nPos2);
                    b %= ModV;
                }
                // b = ((UInt64)(c2 - 'a')) * GetTNum(startPos + 1, State.Any);
            }
            a += b;
            a %= ModV;
            cache.Add(key, a);
            return a;
        }
        return 0;
    }
    // private UInt64 evilHash;
    // public List<UInt64> evilHashLen = new List<ulong>();
    // private Dictionary<UInt64, int> hashToState = new Dictionary<ulong, int>();
    public KMPCmp kmpMatch;
    public int FindGoodStrings(int nnn, string s1, string s2, string evil)
    {
        //N aa da
        //b
        //>= aa <= da
        //aa ab ac ad af az ba ca da
        //a >= after
        S1 = s1;
        S2 = s2;
        Evil = evil;
        // evilHash = 0;
        kmpMatch = new KMPCmp();
        kmpMatch.InitSearch(Evil);
        // ulong coff = 1;
        // for (var i = 0; i < evil.Length; i++)
        // {
        //     evilHashLen.Add(evilHash);
        //     hashToState.Add(evilHash, i);
        //     // evilHash *= 31;
        //     evilHash += (UInt64)(evil[i] - 'a' + 1)*coff;
        //     coff *= 31;
        // }
        // hashToState.Add(evilHash, evil.Length);
        // Console.WriteLine("EH:" + evilHash+":"+JsonSerializer.Serialize(evilHashLen));
        // InitThreeOne();
        //判断两个大小
        // var startIndex = -1;
        // for (var i = 0; i < s1.Length; i++){
        //     if(s1[i] != s2[i]){
        //         if(s1[i] > s2[i]) return 0; //开头> 结尾
        //         startIndex = i;
        //         break;
        //     }
        // }
        // if(startIndex == -1) return 1;//两个相等
        return (int)GetTNum(0, State.IN, 0);
    }
    //500980409:485
    //500543753
    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testGood.json");
    //     var n = JsonSerializer.Deserialize<int>(l[0]);
    //     var s1 = JsonSerializer.Deserialize<string>(l[1]);
    //     var s2 = JsonSerializer.Deserialize<string>(l[2]);
    //     var evil = JsonSerializer.Deserialize<string>(l[3]);


    //     var ag = new AllGood();
    //     // var r = ag.FindGoodStrings(2, "aa", "da", "b");
    //     // var r = ag.FindGoodStrings(2, "leetcode", "leetgoes", "leet");
    //     // var r = ag.FindGoodStrings(2, "le", "le", "le");
    //     var r = ag.FindGoodStrings(n, s1, s2, evil);
    //     // var r = ag.FindGoodStrings(2, "gzxxxx", "gzzzzz", "xxxx");
    //     Console.WriteLine(r+":"+ag.total);
    //     // foreach(var kv in ag.cache){
    //     //     Console.WriteLine("KV:" + kv.Key + ":" + kv.Value);
    //     // }
    // }
}

public class Solution {
    public int FindGoodStrings(int n, string s1, string s2, string evil) {
        var ag = new AllGood();
        return ag.FindGoodStrings(n, s1, s2, evil);
    }
}
```