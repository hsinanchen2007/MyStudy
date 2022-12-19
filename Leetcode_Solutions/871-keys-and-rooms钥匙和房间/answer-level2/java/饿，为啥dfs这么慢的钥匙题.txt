### 解题思路
dfs解决即可，为啥这么慢

### 代码

```java
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Map<Integer,List<Integer>> map=new HashMap<>();
        for(int i=0;i<rooms.size();i++){
            map.put(i,rooms.get(i));
        }
        List<Integer> seen=new ArrayList<>();
        dfs(0,map,seen);
        if(seen.size()==rooms.size()){
            return true;
        }
        return false;
    }

    public void dfs(int src,Map<Integer,List<Integer>> map,List<Integer> seen){
        seen.add(src);
        List<Integer> neighbor=map.get(src);
        if(neighbor==null||neighbor.size()==0){
            return;
        }
        for(Integer neigh:neighbor){
            if(seen.contains(neigh)){
                continue;
            }
            dfs(neigh,map,seen);
        }
    }
}
```