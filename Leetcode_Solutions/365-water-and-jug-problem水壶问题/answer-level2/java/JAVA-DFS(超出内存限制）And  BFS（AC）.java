八种状态， 不清楚请查看官方题解

DFS-超出内存限制
```
    //把x壶倒空
    //把x壶倒满
    //把y壶倒空
    //把x壶倒满
    //把x壶里的倒入到y壶，直到y壶满或x壶空
    //把y壶倒入x壶，直到x壶满或y壶空
    private int maxX;
    private int maxY;
    public boolean canMeasureWater(int x, int y, int z) {
        maxX = x;
        maxY = y;
        Map<Integer, Set<Integer>> visited = new HashMap();
        return dfs(0,0,z,visited);
    }

    public boolean dfs(int x, int y, int z, Map<Integer, Set<Integer>> visited){
        if(x == z || y == z || x + y == z)    return true;
        if(visited.get(x) != null && visited.get(x).contains(y))    return false;
        if(visited.get(x) == null)  visited.put(x, new HashSet());
        visited.get(x).add(y);
        //把x壶倒空
        boolean xEmpty = dfs(0, y, z, visited);
        //把x壶倒满
        boolean xFull = dfs(maxX, y, z, visited);
        //把y壶倒空
        boolean yEmpty = dfs(x, 0, z, visited);
        //把x壶倒满
        boolean yFull = dfs(x, maxY, z, visited);
        //把x壶里的倒入到y壶，直到y壶满或x壶空
        boolean xToY;
        //1.y壶满
        if(x >= maxY - y){
            xToY = dfs(x - (maxY - y), maxY, z, visited);
        }else{
            //2.x壶空
            xToY = dfs(0, y + x, z, visited);
        }
        //把y壶倒入x壶，直到x壶满或y壶空
        boolean yToX;
        //1.x壶满
        if(y >= maxX - x){
            yToX = dfs(maxX, y - (maxX - x), z, visited);
        }else{
            //2.y壶空
            yToX = dfs(x + y, 0, z, visited);
        }
        return xEmpty || xFull || yEmpty || yFull || xToY || yToX;
    }
```

BFS(AC)
```
    public boolean canMeasureWater(int x, int y, int z) {
        int xMax = x;
        int yMax = y;
        Map<Integer, Set<Integer>> visited = new HashMap();
        Queue<int[]> queue = new LinkedList();
        queue.offer(new int[]{0,0});
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i =0 ;i < size; i++){
                int[] poll = queue.poll();
                x = poll[0]; y = poll[1];
                if(visited.get(x) == null) visited.put(x, new HashSet());
                visited.get(x).add(y);
                if(x == z || y == z || x + y == z)  return true;
                //xEmpty
                if(!contains(visited, 0, y)){
                    queue.offer(new int[]{0, y});
                }
                //xFull
                if(!contains(visited,xMax, y)){
                    queue.offer(new int[]{xMax, y});
                }
                //yEmpty
                if(!contains(visited,x, 0)){
                    queue.offer(new int[]{x, 0});
                }
                //yFull
                if(!contains(visited,x, yMax)){
                    queue.offer(new int[]{x, yMax});
                }
                if(x>= yMax - y){
                    if(!contains(visited,x - (yMax - y), yMax)){
                        queue.offer(new int[]{x - (yMax - y), yMax});
                    }
                }else{
                    if(!contains(visited,0, x + y)){
                        queue.offer(new int[]{0, x + y});
                    }
                }
                if(y >= xMax - x){
                    if(!contains(visited,xMax, y-(xMax - x))){
                        queue.offer(new int[]{xMax, y - (xMax - x)});
                    }
                }else{
                    if(!contains(visited,x + y, 0)){
                        queue.offer(new int[]{x + y, 0});
                    }
                }

            }
        }
        return false;
    }

    public boolean contains(Map<Integer, Set<Integer>> visited, int x, int y){
        if(visited.get(x) == null)  return false;
        return visited.get(x).contains(y);
    }
```

