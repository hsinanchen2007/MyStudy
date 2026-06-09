最后一个n=48240的用例实在过不了，总是超时，希望能有通过朋友分享一下思路。

下面简单叙述一下我的想法。看到题目会很自然产生两个思路，1.按要求放coin，操作3的时候再统计；2.放coin的时候同步更新相关节点的coin数，操作3的时候直接读就行，不必统计。这两个思路都有很多朋友写出来了，我就不聊细节了。但很多朋友是采用自己建立树的结构来实现的。这就导致花费大量时间在遍历找节点上。所以我就采用HashMap来解决这个问题。通过Map来描述领导关系，从而可以很轻易地找到目标节点。对于思路1，一个描述领导关系的map就足够了，因为我们只需要向下放coin就行。但对于思路2，仅仅一个Map是不够的，思路2存在两种关系，一种是领导关系，一种是从属关系，我们既要向下放coin，也要向上更新coin。所以思路2需要两张描述关系的Map来达到目的。同时为了操作3读取方便，我又用一张Map来存放coin数。

（过了两天一想，上面的两个思路，思路一适合读取少、存储多的情况，思路二适合读取多、存储少的情况。能不能先花时间判断样本的读取与存储情况，再根据情况选择合适的方法解决。）

下面展示代码
```
class Solution {
    int mod = 1000000007;
    private static class Node{
        int number = -1;  //描述以该节点为根的树的节点数量，包括该节点
        long sumCoin = 0;  //操作3直接读取
    }

    public int[] bonus(int n, int[][] leadership, int[][] operations) {
        Map<Integer,Map<Integer,Integer>>mapLead = new HashMap<>();  //描述领导关系
        Map<Integer,Integer>mapParent = new HashMap<>();  //描述从属关系
        Map<Integer,Node>mapCoin = new HashMap<>();  //存放coin数
        for(int i=0; i<leadership.length; i++){
            if(!mapCoin.containsKey(leadership[i][0])){
                mapCoin.put(leadership[i][0],new Node());
            }
            if(!mapLead.containsKey(leadership[i][0])){
                mapLead.put(leadership[i][0],new HashMap<>());
            }
            if(!mapCoin.containsKey(leadership[i][1])){
                mapCoin.put(leadership[i][1],new Node());
            }
            if(!mapLead.get(leadership[i][0]).containsKey(leadership[i][1])){
                mapLead.get(leadership[i][0]).put(leadership[i][1],-1);
            }
            if(!mapParent.containsKey(leadership[i][1])){
                mapParent.put(leadership[i][1],leadership[i][0]);
            }
        }  //建立3张Map，最好是设个断点看一下
        Queue<Integer>q = new LinkedList<>();
        int action;
        int target;
        long coin;  //想着能不能通过减少取余操作来满足最后一个用例，事实证明我想多了
        for(int i=0; i<operations.length; i++){
            action = operations[i][0];
            target = operations[i][1];
            if(action==1){
                coin = operations[i][2];
                mapCoin.get(target).sumCoin = mapCoin.get(target).sumCoin+coin;
                feedBack(mapCoin,mapParent,target,coin);
            }else if(action==2){
                coin = operations[i][2];
                long pre = mapCoin.get(target).sumCoin;
                putCoin(mapCoin,mapLead,target,coin);
                feedBack(mapCoin,mapParent,target,mapCoin.get(target).sumCoin-pre);
            }else{
                q.add((int)mapCoin.get(target).sumCoin%mod);
            }
        }
        int[]r = new int[q.size()];
        for(int i=0; i<r.length; i++){
            r[i] = q.poll();
        }
        return r;
    }

    private int putCoin(Map<Integer,Node>mapCoin, Map<Integer,Map<Integer,Integer>>mapLead, int target, long coin){
        if(target>0){
            if(mapLead.containsKey(target)){
                Node tmpNode = mapCoin.get(target);
                if(tmpNode.number<=0){
                    int kid = 0;
                    for(int i:mapLead.get(target).keySet()){
                        kid += putCoin(mapCoin,mapLead,i,coin);
                    }  //这里通过第一次的遍历，得知该节点有多少下属，后面再到这可以直接算coin数，虽然该往下遍历还是要往下，但写程序方便
                    tmpNode.number = kid+1;
                    tmpNode.sumCoin = tmpNode.sumCoin+coin*tmpNode.number;
                }else{
                    tmpNode.sumCoin = tmpNode.sumCoin+coin*tmpNode.number;  //因为有了之前遍历的信息，所以直接算就可以
                    for(int i:mapLead.get(target).keySet()){
                        putCoin(mapCoin,mapLead,i,coin);
                    }
                }
                return tmpNode.number;
            }else{
                Node tmpNode = mapCoin.get(target);
                if(tmpNode.number<=0){
                    tmpNode.number = 1;
                }
                tmpNode.sumCoin = tmpNode.sumCoin+coin;
                return 1;
            }
        }
        return 0;
    }

    private void feedBack(Map<Integer,Node>mapCoin, Map<Integer,Integer>mapParent, int target, long coin){
        if(mapParent.containsKey(target)){
            int parent = mapParent.get(target);  //利用描述从属关系的Map，回溯找父节点
            Node pNode = mapCoin.get(parent);
            pNode.sumCoin = pNode.sumCoin+coin;
            feedBack(mapCoin,mapParent,parent,coin);
        }
    }
}
```
