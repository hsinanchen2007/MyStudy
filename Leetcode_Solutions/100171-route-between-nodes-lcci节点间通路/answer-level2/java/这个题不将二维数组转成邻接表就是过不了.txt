    
    class Solution {
        public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
            //不一定用list数组，可以用List<List<Integer>>
		//List<List<Integer>> adj = new ArrayList<>();
            List<Integer>[] adj = new ArrayList[n];
            for(int i = 0;i < graph.length;i++) {
                if(adj[graph[i][0]] == null) {
                    adj[graph[i][0]] = new ArrayList<>();
                }
                adj[graph[i][0]].add(graph[i][1]);
            }
            HashSet<Integer> hs = new HashSet<>();
            Queue<Integer> queue = new LinkedList<>();
            queue.add(start);
            hs.add(start);
            while(!queue.isEmpty()) {
                int num = queue.poll();
                if(adj[num] == null) {
                    continue;
                }
                for(int i = 0;i < adj[num].size();i++) {
                    int temp = adj[num].get(i);
                    if(temp == target) {
                        return true;
                    }
                    if(!hs.contains(temp)) {
                        queue.add(temp);
                        hs.add(temp);
                    }
                }
            }
            return false;
        }

    }