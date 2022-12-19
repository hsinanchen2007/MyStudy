解法一：常规BFS，虽然是困难难度，但其实直接套用BFS模版即可。
实现1：如同大部分题解，转换字符串后操作
```java
class Solution {
    public int slidingPuzzle(int[][] board) {
        int[][] dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        String end = "123450";
        String curr = toString(board);
        if (curr.equals(end)) return 0;

        Queue<String> queue = new LinkedList<>();
        queue.offer(curr);
        Set<String> visited = new HashSet<>();
        visited.add(curr);

        int count = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                curr = queue.poll();
                for (int i = 0; i < curr.length(); i++) {
                    if (curr.charAt(i) != '0') continue; // 非0不做操作
                    for (int j : dir[i]) { // 获取0所在位置所有能移动的点
                        char[] nextValue = curr.toCharArray(); // 每次复制一份做操作
                        swap(nextValue, i, j); // 交换0和其可移动位置
                        String next = new String(nextValue);
                        if (next.equals(end)) return count + 1; // 谜板被解开
                        if (visited.contains(next)) continue; // 过滤已经访问数据
                        queue.offer(next);
                        visited.add(next);
                    }
                    break;
                }
            }
            count++;
        }
        return -1;
    }

    String toString(int[][] board) {
        char[] value = new char[6];
        for (int i = 0; i < 6; i++) value[i] = (char) (board[i / 3][i % 3] + '0');
        return new String(value);
    }

    void swap(char[] arr, int i, int j) {
        if (i != j) {
            char tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}
```

实现2：稍微做点优化
优化点1：观察一下，每次从queue中poll出的字符串，都要整个遍历字符串才能知道0的位置，而我们每次offer的时候其实是可以知道当前字符串0的位置的，所以可以考虑在offer的时候把0的位置跟字符串放一起减少循环，怎么把0跟字符串绑定呢，方法很多，最简单的就是定义一个类；
优化点2：其实没必要使用字符串（毕竟Java字符串的开销不小，至少copy是多的），理论上是直接使用int[][] board就可以，但是为了操作方便，可以转换char[]或int[]，一个逻辑。
```java
class Solution {
    public int slidingPuzzle(int[][] board) {
        int[][] dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        int[] endBoard = {1, 2, 3, 4, 5, 0};
        Node curr = new Node(board);
        if (Arrays.equals(curr.board, endBoard)) return 0;

        Queue<Node> queue = new LinkedList<>();
        queue.offer(curr);
        HashSet<Node> visited = new HashSet<>();
        visited.add(curr);

        int count = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                curr = queue.poll();
                for (int nextZeroPos : dir[curr.zeroPos]) {
                    int[] nextBoard = Arrays.copyOf(curr.board, 6);
                    swap(nextBoard, curr.zeroPos, nextZeroPos);
                    if (Arrays.equals(nextBoard, endBoard)) return count + 1;
                    Node next = new Node(nextBoard, nextZeroPos);
                    if (visited.contains(next)) continue;
                    queue.offer(next);
                    visited.add(next);
                }
            }
            count++;
        }
        return -1;
    }

    void swap(int[] arr, int i, int j) {
        if (i != j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    // 自定义类将当前的board和0的位置绑定，减少循环
    // 重写equals-hashCode是用于visited.contains()判断
    static class Node {
        int[] board;
        int zeroPos;

        public Node(int[][] board) {
            this.board = new int[6];
            for (int i = 0; i < 6; i++) {
                this.board[i] = board[i / 3][i % 3];
                if (this.board[i] == 0) this.zeroPos = i;
            }
        }

        public Node(int[] board, int zeroPos) {
            this.board = board;
            this.zeroPos = zeroPos;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Node)) return false;
            Node node = (Node) o;
            return zeroPos == node.zeroPos && Arrays.equals(board, node.board);
        }

        @Override
        public int hashCode() {
            int result = Objects.hash(zeroPos);
            result = 31 * result + Arrays.hashCode(board);
            return result;
        }
    }
}
```

实现3：其实这才是最原始的思路，通过"上下左右"进行扩散。这里用int[][]实现一遍，我大概是太闲了…
```java
class Solution {
    public int slidingPuzzle(int[][] board) {
        int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int[][] endBoard = {{1, 2, 3}, {4, 5, 0}};
        Node curr = new Node(board);
        if (Arrays.deepEquals(curr.board, endBoard)) return 0;

        Queue<Node> queue = new LinkedList<>();
        queue.offer(curr);
        HashSet<Node> visited = new HashSet<>();
        visited.add(curr);

        int count = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                curr = queue.poll();
                int[] currZeroPos = curr.zeroPos;
                for (int[] d : dir) { // 上下左右进行扩散
                    int i = currZeroPos[0] + d[0], j = currZeroPos[1] + d[1];
                    if (i < 0 || i >= 2 || j < 0 || j >= 3) continue;
                    int[] nextZeroPos = {i, j};
                    int[][] nextBoard = copy(curr.board);
                    swap(nextBoard, currZeroPos, nextZeroPos);

                    if (Arrays.deepEquals(nextBoard, endBoard)) return count + 1;
                    Node next = new Node(nextBoard, nextZeroPos);
                    if (visited.contains(next)) continue;
                    queue.offer(next);
                    visited.add(next);
                }
            }
            count++;
        }
        return -1;
    }

    int[][] copy(int[][] board) {
        int[][] result = new int[2][3];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                result[i][j] = board[i][j];
        return result;
    }

    void swap(int[][] arr, int[] i, int[] j) {
        int tmp = arr[i[0]][i[1]];
        arr[i[0]][i[1]] = arr[j[0]][j[1]];
        arr[j[0]][j[1]] = tmp;
    }

    // 逻辑同上，注意对于二维数组需要deepEquals、deepHashCode函数
    static class Node implements Cloneable {
        int[][] board;
        int[] zeroPos;

        public Node(int[][] board) {
            this.board = board;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        this.zeroPos = new int[]{i, j};
                        return;
                    }
                }
            }
        }

        public Node(int[][] board, int[] zeroPos) {
            this.board = board;
            this.zeroPos = zeroPos;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Node)) return false;
            Node node = (Node) o;
            return Arrays.equals(zeroPos, node.zeroPos) && Arrays.deepEquals(board, node.board);
        }

        @Override
        public int hashCode() {
            int result = Arrays.hashCode(zeroPos);
            result = 31 * result + Arrays.deepHashCode(board);
            return result;
        }
    }
}
```

解法二：终极大招 —— 【A*】
通过估价函数来确定优先级（在这道题中并不快，可能是我实现的有问题，不过官方解更慢…）
```java
class Solution {
    public int slidingPuzzle(int[][] board) {
        int[][] dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        int[] endBoard = {1, 2, 3, 4, 5, 0};
        Node curr = new Node(board);
        if (Arrays.equals(curr.board, endBoard)) return 0;

        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.offer(curr);
        HashSet<Node> visited = new HashSet<>();
        visited.add(curr);

        while (!queue.isEmpty()) {
            curr = queue.poll();
            for (int nextZeroPos : dir[curr.zeroPos]) {
                int[] nextBoard = Arrays.copyOf(curr.board, 6);
                swap(nextBoard, curr.zeroPos, nextZeroPos);
                if (Arrays.equals(nextBoard, endBoard)) return curr.count + 1;
                Node next = new Node(nextBoard, nextZeroPos, curr.count + 1);
                if (visited.contains(next)) continue;
                queue.offer(next);
                visited.add(next);
            }
        }
        return -1;
    }

    void swap(int[] arr, int i, int j) {
        if (i != j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    static class Node implements Comparable<Node> {
        int[] board;
        int zeroPos;
        int count; // g(n)
        int distance; // h(n)
        int f; // f(n) = g(n) + h(n)

        public Node(int[][] board) {
            this.board = new int[6];
            for (int i = 0; i < 6; i++) {
                this.board[i] = board[i / 3][i % 3];
                if (this.board[i] == 0) this.zeroPos = i;
            }
            this.count = 0;
            this.distance = calcDistance();
            this.f = this.count + this.distance;
        }

        public Node(int[] board, int zeroPos, int count) {
            this.board = board;
            this.zeroPos = zeroPos;
            this.count = count;
            this.distance = calcDistance();
            this.f = this.count + this.distance;
        }

        private int calcDistance() {
            int distance = 0;
            for (int i = 0; i < 6; i++) {
                int v = board[i] - 1;
                // 曼哈顿距离，计算每个坐标的当前位置与最终位置的距离
                distance += Math.abs(v / 3 - i / 3) + Math.abs(v % 3 - i % 3);
            }
            return distance;
        }

        @Override
        public int compareTo(Node node) {
            return this.f - node.f;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Node)) return false;
            Node node = (Node) o;
            return zeroPos == node.zeroPos && Arrays.equals(board, node.board);
        }

        @Override
        public int hashCode() {
            int result = Objects.hash(zeroPos);
            result = 31 * result + Arrays.hashCode(board);
            return result;
        }
    }
}
```
