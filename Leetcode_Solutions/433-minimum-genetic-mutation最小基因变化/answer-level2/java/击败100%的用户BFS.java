### 解题思路
同一种方法BFS为什么这道题这麽快？？？？？

### 代码

```java
class Solution {
    private boolean EndSymbol;
    private int res;
    public int minMutation(String start, String end, String[] bank) {
        this.EndSymbol=false;
        HashMap<String,Boolean>visited=new HashMap<String, Boolean>();
        LinkedList<String>WorkQueue=new LinkedList<>();
        int index=1,lever=1;
        WorkQueue.add(start);
        visited.put(start,true);
        while(!WorkQueue.isEmpty()&&!this.EndSymbol){
            start=WorkQueue.poll();
            _getChild(start,WorkQueue,visited,bank);
            for(int i=0;i<WorkQueue.size();i++){
                if(WorkQueue.get(i).equals(end)){
                    this.EndSymbol=true;
                    res=lever;
                }
            }
            index--;
            if(index==0){
                index=WorkQueue.size();
                lever++;
            }
        }
        return res==0?-1:res;
    }
    private void _getChild(String start, LinkedList<String> workQueue, HashMap<String, Boolean> visited, String[] bank) {
        int index=0;
        for(int i=0;i<bank.length;i++){
            if(visited.containsKey(bank[i]))
                continue;
            for(int j=0;j<start.length();j++){
                if(bank[i].charAt(j)!=start.charAt(j))
                    index++;
            }
            if(index==1){
                workQueue.add(bank[i]);
                visited.put(bank[i],true);
            }
            index=0;
        }
    }
}
```