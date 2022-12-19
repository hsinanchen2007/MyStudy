使用两个优先队列。

```java
class MedianFinder {

    PriorityQueue<Integer> up = new PriorityQueue();
    PriorityQueue<Integer> down = new PriorityQueue(Collections.reverseOrder());

    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {

        if (up.size() == 0) {
            up.add(num);
            return;
        }

        if (down.size() == 0) {
            if (num < up.peek()) {
                down.add(num);
            } else {
                up.add(num);
                down.add(up.poll());
            }
            return;
        }

        if (up.size() <= down.size()) {
            // insert to up
            if (num > down.peek()) {
                // 下大下堆的顶，直接推到上堆
                up.add(num);
            } else {
                down.add(num);
                up.add(down.poll());
            }
        } else {
            // insert to down
            if (num < up.peek()) {
                down.add(num);
            } else {
                up.add(num);
                down.add(up.poll());
            }
        }
    }
    
    public double findMedian() {
        if (up.size() == down.size()) {
            Integer u = up.peek();
            Integer d = down.peek();
            return (u + d) / 2.0;
        } else {
            return up.peek();
        }
    }

    public static void main(String[] args) {
        MedianFinder m = new MedianFinder();
        m.addNum(1);
        m.addNum(2);
        System.err.println(m.findMedian());
        m.addNum(3);
        System.err.println(m.findMedian());
    }
}

```
