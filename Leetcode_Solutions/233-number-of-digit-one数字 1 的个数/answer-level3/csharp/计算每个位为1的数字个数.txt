### 解题思路
每位为1  长度为L  小于等于N的数字数量

### 代码

```csharp
class OneNum{
    private int MaxPos(int maxN){
        var n = 0;
        while(maxN > 0){
            n++;
            maxN /= 10;
        }
        return n;
    }
    private int GetKNum(int kLen){
        // if(kLen == 0) return 1;
        // if(kLen == 1) return 10;
        var b = 1;
        for (var i = 0; i < kLen; i++){
            b *= 10;
        }
        return b;
    }
    //头部部分
    private int HeadSafeNum(int headPart, int maxN){
        if(headPart < 0) return 0;
        if(headPart == 0){
            var mn = MaxPos(maxN);
            mn--;
            var mv = maxN;
            while(mn > 0){
                mn--;
                mv /= 10;
            } 
            if(mv > 1) return mv-1;//安全
            //== 1 不安全
            return 0;
        }

        var start = 1;
        for (var i = 1; i < headPart+1; i++){
            start *= 10;
        }
        // var end = start * 10 - 1;
        var mnLen = MaxPos(maxN);
        var removeLen = mnLen - headPart-1;
        //Console.WriteLine("start:" + start + ":" + headPart + ":" + removeLen);
        while(removeLen > 0){
            removeLen--;
            maxN /= 10;
        }
        return maxN - start;
    }
    private int GetKPosValue(int maxN, int kPos){
        for (var i = 1; i < kPos; i++){
            maxN /= 10;
        }
        return maxN % 10;
    }
    private int GetKTailValue(int maxN, int tailLen){
        var mv = 1;
        for (var i = 1; i <= tailLen; i++){
            mv *= 10;
        }
        return maxN % mv;
    }
    private int Count1InK(int maxN, int kPos, int mP){
        var oneNum = 0;
        for (var i = 1; i < mP; i++){
            if(i < kPos){
                oneNum += 0;
            }else if(i == kPos){
                oneNum += GetKNum(i - 1);
            }else {
                var head = i - kPos;
                var tail = kPos - 1;
                var tn = GetKNum(tail);
                var hn = 9 * GetKNum(head - 1);
                oneNum += hn* tn;
            }
        }
        var headPart = mP - kPos;
        var tailPart = kPos - 1;
        var tAllNum = GetKNum(tailPart);
        headPart--;
        //100->999
        var hs = HeadSafeNum(headPart, maxN);
        //Console.WriteLine("head:" + headPart + ":" + tailPart+":"+tAllNum+":"+hs+":"+oneNum);
        oneNum += hs * tAllNum;
        var vv = GetKPosValue(maxN, kPos);
        //////Console.WriteLine("VV:" + vv);
        if(vv == 0) return oneNum;
        if (vv > 1)
        {
            oneNum += tAllNum;
        }else {
            oneNum += GetKTailValue(maxN, tailPart)+1;
        }
        return oneNum;
    }
    public int CountDigitOne(int n) {
        var mp = MaxPos(n);
        var ret = 0;
        for (var i = 1; i <= mp; i++){
            var cc = Count1InK(n, i, mp);
            ret += cc;
            //Console.WriteLine(n + ":" + i + ":" + mp + ":"+cc+":"+ ret);
        }
        return ret;
    }
    // static void Main(string[] arg)
    // {
    //     var oneN = new OneNum();
    //     // var r = oneN.CountDigitOne(11);
    //     // var r = oneN.CountDigitOne(13);
    //     // var r = oneN.CountDigitOne(100);
    //     // var r = oneN.CountDigitOne(20);
    //     // var r = oneN.CountDigitOne(30);
    //     // var r = oneN.CountDigitOne(110);
    //     var r = oneN.CountDigitOne(120);
    //     //Console.WriteLine(r);

    // }
}
public class Solution {
    public int CountDigitOne(int n) {
        var oneN = new OneNum();
        return oneN.CountDigitOne(n);
    }
}
```