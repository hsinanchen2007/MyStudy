### 解题思路
将整个board 划分为多个区间
长度1的区间 可以尝试插入 两个 来消除
长度2 插入1个相同的消除， 
长度2 或者在两个之间插入1个不同的字符来分割，字符最多有 5种选择
因此搜索是 按区间移动，在一个区间内首先尝试5个字符插入，之后尝试消除



### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class ZMState{
    public List<VT> bS;
    public Dictionary<int, int> hS;
    public int boardPos = -1;//Which Group To Disappear
    // public bool testInsert = false; //测试插入 插入之后 再测试 消除
    public int insertIndex = -1;
    public void Insert(int g, int useH){
        hS[useH]--;
        if(hS[useH] == 0) hS.Remove(useH);
        var rg = bS[g];
        //RBR
        bS.Insert(g + 1, (rg.Item1, 1));
        bS.Insert(g + 1, (useH, 1));
        rg.Item2 = 1;
        bS[g] = rg;
    }
    public void RemoveGroup(int g){
        var rg = bS[g];
        var need = 3 - rg.Item2;
        hS[rg.Item1] -= need;
        if(hS[rg.Item1] == 0) hS.Remove(rg.Item1);
    
        var midG = g > 0 && g < (bS.Count - 1);
        bS.RemoveAt(g);
        //0 1 2
        if(midG){
            var beforeC = bS[g - 1];
            var afterC = bS[g];
            //移除或者合并
            if(beforeC.Item1 == afterC.Item1){
                if((beforeC.Item2+afterC.Item2) >= 3){
                    RemoveNeibor(g - 1);
                }else {
                    MergeNeibor(g - 1);
                }
            }
        }
    }
    private void MergeNeibor(int g){
        var rg = bS[g];
        rg.Item2 += bS[g + 1].Item2;
        bS.RemoveAt(g + 1);
        bS[g] = rg;
    }

    //移除所有消除邻居
    private void RemoveNeibor(int g)
    {
        var midG = g > 0 && (g + 1) < (bS.Count - 1);
        bS.RemoveRange(g, 2);
        if (midG)
        {
            var beforeC = bS[g - 1];
            var afterC = bS[g];
            if (beforeC.Item1 == afterC.Item1)
            {
                if ((beforeC.Item2 + afterC.Item2) >= 3)
                {//前后壳消除
                    RemoveNeibor(g - 1);
                }else {
                    MergeNeibor(g - 1);
                }
            }
        }
    }

    public int LeftHand(){
        var s = 0;
        foreach(var k in hS) s += k.Value;
        return s;
    }
    public void CopyOther(ZMState other){
        bS = new List<VT>();
        bS.AddRange(other.bS);
        hS = new Dictionary<int, int>();
        foreach(var kv in other.hS){
            hS.Add(kv.Key, kv.Value);
        }
    }
    public void InitGroup(List<int> d){
        bS = new List<VT>();
        var lastC = -1;
        var lastCount = -1;
        for (var i = 0; i < d.Count; i++){
            var di = d[i];
            if(di != lastC){
                if(lastC != -1){
                    bS.Add((lastC, lastCount));
                }
                lastC = di;
                lastCount = 1;
            }else {
                lastCount++;
            }
        }
        if(lastC != -1){
            bS.Add((lastC, lastCount));
        }
    }

}
class ZuMa2{
     private int ToInt(char c){
        switch(c){
            case 'R': return 0;
            case 'Y': return 1;
            case 'B': return 2;
            case 'G': return 3;
            case 'W': return 4;
            default:
                return -1;
        }
    }
    public int totalNum = 0;
    public int FindMinStep(string board, string hand)
    {
        //WRRBBW  RB
        //对于一个Group 插入到 左侧 或者右侧 或者中间 是等价的
        //board 16  hand 5
        //规模小
        //位置选择 16 hand 选择 5
        var bS = new List<int>();
        foreach(var c in board) bS.Add(ToInt(c));
        var hS = new Dictionary<int, int>();
        foreach (var c in hand)
        {
            hS.TryAdd(ToInt(c), 0);
            hS[ToInt(c)]++;
        }
        var stack = new List<ZMState>();
        var initS = new ZMState()
        {
            // bS = bS,
            hS = hS,
        };
        initS.InitGroup(bS);
        //Console.WriteLine("BS:" + ObjectDumper.Dump(initS));
        stack.Add(initS);
        var minInsert = Int32.MaxValue;
        var totalHand = hand.Length;
        while(stack.Count > 0){
            totalNum++;
            var top = stack[stack.Count - 1];
            //Console.WriteLine("CurTop:"+stack.Count+":"+ObjectDumper.Dump(top));
            //已经消耗太多了不要处理了
            var curInsert = totalHand - top.LeftHand();
            if(curInsert >= minInsert){
                stack.RemoveAt(stack.Count - 1);
                continue;
            }
            
            if(top.bS.Count == 0){
                minInsert = Math.Min(minInsert, totalHand - top.LeftHand());
                stack.RemoveAt(stack.Count - 1);
            }else
            {
                if(top.hS.Count == 0){ //没手牌了
                    stack.RemoveAt(stack.Count - 1);
                    continue;
                }

                var findPos = -1;
                var findInsert = -1;
                var useInsert = -1;
                //分割操作也是一种操作 R RWWRRBBRR WB
                for (var i = top.boardPos + 1; i < top.bS.Count;)
                {
                    // top.boardPos = i;
                    var bv = top.bS[i];
                    //每个Pos 执行0~4 插入测试 == 2 才执行插入测试
                    if(bv.Item2 == 2 && top.insertIndex < 4){
                        for (var j = top.insertIndex + 1; j <= 4; j++){
                            top.insertIndex = j;
                            if(j != bv.Item1 && top.hS.ContainsKey(j)){
                                findInsert = i;
                                useInsert = j;
                                break;
                            }
                        }
                        if(findInsert != -1) break;
                    }else//尝试消除 推进到下一个部分
                    {
                        var oldI = i;
                        top.boardPos = oldI;
                        top.insertIndex = -1;
                        i++;
                        if (top.hS.ContainsKey(bv.Item1))
                        {
                            //可消除该区间
                            var numR = (top.hS[bv.Item1] + bv.Item2) >= 3;
                            if (numR)
                            {
                                findPos = oldI;
                                break;
                            }
                        }
                    }
                }
                if (findPos != -1)
                {
                    var newState = new ZMState();
                    newState.CopyOther(top);
                    newState.RemoveGroup(findPos);
                    stack.Add(newState);
                }else if(findInsert != -1){
                    var newState = new ZMState();
                    newState.CopyOther(top);
                    newState.Insert(findInsert, useInsert);
                    stack.Add(newState);
                }
                else
                {
                    stack.RemoveAt(stack.Count - 1);
                }
            }
        }
        if(minInsert == Int32.MaxValue) return -1;
        return minInsert;
    }
    // static void Main(string[] arg)
    // {
    //     var ls = File.ReadAllLines("testZM.json");
    //     var b = JsonSerializer.Deserialize<string>(ls[0]);
    //     var h = JsonSerializer.Deserialize<string>(ls[1]);


    //     var zm = new ZuMa2();
    //     // var r = zm.FindMinStep("WRRBBW", "RB");
    //     // var r = zm.FindMinStep("WWRRBBWW", "WRBRW");
    //     // var r = zm.FindMinStep(, );
    //     // var r = zm.FindMinStep("G", "GGGGG");
    //     // var r = zm.FindMinStep("RBYYBBRRB", "YRBGB");
    //     var r = zm.FindMinStep(b, h);
    //     Console.WriteLine(r + ":" + zm.totalNum);
    // }
}
public class Solution {
    public int FindMinStep(string board, string hand) {
        var zm = new ZuMa2();
        return zm.FindMinStep(board, hand);
    }
}
```