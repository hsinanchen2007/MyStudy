### 解题思路
基于组 之间的排序
和组内的 排序
记录每个工作的前置完成计数

### 代码

```csharp
class GroupNum{
    public int groupId = -1;
    public List<int> lst= new List<int>();
    public HashSet<int> beforeGroup = new HashSet<int>();
    public HashSet<GroupNum> nextCanDo = new HashSet<GroupNum>();//做完这个接下来可以处理的任务
    public int finish = 0;
    public bool needSort = false;
    public bool IsFinish(){
        return finish == beforeGroup.Count;
    }
}
class GINode{
    public int num;
    public int finNum = 0;
    public bool IsFinish(){
        return finNum == before.Count;
    }
    public HashSet<GINode> before = new HashSet<GINode>();
    public HashSet<GINode> next = new HashSet<GINode>();
}

class SortGroup{
    private bool DoSort(Dictionary<int, GINode> allN, GroupNum g){
        var on = new Queue<GINode>();
        var vis = new HashSet<int>();
        var retList = new List<int>();
        foreach(var n in g.lst){
            var z = allN[n].before.Count == 0;
            if(z) {
                on.Enqueue(allN[n]);
                vis.Add(n);
                retList.Add(n);
            }
        }
        if(on.Count == 0) return false;
        while(on.Count > 0){
            var fir = on.Dequeue();
            foreach(var n in fir.next){
                if(vis.Contains(n.num)) return false;
                n.finNum++;
                if(n.IsFinish()){
                    vis.Add(n.num);
                    on.Enqueue(n);
                    retList.Add(n.num);
                }
            }
        }
        if(retList.Count != g.lst.Count) return false;
        g.lst = retList;
        return true;
    }
    public int[] SortItems(int n, int m, int[] group, IList<IList<int>> beforeItems) {
        var nToG = new Dictionary<int, GroupNum>();
        var allG = new Dictionary<int, GroupNum>();
        var index = 0;
        var allN = new Dictionary<int, GINode>();
        foreach(var g in group){
            var inD = new GINode()
            {
                num = index,
            };
            allN.Add(index, inD);
            if(g == -1){
                var gi = -(index + 1);
                var gg = new GroupNum(){
                    groupId = gi,
                };
                gg.lst.Add(index);
                nToG[index] = gg;
                allG[gi] = gg;
            }else {
                if(!allG.ContainsKey(g)) {
                    var gg = new GroupNum(){groupId = g,};
                    allG[g] = gg;
                }
                allG[g].lst.Add(index);
                nToG[index] = allG[g];
            }
            index++;
        }
        //Console.WriteLine("Groups:"+ObjectDumper.Dump(allG, new DumpOptions(){
        //     MaxLevel = 10,
        // }));
        
        //避免Loop 和自Loop
        for(var i = 0; i < beforeItems.Count; i++){
            var gNow = nToG[i];
            foreach(var nd in beforeItems[i]){
                var gB = nToG[nd];
                //Console.WriteLine("gNow:" + gNow.groupId + ":" + gB.groupId+":"+i+":"+nd);
                // if(gNow == gB) return new int[] { };
                if(gNow == gB){
                    allN[i].before.Add(allN[nd]);
                    allN[nd].next.Add(allN[i]);
                    gNow.needSort = true;
                    continue;//组内部的依赖顺序
                }
                gNow.beforeGroup.Add(gB.groupId);
                gB.nextCanDo.Add(gNow);
            }
        }
        // foreach(var g in allG){
        //     //Console.WriteLine(g.Key + ":" + g.Value.lst.Count + ":" + g.Value.beforeGroup.Count+":"+g.Value.nextCanDo.Count);
        // }
        //反向排序
        //gBefore<-gNow
        //最后一层
        var retList = new List<GroupNum>();
        var openNode = new Queue<GroupNum>();
        var hash = new HashSet<int>();
        foreach(var gg in allG){
            if(gg.Value.beforeGroup.Count == 0){
                openNode.Enqueue(gg.Value);
                hash.Add(gg.Key);
                retList.Add(gg.Value);
                gg.Value.finish = 0;
            }
        }
        //NoBefore 
        //寻找这一层所有的 
        //不存在Root点
        if(openNode.Count == 0) return new int[]{};

        while(openNode.Count > 0){
            var fir = openNode.Dequeue();
            foreach(var nn in fir.nextCanDo){
                //已经处理过了
                if(hash.Contains(nn.groupId)){
                    return new int[] { };
                }else {
                    nn.finish++;
                    if(nn.IsFinish()){
                        hash.Add(nn.groupId);
                        openNode.Enqueue(nn);
                        retList.Add(nn);
                    }
                }
            }
        }
        // foreach(var g in allG){
        //     if(!g.Value.IsFinish()) return new int[] { };
        // }
        if(retList.Count != allG.Count) return new int[] { };

        //排序内部所有节点根据依赖关系
        foreach(var g in retList){
            if(g.needSort){
                if(!DoSort(allN, g)) return new int[] { };
            }
        }
        var retNum = new List<int>();
        foreach(var g in retList){
            foreach(var nv in g.lst){
                retNum.Add(nv);
            }
        }
        return retNum.ToArray();
    }
}

public class Solution {
    public int[] SortItems(int n, int m, int[] group, IList<IList<int>> beforeItems) {
        var gn = new SortGroup();
        return gn.SortItems(n, m, group, beforeItems);
    }
}
```