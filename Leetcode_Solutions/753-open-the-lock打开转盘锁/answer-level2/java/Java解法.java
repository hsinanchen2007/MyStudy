```
class Solution {
    
    private Map<String, Boolean> mp = new HashMap<>();
    
    private int min = Integer.MAX_VALUE;
    
    private int[] dx = {1,2,3,4};
    
    private int[] dy = {-1,1};
    
    public int openLock(String[] deadends, String target) {
        for(String str : deadends){
            mp.put(str, true);
        };
        if(mp.get("0000")!=null){
            return -1;
        }
        return bfs(target);
    }
    
    private int bfs(String target){
        Pos beginP = new Pos("0000", 0);
        Queue<Pos> q = new LinkedList<Pos>();
        q.add(beginP);
        while(!q.isEmpty()){
            Pos p = q.poll();
            if(p.num.equals(target)){
                System.out.println(p.num);
                min = Math.min(min, p.count);
                return min;
            }
            for(int i = 0;i<4;i++){
                for(int j = 0;j<2;j++){
                    String num = add(p.num, i, j);
                    if(mp.get(num)!=null){
                        continue;
                    }
                    q.add(new Pos(num, p.count + 1));
                    mp.put(num, true);
                }
            }
        }
        return -1;
    }
    
    private String add(String num, Integer index, Integer y){
        char[] chars = num.toCharArray();
        char ch = chars[index];
        int x = (ch - '0' + dy[y] + 10) % 10;
        chars[index] = (char) (x + '0');
        return new String(chars);
    }
}
class Pos{
    String num;
    Integer count;
    
    public Pos(String num, Integer count){
        this.num = num;
        this.count = count;
    }
}
```
