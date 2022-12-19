```
public class MaxQueue {

    Queue<Integer> queue;
    Deque<Integer> dequeMax;

    public MaxQueue() {
        queue = new LinkedList<>();
        dequeMax = new LinkedList<>();
    }

    public int max_value() {
        if (dequeMax.isEmpty()) return -1;
        return dequeMax.peek();
    }

    public void push_back(int value) {
        queue.add(value);
        while (!dequeMax.isEmpty() && value > dequeMax.peekLast()){
            dequeMax.removeLast();
        }
        dequeMax.add(value);
    }

    public int pop_front() {
        if (queue.isEmpty()) return -1;
        int ans = queue.remove();
        if (ans == dequeMax.peek()){
            dequeMax.remove();
        }
        return ans;
    }
}
```
