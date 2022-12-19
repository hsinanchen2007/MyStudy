    public static int maxDistance(int[][] grid) {
        LinkedList<Node> queue = new LinkedList<>();

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    queue.offer(new Node(i, j, 1, 0));
                }
            }
        }

        while (!queue.isEmpty()) {
            Node node = queue.poll();

            grid[node.x][node.y] = 2;

            // left
            if (node.y - 1 >= 0 && grid[node.x][node.y - 1] < 2) {
                if (grid[node.x][node.y - 1] == 0) {
                    queue.offer(new Node(node.x, node.y - 1, 2, node.count + 1));
                }
                grid[node.x][node.y - 1] = 2;
            }
            // right
            if (node.y + 1 < grid.length && grid[node.x][node.y + 1] < 2) {
                if (grid[node.x][node.y + 1] == 0) {
                    queue.offer(new Node(node.x, node.y + 1, 2, node.count + 1));
                }
                grid[node.x][node.y + 1] = 2;
            }

            // up
            if (node.x - 1 >= 0 && grid[node.x - 1][node.y] < 2) {
                if (grid[node.x - 1][node.y] == 0) {
                    queue.offer(new Node(node.x - 1, node.y, 2, node.count + 1));
                }
                grid[node.x - 1][node.y] = 2;
            }

            // down
            if (node.x + 1 < grid[0].length && grid[node.x + 1][node.y] < 2) {
                if (grid[node.x + 1][node.y] == 0) {
                    queue.offer(new Node(node.x + 1, node.y, 2, node.count + 1));
                }
                grid[node.x + 1][node.y] = 2;
            }

            if (queue.isEmpty()) {
                if(node.count == 0){
                    return -1;
                }
                return node.count;
            }
        }
        // 没有陆地
        return -1;
    }

    static class Node {
        private int x;
        private int y;
        private int value;
        private int count;

        public Node(int x, int y, int value, int count) {
            this.x = x;
            this.y = y;
            this.value = value;
            this.count = count;
        }
    }