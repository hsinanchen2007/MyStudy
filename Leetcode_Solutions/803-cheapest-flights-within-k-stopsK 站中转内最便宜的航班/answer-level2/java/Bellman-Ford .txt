```
public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        Queue<int[]> queue = new LinkedList<>();
        int[][] graph = buildGraph(n, flights);
        int result = -1;
        queue.offer(new int[]{src, 0});
        while(!queue.isEmpty() && K >= 0){
            int length = queue.size();
            for(int i = 0; i < length; i++){
                int[] stop = queue.poll();
                int curPrice = stop[1];
                for(int j = 0; j < n; j++){
                    if(graph[stop[0]][j] > 0){
                        if( j == dst){
                            int price = curPrice + graph[stop[0]][dst];
                            result = result == -1 ? price : Math.min(result, price);
                        } 
                        if(result == -1 || curPrice + graph[stop[0]][j] < result){
                            queue.offer(new int[]{j, curPrice + graph[stop[0]][j]});    
                        }
                    }
                }
            }
            K -= 1;
        }
        return result;
    }
    
    private int[][] buildGraph(int n, int[][] flights){
        int[][] graph = new int[n][n];
        for(int[] flight: flights){
            graph[flight[0]][flight[1]] = flight[2];
        }
        return graph;
    }
```
