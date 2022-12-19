1. deque存储数据
2. 数组初始化
int[][] v = {{1, 2}, {3}, {4}};
3. 打印调试日志System.err.println
IDEA中的sufix为serr，err打印提交的时候可以不用删

```java
class Vector2D {

    private Deque<Integer> arr = new LinkedList<>();

    public Vector2D(int[][] v) {
        for (int[] row : v) {
            for (int col : row) {
                this.arr.add(col);
            }
        }
    }

    public int next() {
        Integer poll = arr.poll();
        System.err.println(poll);
        return poll;
    }

    public boolean hasNext() {
        boolean hasNext = !arr.isEmpty();
        System.err.println(hasNext);
        return hasNext;
    }

    public static void main(String[] args) {
        int[][] v = {{1, 2}, {3}, {4}};
        Vector2D iterator = new Vector2D(v);

        iterator.next(); // 返回 1
        iterator.next(); // 返回 2
        iterator.next(); // 返回 3
        iterator.hasNext(); // 返回 true
        iterator.hasNext(); // 返回 true
        iterator.next(); // 返回 4
        iterator.hasNext(); // 返回 false
    }
}
```
