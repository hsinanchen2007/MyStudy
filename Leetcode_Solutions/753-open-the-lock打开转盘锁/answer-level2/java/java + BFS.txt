第一次写完BFS 又是有成就感的一天 哈哈
 
```
class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> dead = new HashSet<>(Arrays.asList(deadends));
        if(dead.contains("0000") || dead.contains(target))
            return -1;
        LinkedList<String> queue = new LinkedList<>();
        queue.offer("0000");
        int step = 0;
        Set<String> visited = new HashSet<>();
        visited.add("0000");
        while(!queue.isEmpty()){
            int size = queue.size();
            step++;         
            for(int k = 0; k < size; k++){
                String tmp = queue.removeFirst();
                List<String> status = getStatus(tmp);
                for(int i = 0; i < status.size(); i++){   
                    String s = status.get(i);
                    if(s.equals(target))
                        return step;
                    if(!dead.contains(s) && !visited.contains(s)){
                        queue.offer(s);    
                        visited.add(s);
                    }
                }
            }         
        }
        
        return -1;
    }
    
    public List<String> getStatus(String s){//获取下一层的所有状态
        List<String> res = new ArrayList<>();
        for(int i = 0; i < 4; i++){
            char[] str = s.toCharArray();                   
            if(str[i] == '0')
                 str[i] = '9';
            else
                str[i] -= 1;
            res.add(String.valueOf(str));
            str = s.toCharArray();                    
            if(str[i] == '9')
                str[i] = '0';
            else
                str[i] += 1;  
            res.add(String.valueOf(str));
        }
        return res;
    }
}
```
