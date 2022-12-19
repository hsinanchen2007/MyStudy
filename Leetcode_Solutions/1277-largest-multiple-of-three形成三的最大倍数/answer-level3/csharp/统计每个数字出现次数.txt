### 解题思路
数字从大到小排序
统计每个数字出现次数
%3 == 0 数字 必然全在结果中
接着对 %3 != 0 每个数字的数量进行推导
每个数字最多三种情况数量 0 1 2

### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class LargeNum{

    private int[] D;
    // private string MaxNum(int start, int preSum, StringBuilder sb){
    //     if(start >= D.Length) {
    //         if(preSum % 3 == 0){
    //             return sb.ToString();
    //         }
    //         return string.Empty;
    //     }
    //     //使用start 不使用start
    //     // sb.Append(D[start]);
    //     var newSb = 
    //     var m2 = MaxNum(start+1, preSum, sb);
    //     var m1 = MaxNum(start + 1, (preSum + D[start]) % 3, sb);
    // }
    //后面比我大需要比我长 否则我第一个数字 >= 后面第一个数字
    //如果相等的话 
    //0 1 2
    // private VT MaxSumTo(int sv, int start, int end){
    //     if(start > end){
    //         if(sv != 0)return (false, string.Empty);
    //         return (true, string.Empty);
    //     }
    //     if(start == end){
    //         var v = D[start];
    //         if((v%3) != sv) return (false, string.Empty);
    //         return (true, v.ToString());
    //     }
    //     var mid = start + end;
    //     if(sv == 0){ //12 21 00
    //         var s1 = MaxSumTo(1, start, mid);
    //         var s2 = MaxSumTo()
    //     }else if(sv == 1){//01 10 22

    //     }else {//11 02 20

    //     }

    // }
    //999 888 777 666 555 444 333 222 111 000
    private List<VT> needCal;
    // private List<VT> empty = new List<VT>();
    //Length 最长
    //Length 相等 前面数字比后面数字大
    private int SumLen(List<VT> tl){
        var l = 0;
        for (var i = 0; i < tl.Count; i++){
            l += tl[i].Item2;
        }
        return l;
    }
    private bool Great(List<VT> t1, List<VT> t2){
        if(t1 == null) return false;
        if(t2 == null) return true;

        var l1 = SumLen(t1);
        var l2 = SumLen(t2);
        //比较长度
        if(l1 > l2) return true;
        if(l1 < l2) return false;
        //比较每个部分大小
        for (var i = 0; i < t1.Count; i++){
            if(t1[i].Item1 > t2[i].Item1) return true;
            if(t1[i].Item1 < t2[i].Item1) return false;
            if(t1[i].Item2 > t2[i].Item2) return true;
            if(t1[i].Item2 < t2[i].Item2) return false;
        }
        return false;
    }
    private Dictionary<VT, List<VT>> cache = new Dictionary<VT, List<VT>>();
    private List<VT> MaxV(int start, int preMod){
        //超出长度返回空集
        if(start >= needCal.Count){
            if(preMod != 0) return null;
            return new List<VT>();
        }
        var key = (start, preMod);
        if(cache.ContainsKey(key)) return cache[key];

        var v = needCal[start];
        List<VT> curMax = null;
        for (var i = v.Item2; i >= v.Item2 - 2 && i >= 0; i--){
            //当前选择 i i-1 i-2
            var modV = (v.Item1*i) % 3;
            var curMod = (modV + preMod) % 3;
            var ret1 = MaxV(start + 1, curMod);
            List<VT> t1 = null;
            if(ret1 != null){
                // ret1.Insert(0, (v.Item1, i));
                // t1 = ret1;
                t1 = new List<VT>();
                t1.Add((v.Item1, i));
                t1.AddRange(ret1);
                if(Great(t1, curMax)) curMax = t1;
            }
        }
        cache[key] = curMax;
        return curMax;
    }
    public string LargestMultipleOfThree(int[] digits) {
        Array.Sort(digits, (a,b)=>{
            return b - a;
        });
        D = digits;
        if(D[0] == 0) return "0";
        //Console.WriteLine(JsonSerializer.Serialize(digits));
        //从大到小排序数字
        //优先选择最大的数值
        //长度 和 大小的平衡
        // return MaxNum(0, 0);
        // return MaxSumTo(0, 0, digits.Length-1);
        // var numCount = new Dictionary<int, int>();
        var curNum = -1;
        var curCount = 0;
        var numCount = new List<VT>();
        for (var i = 0; i < D.Length; i++){
            if(D[i] != curNum){
                if(curCount > 0) numCount.Add((curNum, curCount));
                curNum = D[i];
                curCount = 1;
            }else{
                curCount++;
            }
        }
        if(curCount > 0)numCount.Add((curNum, curCount));
        needCal = new List<VT>();
        for (var i = 0; i < numCount.Count; i++){
            //有三因数
            if ((numCount[i].Item1 % 3) != 0)
            {
                needCal.Add(numCount[i]);
            }
        }
        //Console.WriteLine(ObjectDumper.Dump(numCount));
        //8555 555 855
        // var usedNum = new Dictionary<int, int>();
        //preSumMod curIndex 0 ~ N个 
        //9 8 ~0
        // for (var i = 0; i < numCount.Count; i++){
        //     var nv = numCount[i];
        //     var cv = nv.Item1 * nv.Item2;
        //     if((cv % 3) == 0){
        //     }
        // }
        //返回Dictionary 1 2 4 5 7 8 各个的数量
        //Mod 0 1 2
        //(Item1*Item2) % 3 == 1 2
        //数量N N-1 N-2 三种可能 N-2%3 == 0可能

        //长度最长 大小最大
        var ret = MaxV(0, 0);
        var dictNeedNum = new Dictionary<int, int>();
        //10000
        if(ret == null){//
        }else
        {
            foreach (var v in ret)
            {
                if(v.Item2 > 0) dictNeedNum.Add(v.Item1, v.Item2);
            }
        }
        var sb = new StringBuilder();
        for (var i = 0; i < numCount.Count; i++){
            var nc = numCount[i];
            if((nc.Item1 % 3) == 0){
                for (var j = 0; j < nc.Item2; j++) sb.Append(nc.Item1);
            }else if(dictNeedNum.ContainsKey(nc.Item1)) {
                for (var j = 0; j < dictNeedNum[nc.Item1]; j++) sb.Append(nc.Item1);
            }
        }
        var s = sb.ToString();
        if(s.Length == 0) return s;
        if(s[0] == '0') return "0";
        return s;
    }

    // static void Main(string[] arg)
    // {
    //     var ln = new LargeNum();
    //     // var r = ln.LargestMultipleOfThree(new int[] { 8, 1, 9 });
    //     // var r = ln.LargestMultipleOfThree(new int[] { 8,6,7,1,0 });
    //     // var r = ln.LargestMultipleOfThree(new int[] { 3 });
    //     // var r = ln.LargestMultipleOfThree(new int[] { 0,0,0,0,0,0});
    //     var r = ln.LargestMultipleOfThree(new int[] { 1,1,1});
    //     Console.WriteLine(r);
    // }
}
public class Solution {
    public string LargestMultipleOfThree(int[] digits) {
        var ln = new LargeNum();
        return ln.LargestMultipleOfThree(digits);
    }
}
```