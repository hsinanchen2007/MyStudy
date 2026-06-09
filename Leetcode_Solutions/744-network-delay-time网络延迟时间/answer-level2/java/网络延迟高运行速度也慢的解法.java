### 解题思路
 第一轮的思考错误的原因在于我想dfs边，但是有个问题，当进行边的dfs时候，如果以当前节点的已找到路径值来继续计算下一点的路径值
 可能会发生不是最小路径值加到下一个点去，导致错误，例如点1->2,点1当前dfs的可能到达值为4,5,6,但是如果1还没有找到4，传了
 5或者6到点2，则会导致错误，所以必须想到更新问题，这就必须考虑djikstra算法，或者换种思路，每次dfs找一个点的最短路径
 小的处理技巧，将初始点看做下一个操作点，将其到自身的长度设为0

### 代码

```java


class Solution {
  public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer,List<int[]>> map=new HashMap<>();
        Map<Integer,Integer> values=new HashMap<>();
        if(N==1&&times.length==0){
            return 0;
        }
        for(int i=1;i<=N;i++){
            values.put(i,Integer.MAX_VALUE);
        }
        values.put(K,0);
        for(int[] time:times){
            List<int[]> neighbor=map.computeIfAbsent(time[0],k->new ArrayList<>());
            int[] dd=new int[2];
            dd[0]=time[1];
            dd[1]=time[2];
            neighbor.add(dd);
        }

        List<Integer> result=new ArrayList<>();

        while(true){
            // 第一轮找最小的邻居点
            int index=-1;
            int value=Integer.MAX_VALUE;
            for(int j=1;j<=N;j++){
                if(!result.contains(j)&&values.get(j)<value){
                    index=j;
                    value=values.get(j);
                }
            }
            if(value==Integer.MAX_VALUE){
                break;
            }
            result.add(index);
            // 开始更新这个点对应的邻居点与起始点的长度
            List<int[]> otherNeighbor=map.get(index);
            if(otherNeighbor==null||otherNeighbor.size()==0){
                continue;
            }
            for(int j=0;j<otherNeighbor.size();j++){
                if(values.get(otherNeighbor.get(j)[0])>(otherNeighbor.get(j)[1]+values.get(index))){
                    values.put(otherNeighbor.get(j)[0],otherNeighbor.get(j)[1]+values.get(index));
                }
            }
        }
        int fina=-1;
        for(int i=1;i<=N;i++){
            if(i==K){
                continue;
            }
            if(values.get(i)==Integer.MAX_VALUE){
                return -1;
            }
            if(fina<values.get(i)){
                fina=values.get(i);
            }
        }
        return fina;
    }

   
}
```