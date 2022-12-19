1、使用大顶堆
2、循环排序
3、双栈实现大顶堆

```
public class heap {

    public static void main(String[] args) {
        int[] input = {2,7,4,1,8,1};
        System.out.println(lastStoneWeight3(input));
    }

    /**
     * java大顶堆
     * 执行用时 :43 ms, 在所有 Java 提交中击败了10.83%的用户
     * 内存消耗 :34.4 MB, 在所有 Java 提交中击败了100.00%的用户
     */
    public static int lastStoneWeight3(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1, i2) -> i2 - i1);
        for (int x: stones) {
            pq.offer(x);
        }
        while (pq.size() > 1) {
            int remaining = pq.poll() - pq.poll();
            if (remaining != 0) {
                pq.offer(remaining);
            }
        }
        return pq.isEmpty() ? 0 : pq.poll();
    }
    /**
     * 循环排序
     * 执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
     * 内存消耗 :34.2 MB, 在所有 Java 提交中击败了100.00%的用户
     */
    public static int lastStoneWeight2(int[] stones) {
        Arrays.sort(stones);
        while (stones.length > 1 && stones[stones.length - 2] > 0) {
            stones[stones.length - 1] = stones[stones.length - 1] - stones[stones.length - 2];
            stones[stones.length - 2] = 0;
            Arrays.sort(stones);
        }
        return stones[stones.length-1];
    }
    /**
     * 双栈实现最大堆
     * 执行用时 : 7 ms, 在所有 Java 提交中击败了15.14%的用户
     * 内存消耗 :34 MB, 在所有 Java 提交中击败了100.00%的用户
     */
    public static int lastStoneWeight(int[] stones) {
        Stack<Integer> max = new Stack();
        Stack<Integer> temp = new Stack<>();
        for (int x: stones) {
            while (!max.isEmpty() && max.peek() > x) {
                temp.push(max.pop());
            }
            max.push(x);
            while (!temp.isEmpty()) {
                max.push(temp.pop());
            }
        }
        while (max.size() > 1) {
            int remaining = max.pop() - max.pop();
            if (remaining != 0) {
                while (!max.isEmpty() && max.peek() > remaining) {
                    temp.push(max.pop());
                }
                max.push(remaining);
                while (!temp.isEmpty()) {
                    max.push(temp.pop());
                }
            }
        }
        return max.isEmpty() ? 0 : max.pop();
    }
}
```
