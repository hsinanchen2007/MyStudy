### 解题思路
需要数字+1
不是需要的数字-1
判定当前没有需要的则 可以切割为一个Trunk
控制Chunk的最大最小数字

### 代码

```csharp
class TrunkData {
    public enum State {
        FindStart,
        FindEnd,
    }
    public State state = State.FindStart;
    public int start = -1;
    public int end = -1;
    public int minNum = -1;
    public int maxNum = -1;
    //区间内需要的数字数量
    public Dictionary<int, int> rangeNeedCount = new Dictionary<int, int> ();
    // public Dictionary<int, int> curHoldNum = new Dictionary<int, int> ();
}
class MaxChunk {
    //可以重复数组  Chunks
    //分别排序内部
    //连接 =》 产生一个排序数组
    //最多多少个Chunk
    //1个chunk排序内部
    //最多的Chunk 
    //MaxN == CurN 停止 可接受
    public int MaxChunksToSorted (int[] arr) {
        var ls = new List<int> ();
        ls.AddRange (arr);
        //1第一个元素 == First 则可以切割Chunk 
        //最小 和 最大 Range == 当前区间MaxSmall
        ls.Sort ();
        // Console.WriteLine (JsonSerializer.Serialize (ls));

        var totalTrunk = 0;
        var trunk = new TrunkData ();
        for (var i = 0; i < arr.Length; i++) {
            // Console.WriteLine (ObjectDumper.Dump (trunk));
            if (trunk.state == TrunkData.State.FindStart) {
                trunk.state = TrunkData.State.FindEnd;
                trunk.start = i;
                trunk.end = i;
                trunk.minNum = arr[i];
                trunk.maxNum = arr[i];
                //需要1个 Start
                // trunk.rangeNeedCount.TryAdd (arr[i], 0);
                // trunk.rangeNeedCount[arr[i]]++;
                var nd = ls[i];
                // trunk.rangeNeedCount.TryAdd ();
            }

            if (trunk.state == TrunkData.State.FindEnd) {
                trunk.end = i;
                var needNum = ls[i];
                var addNum = arr[i];
                //不能抵消 则添加计数
                if (needNum != addNum) {
                    trunk.rangeNeedCount.TryAdd (needNum, 0);
                    trunk.rangeNeedCount[needNum]++;
                    if (trunk.rangeNeedCount[needNum] == 0) trunk.rangeNeedCount.Remove (needNum);
                    trunk.rangeNeedCount.TryAdd (addNum, 0);
                    trunk.rangeNeedCount[addNum]--;
                    if (trunk.rangeNeedCount[addNum] == 0) trunk.rangeNeedCount.Remove (addNum);
                }
                trunk.minNum = Math.Min (trunk.minNum, arr[i]);
                trunk.maxNum = Math.Max (trunk.maxNum, arr[i]);
                if (trunk.minNum == ls[trunk.start] &&
                    trunk.maxNum == ls[trunk.end] &&
                    trunk.rangeNeedCount.Count == 0) {
                    totalTrunk++;
                    trunk.state = TrunkData.State.FindStart;
                    trunk.rangeNeedCount.Clear ();
                }
            }
            // Console.WriteLine ("Ret:"+ObjectDumper.Dump (trunk));
        }
        return totalTrunk;
    }
    // static void Main (string[] arg) {
    //     var mc = new MaxChunk ();
    //     // var r = mc.MaxChunksToSorted (new int[] {5,4,3,2,1 });
    //     // var r = mc.MaxChunksToSorted (new int[] {2,1,3,4,4 });
    //     //00111  
    //     //11001
    //     //但是需要考虑范围内数字的数量 Min NumCount 
    //     var r = mc.MaxChunksToSorted (new int[] { 1, 1, 0, 0, 1 });
    //     Console.WriteLine (r);

    // }
}
public class Solution {
    public int MaxChunksToSorted(int[] arr) {
        var mc = new MaxChunk();
        return mc.MaxChunksToSorted(arr);
    }
}
```