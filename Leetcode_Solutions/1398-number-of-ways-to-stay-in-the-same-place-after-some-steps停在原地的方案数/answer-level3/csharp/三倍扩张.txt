### 解题思路
以当前位置和剩余步数 作为 子问题Key
子问题 各自独立，且子问题 步数 是当前问题 步数的一部分


### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class StayPos{
    UInt64 MODV = 1000000000 + 7;
    private int AL;
    public Dictionary<VT, UInt64> cache = new Dictionary<VT, UInt64>();
    public int totalN = 0;
    private UInt64 NW(int curPos, int leftStep){
        totalN++;
        //不可能到达0 或者在0位置
        if(leftStep <= 0){
            if(curPos != 0) return 0;
            return 1;
        }
        //差一步 Stay 或者 MoveLeft
        if(leftStep == 1){
            if(curPos == 0) return 1;
            if(curPos == 1) return 1;
            return 0;
        }
        var key = (curPos, leftStep);
        if(cache.ContainsKey(key)) return cache[key];

        UInt64 totalWay = 0;
        if (curPos < (AL-1))
        {
            var rN = NW(curPos + 1, leftStep - 1);
            totalWay += rN;
            totalWay %= MODV;
        }
        if(curPos > 0){
            var lN = NW(curPos - 1, leftStep - 1);
            totalWay += lN;
            totalWay %= MODV;
        }
        totalWay += NW(curPos, leftStep - 1);
        totalWay %= MODV;

        cache.Add(key, totalWay);
        return totalWay;
    }
    public int NumWays(int steps, int arrLen) {
        AL = arrLen;
        return (int)NW(0, steps);
    }
}
public class Solution {
    public int NumWays(int steps, int arrLen) {
        var sp = new StayPos();
        return sp.NumWays(steps, arrLen);
    }
}
```