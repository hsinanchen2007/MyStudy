### 解题思路
第一次想的是每个节点dfs一次即可，但是超时，然后借鉴别人的经验，以入度做数组，将入度为1的点不停的删去，直至剩下1个或者2个点

### 代码

```java
class Solution {
    public  Map<Integer,List<Integer>> map;
    boolean[] isVisited;
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        int remain=n;
        int [] edgeNum=new int[n];
        map=new HashMap<>();
        for(int[] edge:edges){
            List<Integer> firstNeighbor=null;
            if(map.containsKey(edge[0])){
                firstNeighbor=map.get(edge[0]);
            } else{
                firstNeighbor=new ArrayList<>();
            }
            firstNeighbor.add(edge[1]);
            map.put(edge[0],firstNeighbor);

            List<Integer> nextNeighbor=null;
            if(map.containsKey(edge[1])){
                nextNeighbor=map.get(edge[1]);
            } else{
                nextNeighbor=new ArrayList<>();
            }
            nextNeighbor.add(edge[0]);
            map.put(edge[1],nextNeighbor);

            edgeNum[edge[0]]++;
            edgeNum[edge[1]]++;
        }
        while(remain>2){
            Stack<Integer> s=new Stack<>();
            // 每轮找到入度为1的点
            for(int i=0;i<n;i++){
                if(edgeNum[i]==1){
                    s.push(i);
                    edgeNum[i]=-1;
                    remain--;
                }
            }
            // 将这些点对应的边上的点的边数目减一
            while(!s.isEmpty()){
                Integer pop=s.pop();
                List<Integer> neighbor=map.get(pop);
                for(Integer neigh:neighbor){
                    edgeNum[neigh]--;
                }
                map.remove(pop);
            }
            

        }
        List<Integer> result=new ArrayList<>();
        for(int i=0;i<n;i++){
                if(edgeNum[i]>-1){
                    result.add(i);
                }
        }
        return result;
    }
        
}
```