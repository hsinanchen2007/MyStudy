### 解题思路
打开 且 拥有的箱子

### 代码

```csharp
class BoxState{
    public int id = -1;
    // public HashSet<int> preBox = new HashSet<int>();
    public HashSet<int> nextBox = new HashSet<int>();
    public HashSet<int> containedBox = new HashSet<int>();
    // public HashSet<int> inWhatOther = new HashSet<int>();
    public bool isOpen = false;
    public int candNum = 0;
}

class OpenBox{
    public int MaxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        var boxNum = status.Length;
        
        // var openFrom = new Dictionary<int, HashSet<int>>();
        // for (var i = 0; i < keys.Length; i++){
        //     for (var j = 0; j < keys[i].Length; j++){
        //         openFrom.TryAdd(keys[i][j], new HashSet<int>());
        //         openFrom[keys[i][j]].Add(i);//box 被 i 钥匙打开
        //     }
        // }

        var openedBox = new HashSet<int>();
        // var closedBox = new HashSet<int>();
        for (var i = 0; i < status.Length;i++){
            if(status[i] == 1) openedBox.Add(i);
            // else closedBox.Add(i);
        }
        //这个宝箱可以开启的下一个宝箱
        //每个宝箱 之前可以开启自己的联系
        var lsB = new List<BoxState>();
        for (var i = 0; i < boxNum; i++){
            var bd = new BoxState();
            bd.id = i;
            lsB.Add(bd);
            // if(openFrom.ContainsKey(i)){
            //     bd.preBox = openFrom[i];
            // }
            foreach(var nb in keys[i]){
                bd.nextBox.Add(nb);
            }
            if(openedBox.Contains(i)){
                bd.isOpen = true;
            }
            bd.candNum = candies[i];
        }



        for (var i = 0; i < containedBoxes.Length; i++){
            foreach (var sb in containedBoxes[i])
            {
                lsB[i].containedBox.Add(sb);
                // lsB[sb].inWhatOther.Add(i);
            }
        }

        var canUsedBox = new HashSet<int>();
        var takedBox = new HashSet<int>();
        foreach(var b in initialBoxes){
            canUsedBox.Add(b);
        }
        var allTaked = 0;

OpenOpen:
        var openQueue = new Queue<BoxState>();
        var visedBox = new HashSet<int>();
        foreach(var b in canUsedBox){
            openQueue.Enqueue(lsB[b]);
            visedBox.Add(b);
        }
        var opened = false;
        while(openQueue.Count > 0){
            var fir = openQueue.Dequeue();
            //满足两个条件 isOpen 拥有Box
            if(fir.isOpen){
                opened = true;
                allTaked += fir.candNum;
                fir.candNum = 0;
                takedBox.Add(fir.id);
                canUsedBox.Remove(fir.id);
                foreach(var b in fir.containedBox){
                    if(!takedBox.Contains(b) && !visedBox.Contains(b)){
                        openQueue.Enqueue(lsB[b]);
                        canUsedBox.Add(b);
                        visedBox.Add(b);
                    }
                }
                //钥匙打开Box
                foreach(var k in fir.nextBox){
                    if(!takedBox.Contains(k)){
                        lsB[k].isOpen = true;
                    }
                }
            }
        }

        if(canUsedBox.Count > 0 && opened){
            goto OpenOpen;
        }
        return allTaked;
    }
}


public class Solution {
    public int MaxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        var ob = new OpenBox();
        return ob.MaxCandies(status, candies, keys, containedBoxes, initialBoxes);
    }
}
```