```
class Solution {
    public int openLock(String[] deadends, String target) {
        HashSet<String> deadset = new HashSet<>();
        for(String s:deadends){
            deadset.add(s);
        }
        if(deadset.contains(target)) return -1;
        if(deadset.contains("0000")) return -1;
        if(target.equals("0000")) return 0;

        // bfs过程
        Queue<String> queue = new LinkedList<>();
        HashMap<String,Integer> visited = new HashMap<>();
        queue.add("0000");
        visited.put("0000",0);
        while(!queue.isEmpty()){
            String curs = queue.remove();
            char[] curarray = curs.toCharArray();
            ArrayList<String> nexts = new ArrayList<>();
            for(int i=0;i<4;i++){
                char origin = curarray[i];
                // 向后拨1位
                curarray[i] = Character.forDigit((curarray[i] - '0' + 1) % 10 , 10);
                nexts.add(new String(curarray));
                curarray[i] = origin;
                // 向前拨1位
                curarray[i] = Character.forDigit((curarray[i] - '0' + 9) % 10 , 10);
                nexts.add(new String(curarray));
                curarray[i] = origin;
            }

            for(String next:nexts){
                if(!deadset.contains(next) && !visited.containsKey(next)){
                    queue.add(next);
                    visited.put(next, visited.get(curs)+1);
                    if(next.equals(target)){
                        return visited.get(next);
                    }
                }
            }
        }
        return -1;
    }
}
```
