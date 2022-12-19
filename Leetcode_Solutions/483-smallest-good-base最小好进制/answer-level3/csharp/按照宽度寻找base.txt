### 解题思路
base 2 确定最长 宽度 maxLen
base n-1 是 宽度 为2 的base

maxLen-1 ->3
二分查找一个 base 长度为 特定值
若 全是1 则 这个 base 是最长宽度的结果

### 代码

```csharp
class GoodBase2
{
    private UInt64 FindSqrt(UInt64 nv)
    {
        UInt64 s = 2;
        UInt64 e = nv - 1;
        while (s <= e)
        {
            var mid = (s + e) / 2;
            var small = nv / mid;
            var mod = nv % mid;
            // if(mod == 0 && small == mid) return mid;
            //mid^2+mid+1 > nv
            //6 2 5 2 3  
            if (small == mid) return mid;
            if (small > mid)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        //6  110  20 12 11
        return e;
    }
    public int total = 0;
    private UInt64 FindK(UInt64 nv, int len, out bool allOne)
    {
        UInt64 gkStart = 2;
        UInt64 gkEnd = sqr;
        //k^len-1 / k-1 = nv
        //nv > k^(len-1)-1
        //nv < k^(len)-1 
        //(k+1)^len-1/k = nv
        //nv+1 > k^(len-1) < k^(len)
        //(k+1)^(len-1) > k^(len-1) < k^(len-1) * k
        //(k+1/k)^(len-1) < k  k >= 2 len >= 2
        //-1 /k 
        // Console.WriteLine("######len:"+len);
        while (gkStart <= gkEnd)
        {
            var mid = (gkStart + gkEnd) / 2;
            var curNv = nv - 1;
            var i = 0;
            //111 7 6  3 2  1 0
            //9+3+1 = 13 12   false
            allOne = true;
            if((nv%mid) != 1) allOne = false;
            var smallZ = false;
            for (i = 0; i < (len - 1) && curNv > 0; i++)
            {
                total++;
                curNv /= mid;
                if ((curNv % mid) != 1) allOne = false;
                if (curNv > 0)
                {
                    curNv--;
                }else {
                    smallZ = true;
                    break;
                }
            }
            // Console.WriteLine("Mid:" + mid+":"+gkStart+":"+gkEnd+":"+curNv+":"+smallZ+":"+i+":"+allOne);
            // if (curNv > 0 && (curNv / mid) == 0)
            // if(curNv == 0 && allOne && !smallZ) {
            //     return mid;
            // }
            //刚好结束 但是没有allOne
            if (curNv == 0 && i == (len - 1) && !smallZ && allOne)
            {
                return mid;
            }
            if (!smallZ && i == (len-1))
            {
                gkStart = mid + 1;
            }
            else
            {
                gkEnd = mid - 1;
            }
            // Console.WriteLine("NewGK:" + gkStart + ":" + gkEnd);
        }
        allOne = false;
        return gkStart;
    }
    private UInt64 sqr;
    public string SmallestGoodBase(string n)
    {
        UInt64 nv = 0;
        for (var i = 0; i < n.Length; i++)
        {
            nv *= 10;
            nv += (UInt64)(n[i] - '0');
        }
        //11 + k-1 = 10000
        if (nv == 1) return 2.ToString();
        var curNv = nv;
        var minLen = 2;
        var maxLen = 0;
        var allOne = true;
        while (curNv > 0)
        {
            if ((curNv % 2) != 1) allOne = false;
            curNv /= 2;
            maxLen++;
        }
        if (allOne) return 2.ToString();
        //4= 100
        //(nv + k-1) = K^(len+1)
        var curLen = maxLen - 1;
        if (curLen == 2) return (nv - 1).ToString();
        //k^curLen = nv + (k-1)
        //k = [2, sqr]
        //K^(len-1)+ ... + K^0
        sqr = FindSqrt(nv);
        // Console.WriteLine("curLen:" + curLen + ":" + sqr);
        //1-k^len / 1-k  k^len-1 / k-1
        for (var i = curLen; i > 2; i--)
        {
            var k = FindK(nv, i, out var ao);
            if (ao) return k.ToString();
        }
        return (nv-1).ToString();
    }
    // static void Main(string[] arg)
    // {
    //     var gb = new GoodBase2();
    //     // var r = gb.SmallestGoodBase("13");
    //     // var r = gb.SmallestGoodBase("4681");
    //     // var r = gb.SmallestGoodBase("1000000000000000000");
    //     var r = gb.SmallestGoodBase("9385");
    //     Console.WriteLine(r+":"+gb.total);

    // }
}


public class Solution {
    public string SmallestGoodBase(string n) {
        var gb = new GoodBase2();
        return gb.SmallestGoodBase(n);
    }
}
```