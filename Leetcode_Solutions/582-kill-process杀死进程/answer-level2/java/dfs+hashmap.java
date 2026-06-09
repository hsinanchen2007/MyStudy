```
class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Map<Integer,List<Integer>> map=new HashMap<>();
        List<Integer> output=new ArrayList<>();

        for (int i=0;i<ppid.size();i++){
            if (!map.containsKey(ppid.get(i))){
                map.put(ppid.get(i),new ArrayList<Integer>());
            }
            map.get(ppid.get(i)).add(pid.get(i));
        }

        dfs(output,map,kill);
        return output;
    }

    public void dfs(List<Integer> output,Map<Integer,List<Integer>> map, int process){
        output.add(process);
        if (!map.containsKey(process)){
            return;
        }
        List<Integer> temp=map.get(process);

        for (int i=0;i<temp.size();i++){
            dfs(output,map,temp.get(i));
        }
    }
}
```
