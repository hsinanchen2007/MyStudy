### 解题思路
此处撰写解题思路

### 代码

```java
class MedianFinder {
    private PriorityQueue<Integer> smallRootHeap;

    private PriorityQueue<Integer> bigRootHeap;

    /** initialize your data structure here. */
    public MedianFinder() {
        smallRootHeap = new PriorityQueue<>();
        bigRootHeap = new PriorityQueue<>((o1, o2) -> {
            if (o1 > o2) {
                return -1;
            }
            return 1;
        });
    }

    public void addNum(int num) {
        if (smallRootHeap.isEmpty() || num > smallRootHeap.peek()) {
            smallRootHeap.add(num);
        } else {
            bigRootHeap.add(num);
        }
        balance(smallRootHeap, bigRootHeap);
    }

    private void balance(PriorityQueue<Integer> q1, PriorityQueue<Integer> q2) {
        if (q1.size() - q2.size() >= 2) {
            q2.add(q1.poll());
        } else if (q2.size() - q1.size() >= 2) {
            q1.add(q2.poll());
        }
    }

    public double findMedian() {
        if (((smallRootHeap.size() + bigRootHeap.size()) & 1) == 1) {
            if (smallRootHeap.size() > bigRootHeap.size()) {
                return (double)smallRootHeap.peek();
            } else {
                return (double)bigRootHeap.peek();
            }
        } else {
            return ((double)smallRootHeap.peek() + (double)bigRootHeap.peek()) / 2.0;
        }
    }

}
```