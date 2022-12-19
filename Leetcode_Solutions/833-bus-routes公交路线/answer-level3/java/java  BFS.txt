思路就是一般的BFS，从出发点拓展去找下一步可以到达的点

需要注意的是，在构建图的时候，可以只保存路线（下标），而不是保存每个点，这样可以加快检索效率

```
public int numBusesToDestination(int[][] routes, int S, int T) {
        if(S==T) return 0;
        Map<Integer,List<Integer>> map = new HashMap<>();
        for(int i=0 ;i<routes.length ; i++){          
            for(int j=0 ; j<routes[i].length ; j++){
                List<Integer> list = map.getOrDefault(routes[i][j],new ArrayList<>());
                list.add(i);
                map.put(routes[i][j],list);
            }            
        }       
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(S);
        Set<Integer> visited_stop = new HashSet<>();
        boolean[] visited_line = new boolean[routes.length];
        visited_stop.add(S);
        int res = -1;
        while(!queue.isEmpty()){
            ++res;
            int size = queue.size();
            for(int i=0 ; i<size ; i++){
                int src = queue.poll();
                if(src==T) return res;
                List<Integer> lines = map.get(src);                
                for(int line : lines){
                    if(!visited_line[line]){
                        for(int n : routes[line]){
                            if(!visited_stop.contains(n)){
                                queue.offer(n);
                                visited_stop.add(n);
                            }
                        }
                        visited_line[line] = true;
                    }
                }
                
            }
        }       
        return -1;
    } 
```
