### 解题思路
每三位一组解析
0 1 2 3 1 2 3
量词 根据 当前组 位置决定
个位 需要考虑 十位情况
十位 需要考虑个位 和 十位数情况决定
百位 

### 代码

```csharp
using VT = System.ValueTuple<int, string>;
class ConvertState{
    private enum State {
        Start,
        GeWei,
        Teen,
        Liang,
        Ty,
    }
    private State state = State.Start;
    // private int accZero = 0;
    public static Dictionary<int, string> dict;
    private int GetZeroNum(int z){
        var r = 1;
        for (var i = 0; i < z; i++){
            r *= 10;
        }
        return r;
    } 
    private int GetZWei(int zN){
        if(zN == 0) return 0;
        var r = 0;
        while(zN > 0){
            zN /= 10;
            r++;
        }
        return r-1;
    }
    private VT GetNearZeroNum(int zN, out int usedZ){
        var zW = GetZWei(zN);
        usedZ = zW;
        if(dict.ContainsKey(zN)) return (0, dict[zN]);
        var nn = zN;
        var left = 0;
        while(nn > 0){
            nn /= 10;
            left++;
            usedZ = zW - left;
            if(dict.ContainsKey(nn)) return (left, dict[nn]);
        }
        return (zN, string.Empty);
    }
    public List<string> Parse(int offset, List<int> nb){
        var totalCount = nb.Count;
        var divPart = (totalCount+2) / 3;
        var allRet = new List<string>();
        for (var i = 0; i < divPart; i++){
            var start = i * 3;
            var end = (i + 1) * 3;
            var off = 0;
            var ret = new List<string>();
            for (var j = start; j < end && j < nb.Count; j++){
                var v = nb[j];
                if(v != 0){
                    if(ret.Count == 0 && start > 0){
                        var ni = i;
                        //0 1 2 3 1 2 3 1 2 3
                        if (i > 3)
                        {
                            ni = (i - 1) % 3 + 1;
                        }
                        var liang = ni * 3;
                        // Console.WriteLine("Liant:" + start + ":" + liang);
                        if (liang > 0)
                        {
                            // var liang = start;
                            // if(start > 9) liang %= 3;
                            if (liang > 0)
                            {
                                ret.Add(dict[(int)Math.Pow(10, liang)]);
                            }
                        }
                    }
                    if(off == 0){
                        var wait = false;
                        if(j+1 < nb.Count){
                            if(nb[j+1] ==1) wait = true;
                        }
                        if (!wait)
                        {
                            ret.Add(dict[v]);
                        }
                    }else if(off == 1){
                        if(v == 1){
                            var bv = nb[j - 1];
                            ret.Add(dict[v * 10+bv]);
                        }else
                        {
                            ret.Add(dict[v * 10]);
                        }
                    }else {
                        ret.Add(dict[100]);
                        ret.Add(dict[v]);
                    }
                }
                off++;
            }
            allRet.AddRange(ret);
        }
        allRet.Reverse();
        return allRet;
    }
    // public VT Parse(int offset, List<int> nb){
    //     if(state == State.Start){
    //         var n = nb[offset];
    //         if(n == 0){
    //             // accZero++;
    //             return (offset + 1, string.Empty);
    //         }else { //10 100 1000 10,000 100,000 1000,000 1000,000,000
    //             // var nName = dict[n];
    //             // var zn = GetZeroNum(offset-1);
    //             // var zc = GetNearZeroNum(zn, out var usedZ);
    //             // string str = String.Empty;
    //             // if(usedZ == 1){//Ten 
    //             //     if(nb[offset-1] == 0 || n > 1){
    //             //         str = zc.Item2;
    //             //     }else {// n == 1 && > 0
    //             //         var nv = 10 + nb[offset - 1];
    //             //         str = dict[nv];
    //             //     }
    //             // }else {
    //             //     str = zc.Item2;
    //             // }
    //             // return (offset+1, nName + " " + str);

    //         }
    //     }
    // }
}
class EngToInt{
    private List<VT> liang = new List<VT>(){
        (100, "Hundred"),
        (1000, "Thousand"),
        (1000000, "Million"),
        (1000000000, "Billion"),
    };
    private List<string> nums = new List<string>()
    {
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
    };
    private List<string> teen = new List<string>()
    {
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen",
    };
    private List<string> ty = new List<string>(){
        "Ten",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety",
    };
    public string NumberToWords(int num) {
        var dict = new Dictionary<int, string>();
        foreach(var v in liang){
            dict.Add(v.Item1, v.Item2);
        }
        for (var i = 0; i < nums.Count; i++){
            dict.Add(i, nums[i]);
        }
        for (var i = 0; i < teen.Count; i++){
            dict.Add(i + 11, teen[i]);
        }
        for (var i = 0; i < ty.Count; i++){
            dict.Add((i + 1) * 10, ty[i]);
        }

        var list = new List<int>();
        while(num > 0){
            var mv = num % 10;
            num /= 10;
            list.Add(mv);
        }
        var cs = new ConvertState();
        ConvertState.dict = dict;
        var r = cs.Parse(0, list);
        if(r.Count == 0) r.Add("Zero");
        var w = string.Join(' ', r);
        return w;
        // for (var i = 0; i < list.Count; ){
        //     var r = cs.Parse(i, list);
        //     i = r.Item1;
        //     if(r.Item2.Length > 0){
        //         ret.Add(r.Item2);
        //     }
        // }
    }
    // static void Main(string[] arg)
    // {
    //     var et = new EngToInt();
    //     var w = et.NumberToWords(0);
    //     // var w = et.NumberToWords(123);
    //     // var w = et.NumberToWords(12345);
    //     // var w = et.NumberToWords(1234567);
    //     // var w = et.NumberToWords(1234567891);
    //     // var w = et.NumberToWords(12000001000);
    //     Console.WriteLine(w);

    // }
}
public class Solution {
    public string NumberToWords(int num) {
        var et = new EngToInt();
        return et.NumberToWords(num);
    }
}
```