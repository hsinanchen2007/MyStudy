### 解题思路
先初始化图，双向邻接表建立，然后剪枝，每轮循环删除度为1的节点，直至剩下的节点度大于1，
最后将剩下的点与输入数组匹配，从后往前找，找到则返回结果

### 代码

```java
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        Map<Integer,List<Integer>> map=new HashMap<>();
        for(int[] edge:edges){
            List<Integer> last=map.computeIfAbsent(edge[0],k->new ArrayList<>());
            last.add(edge[1]);
            List<Integer> next=map.computeIfAbsent(edge[1],k->new ArrayList<>());
            next.add(edge[0]);
        }

        boolean flag=false;
        while(!flag){
            flag=true;
            Set<Map.Entry<Integer,List<Integer>>> s=map.entrySet();
            Iterator<Map.Entry<Integer,List<Integer>>> iterator=s.iterator();
            while(iterator.hasNext()){
                Map.Entry<Integer,List<Integer>> mapEntry=iterator.next();
                List<Integer> neighbor=mapEntry.getValue();
                if(neighbor.size()==1){
                    List<Integer> neighborIn=map.get(neighbor.get(0));
                    flag=false;
                    Integer deleteObject=mapEntry.getKey();
                    iterator.remove();
                    neighborIn.remove(deleteObject);
                }
            }
        }
        int []result=new int[2];
        for(int i=(edges.length-1);i>=0;i--){
            if(map.containsKey(edges[i][0])&&map.containsKey(edges[i][1])){
                result[0]=edges[i][0];
                result[1]=edges[i][1];
                break;
            }
        }
        return result;
    }


}
```