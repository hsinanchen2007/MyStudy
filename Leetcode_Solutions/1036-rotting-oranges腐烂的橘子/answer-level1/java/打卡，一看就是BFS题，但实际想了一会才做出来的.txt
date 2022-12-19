    
    class Solution {
        public class Node{
            int i;
            int j;
            public Node(int i, int j) {
                this.i = i;
                this.j = j;
            }
        }

        public int orangesRotting(int[][] grid) {
            Queue<Node> queue = new LinkedList<>();
            HashSet<String> hs = new HashSet<>();
            int count = 0;
            for(int i = 0;i < grid.length;i++) {
                for(int j = 0;j < grid[0].length;j++) {
                    if(grid[i][j] == 2) {
                        String key = i + "#" + j;
                        hs.add(key);
                        queue.add(new Node(i, j));
                        
                    }
                }
            }
            while(!queue.isEmpty()) {
                int size = queue.size();
                int len = hs.size();
                for(int k = 0;k < size;k++) {
                    Node node = queue.poll();
                    // 右边
                    if(node.j + 1 < grid[0].length && grid[node.i][node.j + 1] == 1) {
                        String k1 = node.i + "#" +(node.j + 1);
                        if(!hs.contains(k1)) {
                            hs.add(k1);
                            grid[node.i][node.j + 1] = 2;
                            queue.offer(new Node(node.i, node.j + 1));
                        }
                    }
                    // 下边
                    if(node.i + 1 < grid.length && grid[node.i + 1][node.j] == 1) {
                        String k2 = (node.i + 1) + "#" + node.j;
                        if(!hs.contains(k2)) {
                            hs.add(k2);
                            grid[node.i + 1][node.j] = 2;
                            queue.offer(new Node(node.i + 1, node.j));
                        }
                    }
                    // 左边
                    if(node.j - 1 >= 0 && grid[node.i][node.j - 1] == 1) {
                        String k1 = node.i + "#" +(node.j - 1);
                        if(!hs.contains(k1)) {
                            hs.add(k1);
                            grid[node.i][node.j - 1] = 2;
                            queue.offer(new Node(node.i, node.j - 1));
                        }
                    }
                    // 上边
                    if(node.i - 1 >= 0 && grid[node.i - 1][node.j] == 1) {
                        String k2 = (node.i - 1) + "#" + node.j;
                        if(!hs.contains(k2)) {
                            hs.add(k2);
                            grid[node.i - 1][node.j] = 2;
                            queue.offer(new Node(node.i - 1, node.j));
                        }
                    }
                }
                if(hs.size() > len) {  // 感染一批 好桔子
                    count++;
                }
            }
            for(int i = 0;i < grid.length;i++) {
                for(int j = 0;j < grid[0].length;j++) {
                    if(grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
            return count;
        }
    }