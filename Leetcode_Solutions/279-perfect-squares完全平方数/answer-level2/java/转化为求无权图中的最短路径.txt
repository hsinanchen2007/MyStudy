
![20191019194052110.png](https://pic.leetcode-cn.com/0b5aa6de4a34a48577b5fb2a01e63e18383297f801338697bb6581b64b8916d5-20191019194052110.png)
***
![20191019194347569.png](https://pic.leetcode-cn.com/9068a064656a6bc36694e5c95b83a0d25f8e7bf1175a291ba8dcf983a18a0b3b-20191019194347569.png)

***
![20191019195005295.png](https://pic.leetcode-cn.com/ed8d043c2fc01081f937627eadf25f09e30ab5062e769003691d617451eb5df6-20191019195005295.png)
***
```
// 279. Perfect Squares
// https://leetcode-cn.com/problems/perfect-squares/description/
// 该方法会导致 Time Limit Exceeded 或者 Memory Limit Exceeded
// 时间复杂度: O(2^n)
// 空间复杂度: O(2^n)
import javafx.util.Pair;
import javafx.util.Pair;
public class Solution {
    public int numSquares(int n) {
        //Pair<具体是第几个数字, 经历了几段路径走到了这个数字>
        LinkedList<Pair<Integer, Integer>> queue = new LinkedList<>();
        queue.addLast(new Pair<>(n, 0));
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> front = queue.removeFirst();
            int num = front.getKey();
            int step = front.getValue();
            if (num == 0) {
                return step;
            }
            //重复推入了很多节点
            for (int i = 1; num - i * i >= 0; i++) {
                queue.addLast(new Pair(num - i * i, step + 1));
            }
        }
        throw new IllegalStateException("No Solution.");
    }
    //public static void main(String[] args) {
    //    System.out.println((new Solution()).numSquares(12));
    //    System.out.println((new Solution()).numSquares(13));
    //}
}
```
由于从不同的节点，都可以到同一个节点，每个节点只需要入队一次即可（其他的都是重复的过程）
```
// 279. Perfect Squares
// https://leetcode-cn.com/problems/perfect-squares/description/
// 使用visited数组,记录每一个入队元素
//
// 时间复杂度: O(n)
// 空间复杂度: O(n)
import javafx.util.Pair;
public class Solution {
    public int numSquares(int n) {
        LinkedList<Pair<Integer, Integer>> queue = new LinkedList<>();
        queue.addLast(new Pair<>(n, 0));
        boolean[] visited = new boolean[n + 1];
        visited[n] = true;
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> front = queue.removeFirst();
            int num = front.getKey();
            int step = front.getValue();
            if (num == 0) {
                return step;
            }
            for (int i = 1; num - i * i >= 0; i++) {
                if (!visited[num - i * i]) {
                    queue.addLast(new Pair(num - i * i, step + 1));
                    visited[num - i * i] = true;
                }
            }
        }
        throw new IllegalStateException("No Solution.");
    }
    //public static void main(String[] args) {
    //    System.out.println((new Solution()).numSquares(12));
    //    System.out.println((new Solution()).numSquares(13));
    //}
}
```
进一步优化
```
// 279. Perfect Squares
// https://leetcode-cn.com/problems/perfect-squares/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)
import javafx.util.Pair;
public class Solution {
    public int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        LinkedList<Pair<Integer, Integer>> queue = new LinkedList<>();
        queue.addLast(new Pair<>(n, 0));
        boolean[] visited = new boolean[n + 1];
        visited[n] = true;
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> front = queue.removeFirst();
            int num = front.getKey();
            int step = front.getValue();
            if (num == 0) {
                return step;
            }
            for (int i = 1; num - i * i >= 0; i++) {
                int a = num - i * i;
                if (!visited[a]) {
                    if (a == 0) {
                        return step + 1;
                    }
                    queue.addLast(new Pair(num - i * i, step + 1));
                    visited[num - i * i] = true;
                }
            }
        }
        throw new IllegalStateException("No Solution.");
    }
    //public static void main(String[] args) {
    //    System.out.println((new Solution()).numSquares(12));
    //    System.out.println((new Solution()).numSquares(13));
    //}
}
```
详细说明：[https://blog.csdn.net/qq_40794973/article/details/102642113]()
