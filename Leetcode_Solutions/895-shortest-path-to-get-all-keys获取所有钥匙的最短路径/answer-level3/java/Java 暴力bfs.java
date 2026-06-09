用boolean数组保存钥匙状态，用坐标+钥匙状态避免重复路径（钥匙状态似乎用整数的二进制位保存更好，但写完才发现懒得改了=u=）
```
class Solution {
    public int shortestPathAllKeys(String[] grid) {
        LinkedList<Status> queue = new LinkedList<>();
        int x = 0;
        int y = 0;
        char[][] map = new char[grid.length][grid[0].length()];
        for (int i = 0;i<grid.length;i++){
            map[i] = grid[i].toCharArray();
        }
        int m = grid.length;
        int n = map[0].length;
        int target = 0;
        a:
        for (int i = 0;i<m;i++) for (int j = 0;j<n;j++){
            if (map[i][j]=='@'){
                x = i;y = j;
            }
            if ((map[i][j]>='A')&&(map[i][j]<='Z')){
                target++;
            }
        }
        Status start = new Status(new boolean[target],x,y,0,0);
        queue.add(start);
        Map<Status,Integer> hash = new HashMap<>();
        hash.put(start,0);
        int[] xx = {-1,1,0,0};
        int[] yy = {0,0,1,-1};
        while (queue.size()>0){
            Status now = queue.poll();
            for (int i = 0;i<4;i++){
                x = now.x+xx[i];
                y = now.y+yy[i];
                if (x<0||x>=m||y<0||y>=n) continue;
                if (map[x][y]=='#') continue;
                if ((map[x][y]>='A')&&(map[x][y]<='Z')){
                    if (!now.key[map[x][y]-'A']) continue;
                }
                boolean[] newkey = now.key;
                if ((map[x][y]>='a')&&(map[x][y]<='z')){
                    newkey = Arrays.copyOf(now.key,target);
                    int newCount = now.count;
                    if (!now.key[map[x][y]-'a']){
                        newkey[map[x][y]-'a'] = true;
                        newCount++;
                    }
                    if (newCount == target) return now.dis+1;
                    Status next = new Status(newkey,x,y,newCount,now.dis+1);
                    if (hash.containsKey(next)) continue;
                    hash.put(next,0);
                    queue.offer(next);
                }else{
                    Status next = new Status(now.key,x,y,now.count,now.dis+1);
                    if (hash.containsKey(next)) continue;
                    hash.put(next,0);
                    queue.offer(next);
                }
            }
        }
        return -1;


    }
    class Status{
        public boolean[] key;
        public int x;
        public int y;
        public int count;//distance from target
        public int dis; // number of moves
        public Status(boolean[] a,int b,int c,int d,int e){
            key = a;
            x = b;
            y = c;
            count = d;
            dis = e;
        }

        @Override
        public int hashCode(){
            return x*100007+y*1007+count;
        }

        @Override
        public boolean equals(Object c){
            Status b = (Status)c;
            if ((x!=b.x)||(y!=b.y)||(count!=b.count)) return false;
            for (int i = 0;i<key.length;i++){
                if (key[i]!=b.key[i]) return false;
            }
            return true;
        }

    }
}
```