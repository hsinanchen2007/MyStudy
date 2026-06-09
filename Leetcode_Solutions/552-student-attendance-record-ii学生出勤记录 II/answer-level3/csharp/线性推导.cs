### 解题思路
A位移位置，切分N长度数组
L数量最多2 可构成开头结构
P
LP
LLP


### 代码

```csharp

using VT = System.ValueTuple<bool, int, int>;
using VT2 = System.ValueTuple<int, int>;

class StudentAtten{
    private const UInt64 ModV = 1000000000 + 7;
    private Dictionary<VT, UInt64> cache = new Dictionary<VT, ulong>();
    private Dictionary<VT2, UInt64> cache2 = new Dictionary<VT2, ulong>();
    public int totalNum = 0;
    private UInt64 Award(bool hasA, int preL, int leftLen){
        totalNum++;
        if(leftLen <= 0) return 1;
        var key = (hasA, preL, leftLen);
        if(cache.ContainsKey(key)) return cache[key];

        if(hasA && preL == 2){
            //必须P
            var r = Award(hasA, 0, leftLen - 1);
            cache.Add(key, r);
            return r;
        }
        if(hasA){
            //preL == 0 1
            var l = Award(hasA, preL + 1, leftLen - 1);
            var p = Award(hasA, 0, leftLen - 1);
            var r = (l + p)%ModV;
            cache.Add(key, r);
            return r;
        }
        if(preL == 2){
            //a P
            var a = Award(true, 0, leftLen - 1);
            var p = Award(hasA, 0, leftLen - 1);
            var r = (a + p)%ModV;
            cache.Add(key, r);
            return r;
        }

        //A L P
        {
            var a = Award(true, 0, leftLen - 1);
            var l = Award(hasA, preL + 1, leftLen - 1);
            var p = Award(hasA, 0, leftLen - 1);
            a += l;
            a %= ModV;
            a += p;
            a %= ModV;
            cache.Add(key, a);
            return a;
        }

    }
    private UInt64 NoA(int preL, int leftLen){
        totalNum++;
        if(leftLen <= 0) return 1;    
        var key = (preL, leftLen);
        if(cache2.ContainsKey(key)) return cache2[key];
        //无法分割
        if (leftLen < 12)
        {
            if (preL == 2)
            {
                //分割两部分
                var p = NoA(0, leftLen - 1);
                cache2.Add(key, p);
                return p;
            }
            //A L P
            {
                var l = NoA(preL + 1, leftLen - 1);
                var p = NoA(0, leftLen - 1);
                ulong a = 0;
                a += l;
                a %= ModV;
                a += p;
                a %= ModV;
                cache2.Add(key, a);
                return a;
            }
        }else {//分割两部分
            var first = leftLen / 2;
            var second = first;
            if((leftLen%2) == 1) second++;
            if(preL == 2){
                ulong total = 0;
                //只能P开头
                //P PLL 结尾
                var a1 = NoA(0, first - 4);
                var a2 = NoA(2, second);
                a1 *= a2;
                a1 %= ModV;
                //P PL
                var b1 = NoA(0, first - 3);
                var b2 = NoA(1, second);
                b1 *= b2;
                b1 %= ModV;
                //P P
                var c1 = NoA(0, first - 2);
                var c2 = NoA(0, second);
                c1 *= c2;
                c1 %= ModV;
                total += a1;
                total %= ModV;
                total += b1;
                total %= ModV;
                total += c1;
                total %= ModV;
                cache2.Add(key, total);
                return total;
            }else {
                //可以+1 可以不加
                //P开头
                ulong total = 0;
                //只能P开头
                //P PLL 结尾
                var a1 = NoA(0, first - 4);
                var a2 = NoA(2, second);
                a1 *= a2;
                a1 %= ModV;
                //P PL
                var b1 = NoA(0, first - 3);
                var b2 = NoA(1, second);
                b1 *= b2;
                b1 %= ModV;
                //P P
                var c1 = NoA(0, first - 2);
                var c2 = NoA(0, second);
                c1 *= c2;
                c1 %= ModV;
                total += a1;
                total %= ModV;
                total += b1;
                total %= ModV;
                total += c1;
                total %= ModV;

                //L+1 开头 LL结尾
                //L PLL
                var d1 = NoA(preL+1, first - 4);
                var d2 = NoA(2, second);
                d1 *= d2;
                d1 %= ModV; 
                //L PL
                var e1 = NoA(preL+1, first - 3);
                var e2 = NoA(1, second);
                e1 *= e2;
                e1 %= ModV;
                //L P
                var f1 = NoA(preL+1, first - 2);
                var f2 = NoA(0, second);
                f1 *= f2;
                f1 %= ModV;

                total += d1;
                total %= ModV;
                total += e1;
                total %= ModV;
                total += f1;
                total %= ModV;

                cache2.Add(key, total);
                return total;
            }
        }  
    }
    private Dictionary<int, UInt64> cache3 = new Dictionary<int, UInt64>();
    private UInt64 OnlyP(int leftLen){
        totalNum++;
        if(leftLen <= 0) return 1;
        if(leftLen == 1) return 2;//L P
        if(leftLen == 2) return 4;//PP PL LP LL
        if(cache3.ContainsKey(leftLen)) return cache3[leftLen];
        // if(leftLen >= 3){
            //P LP LLP
            var a = OnlyP(leftLen - 1);
            var b = OnlyP(leftLen - 2);
            var c = OnlyP(leftLen - 3);
            a += b;
            a %= ModV;
            a += c;
            a %= ModV;
            cache3.Add(leftLen, a);
            return a;
        // }
    }
    public int CheckRecord(int n) {
        // var r = Award(false, 0, n);
        //没有A
        // var na = NoA(0, n);
        for (var i = 3; i < n; i++){
            OnlyP(i);
        }
        var na = OnlyP(n);
        //1个A切割
        for (var i = 0; i < n; i++){
            var rightLeft = n - i - 1;
            var leftLeft = i;
            // var ln = OnlyP(0, leftLeft);
            // var rn = NoA(0, rightLeft);
            var ln = OnlyP(leftLeft);
            var rn = OnlyP(rightLeft);
            ln = ln* rn;
            ln %= ModV;
            na += ln;
            na %= ModV;
        }
        return (int)na;
    }
    //PLLP
    //PLL
    //PL
    //P

    // static void Main(string[] arg)
    // {
    //     // var r = a.CheckRecord(1);
    //     // for (var i = 3; i < 100; i++)
    //     {
    //         var a = new StudentAtten();
    //         // var r = a.CheckRecord(100000);
    //         // var r = a.CheckRecord(100000);
    //         var r = a.CheckRecord(12);//14071
    //         // var r = a.CheckRecord(75633);
    //         // var r = a.CheckRecord(99991);
    //         Console.WriteLine(r + ":" + a.totalNum);
    //     }

    // }
}
public class Solution {
    public int CheckRecord(int n) {
        var a = new StudentAtten();
        return a.CheckRecord(n);
    }
}
```