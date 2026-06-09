```
//单队列实现
/*复杂度：入栈O(1)，pop和top为O(n) 或者 入栈O(n)，pop和top为O(1)
 *取决于头size个值放到尾部的代码段放在哪
 */
class MyStack {

    Queue<Integer> queue;

    public MyStack() {
        queue = new LinkedList<>();
    }

    public void push(int x) {
        queue.add(x);
    }

    public int pop() {
        return shift();
    }

    private int shift() {
        int size = queue.size();
        while (size-- > 1) {
            // 精髓：暂存大小,再将头size个值放到尾部
            queue.add(queue.poll());
        }
        return queue.poll();
    }

    public int top() {
        int peek = shift();
        // 放回队列
        queue.add(peek);
        return peek;
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}
```
